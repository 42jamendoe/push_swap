/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:05:56 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:59 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/checker.h"
#include "../includes/libft.h"

void	ft_do_instr(t_node **stack_a, t_node **stack_b, t_action *inst)
{
	if (inst->mv[0] == 's' && inst->mv[1] == 'a' && inst->mv[2] == '\n')
		ft_swap(&(*stack_a), NO_WRITE);
	else if (inst->mv[0] == 's' && inst->mv[1] == 'b' && inst->mv[2] == '\n')
		ft_swap(&(*stack_b), NO_WRITE);
	else if (inst->mv[0] == 's' && inst->mv[1] == 's' && inst->mv[2] == '\n')
		ft_both_swap(&(*stack_a), &(*stack_b), NO_WRITE);
	else if (inst->mv[0] == 'p' && inst->mv[1] == 'a' && inst->mv[2] == '\n')
		ft_push(&(*stack_b), &(*stack_a), NO_WRITE);
	else if (inst->mv[0] == 'p' && inst->mv[1] == 'b' && inst->mv[2] == '\n')
		ft_push(&(*stack_a), &(*stack_b), NO_WRITE);
	else
		ft_do_instr_rot(&(*stack_a), &(*stack_b), inst);
}

void	ft_do_instr_rot(t_node **stack_a, t_node **stack_b, t_action *inst)
{
	if (inst->mv[0] == 'r' && inst->mv[1] == 'a' && inst->mv[2] == '\n')
		ft_rotate(&(*stack_a), NO_WRITE);
	else if (inst->mv[0] == 'r' && inst->mv[1] == 'b' && inst->mv[2] == '\n')
		ft_rotate(&(*stack_b), NO_WRITE);
	else if (inst->mv[0] == 'r' && inst->mv[1] == 'r' && inst->mv[2] == '\n')
		ft_both_rotate(&(*stack_a), &(*stack_b), NO_WRITE);
	else if (inst->mv[0] == 'r' && inst->mv[1] == 'r' && inst->mv[2] == 'a' \
	&& inst->mv[3] == '\n')
		ft_reverse_rotate(&(*stack_a), NO_WRITE);
	else if (inst->mv[0] == 'r' && inst->mv[1] == 'r' && inst->mv[2] == 'b' \
	&& inst->mv[3] == '\n')
		ft_reverse_rotate(&(*stack_b), NO_WRITE);
	else if (inst->mv[0] == 'r' && inst->mv[1] == 'r' && inst->mv[2] == 'r' \
	&& inst->mv[3] == '\n')
		ft_both_reverse_rotate(&(*stack_a), &(*stack_b), NO_WRITE);
	else
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

t_action	*ft_create_action_list(t_action **evaluation, char **inst)
{
	t_action	*tmp_ptr;
	t_action	*tmp;

	tmp = (t_action *) malloc (sizeof(t_action));
	if (!tmp)
		return (NULL);
	tmp->mv = (*inst);
	tmp->next = NULL;
	if (!(*evaluation))
		(*evaluation) = tmp;
	else
	{
		tmp_ptr = (*evaluation);
		while (tmp_ptr->next)
			tmp_ptr = tmp_ptr->next;
		tmp_ptr->next = tmp;
	}
	return ((*evaluation));
}

t_action	*ft_get_instructions(void)
{
	char		*inst;
	t_action	*to_do;

	to_do = NULL;
	inst = get_next_line(STDIN_FILENO);
	if (inst)
	{
		while (inst)
		{
			to_do = ft_create_action_list(&to_do, &inst);
			inst = get_next_line(STDIN_FILENO);
		}
	}
	else
	{
		write(STDERR_FILENO, "Error\n", 6);
	}
	return (&(*to_do));
}

void	ft_sort_evaluation(t_node **stack_a, t_node **stack_b)
{
	t_action	*print_moves;
	t_action	*pm_tmp;
	int			tmp_a_st;

	tmp_a_st = ft_count_node_stack((*stack_a));
	print_moves = ft_get_instructions();
	pm_tmp = print_moves;
	while (pm_tmp)
	{
		ft_do_instr(&(*stack_a), &(*stack_b), pm_tmp);
		pm_tmp = pm_tmp->next;
	}
	ft_clean_inst_list(&print_moves);
	if (ft_stack_is_sorted((*stack_a), SORT_ASC) == SORT_YES && \
	tmp_a_st == ft_count_node_stack((*stack_a)))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	if (*stack_a)
		ft_clean_stack_a(&(*stack_a));
	if (*stack_b)
		ft_clean_stack_a(&(*stack_b));
}

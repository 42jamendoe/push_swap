/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:05:56 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:59 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../includes/libft.h"

int	ft_test_duplicates(t_node *stack, int size)
{
	t_node	*tmp;

	tmp = stack;
	tmp = tmp->next;
	size--;
	while (size > 1)
	{
		while (tmp != stack)
		{
			if (stack->number == tmp->number)
				return (DUPLICATES);
			tmp = tmp->next;
		}
		stack = stack->next;
		tmp = stack->next;
		size--;
	}
	return (NO_DUPLICATES);
}

void	ft_test_asc_dup(t_node **stack_a, int size)
{
	int	dupl;

	dupl = ft_test_duplicates((*stack_a), size);
	if (ft_stack_is_sorted((*stack_a), SORT_ASC) == SORT_YES || \
	dupl == DUPLICATES)
	{
		if (dupl == DUPLICATES)
		{
			ft_clean_stack_a(&(*stack_a));
			ft_exit_stderror();
		}
		ft_clean_stack_a(&(*stack_a));
		exit(EXIT_SUCCESS);
	}
}

int	ft_stack_asc_from_min(t_node *stack)
{
	t_node	*tmp;
	int		min_stack;
	int		max_stack;
	int		n;

	tmp = stack;
	n = ft_count_node_stack(stack);
	min_stack = ft_find_point_position(stack, MIN);
	max_stack = ft_find_point_position(stack, MAX);
	while (tmp->rank != min_stack)
		tmp = tmp->next;
	while (n > 1)
	{
		if (tmp->rank < tmp->next->rank)
			tmp = tmp->next;
		else
			return (SORT_NO);
		n--;
	}
	if (tmp->rank == max_stack)
		return (SORT_YES);
	else
		return (SORT_NO);
}

int	ft_stack_is_sorted(t_node *stack, int type_sort)
{
	t_node	*tmp;
	int		tmp_rank;

	tmp = stack;
	tmp_rank = tmp->rank;
	tmp = tmp->next;
	while (tmp != stack)
	{
		if (type_sort == SORT_DES)
		{
			if (tmp_rank < tmp->rank)
				return (SORT_NO);
		}
		else
		{
			if (tmp_rank > tmp->rank)
				return (SORT_NO);
		}
		tmp_rank = tmp->rank;
		tmp = tmp->next;
	}
	return (SORT_YES);
}

int	ft_count_node_stack(t_node *stack)
{
	t_node	*tmp;
	int		i;

	if (!stack)
		ft_exit_stderror();
	tmp = stack;
	tmp = tmp->next;
	i = 1;
	while (tmp != stack)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

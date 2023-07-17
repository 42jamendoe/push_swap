/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:05:56 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:59 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/checker.h"
#include "../includes/libft.h"

void	ft_clean_array(int size, char **array)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(&(*array));
}

void	ft_clean_stack_a(t_node **stack)
{
	int		len;
	t_node	*tmp;

	len = ft_count_node_stack(*stack);
	if (len == 1)
		free((*stack));
	if (len > 1)
	{
		tmp = (*stack)->next;
		while (tmp->next != (*stack))
			tmp = tmp->next;
		tmp = tmp->prev;
		while (tmp != (*stack))
		{
			free(tmp->next);
			tmp = tmp->prev;
		}
		free((*stack)->next);
		free((*stack));
	}
}

void	ft_exit_stderror(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
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

int	ft_test_duplicates(t_node *stack, int size)
{
	t_node	*tmp;

	tmp = stack;
	tmp = tmp->next;
	size--;
	while (size > 0)
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

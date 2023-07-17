/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:05:56 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:59 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/checker.h"

void	ft_both_rotate(t_node **a, t_node **b, char stack_letter)
{
	if ((*a))
	{
		ft_rotate(&(*a), NO_WRITE);
		ft_rotate(&(*b), NO_WRITE);
		if (stack_letter != BOTH_REV && stack_letter != NO_WRITE)
			write(1, "rr\n", 3);
	}
}

void	ft_rotate(t_node **stack, char stack_letter)
{
	if ((*stack))
	{
		(*stack) = (*stack)->next;
		if (stack_letter != BOTH_REV && stack_letter != NO_WRITE)
		{
			write(1, "r", 1);
			write(1, &stack_letter, 1);
			write(1, "\n", 1);
		}
	}
}

void	ft_both_reverse_rotate(t_node **a, t_node **b, char stack_letter)
{
	if ((*a))
	{
		ft_reverse_rotate(&(*a), BOTH_REV);
		ft_reverse_rotate(&(*b), BOTH_REV);
		if (stack_letter != NO_WRITE)
			write(1, "rrr\n", 4);
	}
}

void	ft_reverse_rotate(t_node **stack, char stack_letter)
{
	if ((*stack))
	{
		(*stack) = (*stack)->prev;
		if (stack_letter != BOTH_REV && stack_letter != NO_WRITE)
		{
			write(1, "rr", 2);
			write(1, &stack_letter, 1);
			write(1, "\n", 1);
		}
	}
}

void	ft_test_int(char **str, int size, char *sent)
{
	int	i;
	int	num_int;

	i = 0;
	num_int = INT;
	while (i < size)
	{
		if (ft_str_is_int(str[i]) == NOT_INT)
			num_int = NOT_INT;
		i++;
	}
	i = 0;
	if (num_int == NOT_INT)
	{
		while (i < size)
		{
			free(str[i]);
			i++;
		}
		free(&(*sent));
		free(&(*str));
		ft_exit_stderror();
	}
}

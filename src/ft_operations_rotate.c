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
	if ((*a) && (*b))
	{
		ft_rotate(&(*a), stack_letter);
		ft_rotate(&(*b), stack_letter);
		if (stack_letter == BOTH_REV)
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
	if ((*a) && (*b))
	{
		ft_reverse_rotate(&(*a), stack_letter);
		ft_reverse_rotate(&(*b), stack_letter);
		if (stack_letter == BOTH_REV)
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

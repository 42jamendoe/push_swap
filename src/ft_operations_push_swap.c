/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_push_swap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:05:56 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:59 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/checker.h"

void	ft_both_swap(t_node **stack_a, t_node **stack_b, char stack_letter)
{
	if ((*stack_a) && (*stack_b))
	{
		ft_swap(&(*stack_a), stack_letter);
		ft_swap(&(*stack_b), stack_letter);
		if (stack_letter == BOTH_SWAP)
			write(1, "ss\n", 3);
	}
}

void	ft_swap(t_node **stack, char stack_letter)
{
	int	tmp_nbr;
	int	tmp_rnk;

	if ((*stack))
	{
		if ((*stack)->next)
		{
			tmp_nbr = (*stack)->number;
			tmp_rnk = (*stack)->rank;
			(*stack)->number = (*stack)->next->number;
			(*stack)->rank = (*stack)->next->rank;
			(*stack)->next->number = tmp_nbr;
			(*stack)->next->rank = tmp_rnk;
		}
		if (stack_letter != BOTH_SWAP && stack_letter != NO_WRITE)
		{
			write(1, "s", 1);
			write(1, &stack_letter, 1);
			write(1, "\n", 1);
		}
	}
}

void	ft_push_with_stack(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = (*stack_a);
	if ((*stack_b))
	{
		(*stack_a) = tmp->next;
		(*stack_a)->prev = tmp->prev;
		(*stack_a)->prev->next = tmp->next;
		tmp->prev = (*stack_b)->prev;
		tmp->next = (*stack_b);
		(*stack_b)->prev->next = tmp;
		(*stack_b)->prev = tmp;
		(*stack_b) = tmp;
	}
	else
	{
		(*stack_a) = tmp->next;
		(*stack_a)->prev = tmp->prev;
		(*stack_a)->prev->next = tmp->next;
		(*stack_b) = tmp;
		(*stack_b)->prev = tmp;
		(*stack_b)->next = tmp;
	}
}

void	ft_write_push(char stack_letter)
{
	if (stack_letter != NO_WRITE)
	{
		write(1, "p", 1);
		write(1, &stack_letter, 1);
		write(1, "\n", 1);
	}
}

void	ft_push(t_node **stack_a, t_node **stack_b, char stack_letter)
{
	t_node	*tmp;

	if (*stack_a)
	{
		tmp = (*stack_a);
		if (ft_count_node_stack((*stack_a)) == 1)
		{
			(*stack_a) = NULL;
			tmp->prev = (*stack_b)->prev;
			tmp->next = (*stack_b);
			(*stack_b)->prev->next = tmp;
			(*stack_b)->prev = tmp;
			(*stack_b) = tmp;
		}
		else
		{
			ft_push_with_stack(&(*stack_a), &(*stack_b));
		}
		ft_write_push(stack_letter);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:05:56 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:59 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	ft_rotate_final_position(t_node **stack_a)
{
	int	current;
	int	max_a;

	current = (*stack_a)->rank;
	max_a = ft_find_point_position((*stack_a), MAX);
	if (current < ((max_a + 1) / 2))
	{
		while ((*stack_a)->rank != MIN)
			ft_reverse_rotate(&(*stack_a), STACK_A);
	}
	else
	{
		while ((*stack_a)->rank != MIN)
			ft_rotate(&(*stack_a), STACK_A);
	}
}

int	ft_get_optimized_position_stack_a(t_node *stack_a, t_node *stack_b)
{
	int	count;

	count = 0;
	if (stack_b->rank > stack_a->rank)
		count++;
	if (stack_b->rank > stack_a->prev->rank)
		count++;
	if (stack_b->rank > stack_a->next->rank)
		count++;
	return (count);
}

int	ft_get_current_position_stack_a(t_node *stack_a)
{
	int	max_a;

	max_a = ft_find_point_position(stack_a, MAX);
	if (stack_a->prev->rank == max_a)
		return (2);
	else if (stack_a->next->rank == max_a)
		return (1);
	else
		return (0);
}

void	ft_optimize_rotate_stack_a(t_node **stack_a, t_node **stack_b)
{
	int	tmp;
	int	current;
	int	best;

	current = ft_get_current_position_stack_a((*stack_a));
	best = ft_get_optimized_position_stack_a((*stack_a), (*stack_b));
	tmp = ((current + best) % MIN_STACK);
	if (tmp == RANK_0)
		ft_rotate(&(*stack_a), STACK_A);
	if (tmp == RANK_1)
		ft_reverse_rotate(&(*stack_a), STACK_A);
	ft_clean_stack_b(&(*stack_a), &(*stack_b));
	ft_rotate_final_position(&(*stack_a));
}

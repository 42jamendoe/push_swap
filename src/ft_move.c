/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:05:56 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:59 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../includes/libft.h"

t_move	ft_find_best_move(t_node *a, t_node *b, int move_a, t_move best)
{
	t_move	tmp_best;
	t_move	tmp_move;
	t_node	*tmp_node;
	int		len_a;

	tmp_node = a;
	len_a = ft_count_node_stack(a);
	tmp_best = best;
	tmp_move = ft_min_rotation(b, tmp_node->rank, move_a, len_a);
	if (tmp_move.total < best.total)
		tmp_best = tmp_move;
	return (tmp_best);
}

void	ft_one_stack_move(t_node **a, t_node **b, t_move best)
{
	while (best.a < 0)
	{
		ft_reverse_rotate(&(*a), STACK_A);
		best.a++;
	}
	while (best.a > 0)
	{
		ft_rotate(&(*a), STACK_A);
		best.a--;
	}
	while (best.b < 0)
	{
		ft_reverse_rotate(&(*b), STACK_B);
		best.b++;
	}
	while (best.b > 0)
	{
		ft_rotate(&(*b), STACK_B);
		best.b--;
	}
}

t_move	ft_two_stack_move(t_node **a, t_node **b, t_move best, int signal)
{
	t_move	tmp;

	tmp = best;
	tmp.a = best.a * signal;
	tmp.b = best.b * signal;
	tmp.total = best.total;
	while (tmp.a > 0 && tmp.b > 0)
	{
		if (signal == NEGATIVE)
			ft_both_reverse_rotate(&(*a), &(*b), BOTH_REV);
		else
			ft_both_rotate(&(*a), &(*b), BOTH_REV);
		tmp.a--;
		tmp.b--;
		tmp.total--;
	}
	tmp.a *= signal;
	tmp.b *= signal;
	return (tmp);
}

void	ft_push_a_to_b(t_node **stack_a, t_node **stack_b, t_move best)
{
	int	signal;

	signal = POSITIVE;
	if (best.total == 0)
		ft_push(&(*stack_a), &(*stack_b), STACK_B);
	else
	{
		if ((best.a > 0 && best.b > 0) || (best.a < 0 && best.b < 0))
		{
			if (best.a < 0 && best.b < 0)
				signal = NEGATIVE;
			best = ft_two_stack_move(&(*stack_a), &(*stack_b), best, signal);
		}
		if (best.total > 0)
			ft_one_stack_move(&(*stack_a), &(*stack_b), best);
		ft_push(&(*stack_a), &(*stack_b), STACK_B);
	}
}

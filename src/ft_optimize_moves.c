/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:05:56 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:59 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_range	*ft_create_range(t_node *stack)
{
	t_range	*tmp;
	int		min;
	int		max;

	min = ft_find_point_position(stack, MIN);
	max = ft_find_point_position(stack, MAX);
	tmp = (t_range *) malloc (sizeof(t_range));
	if (!tmp)
		ft_exit_stderror();
	tmp->min_rg = min;
	tmp->max_rg = max;
	return (tmp);
}

t_move	ft_min_rotation_b_rev_rot(t_node *stack_b, int search, int move_a)
{
	t_move	small;
	t_range	*b;

	b = ft_create_range(stack_b);
	small.a = -(move_a);
	small.b = 0;
	if ((search < b->min_rg || search > b->max_rg) || \
	(search < stack_b->rank && search < stack_b->prev->rank))
	{
		while (stack_b->rank != b->max_rg)
		{
			stack_b = stack_b->prev;
			small.b--;
		}
	}
	while (search > stack_b->prev->rank && search < b->max_rg \
	&& search > b->min_rg)
	{
		stack_b = stack_b->prev;
		small.b--;
	}
	small.total = ft_max_from_ints(-small.a, -small.b);
	free(b);
	return (small);
}

t_move	ft_min_rotation_b_rot(t_node *stack_b, int search, int move_a)
{
	t_move	small;
	t_range	*b;

	b = ft_create_range(stack_b);
	small.a = move_a;
	small.b = 0;
	if ((search < b->min_rg || search > b->max_rg) || \
	(search > stack_b->rank && search > stack_b->prev->rank))
	{
		while (stack_b->rank != b->max_rg)
		{
			stack_b = stack_b->next;
			small.b++;
		}
	}
	while (search < stack_b->rank && search < b->max_rg \
	&& search > b->min_rg)
	{
		stack_b = stack_b->next;
		small.b++;
	}
	small.total = ft_max_from_ints(small.a, small.b);
	free(b);
	return (small);
}

t_move	ft_min_rotation(t_node *stack, int tmp_rank, int move_a, int len_a)
{
	t_move	tmp_best;
	t_move	tmp_best_rev;

	tmp_best = ft_min_rotation_b_rot(stack, tmp_rank, move_a);
	if (((len_a - move_a) % len_a) + tmp_best.b < tmp_best.total)
	{
		tmp_best.a = -((len_a - move_a) % len_a);
		tmp_best.total = ((len_a - move_a) % len_a) + tmp_best.b;
	}
	tmp_best_rev = ft_min_rotation_b_rev_rot(stack, tmp_rank, \
	(len_a - move_a) % len_a);
	if (tmp_best_rev.total < tmp_best.total)
		tmp_best = tmp_best_rev;
	if ((move_a - tmp_best_rev.b) < tmp_best.total)
	{
		tmp_best.a = move_a;
		tmp_best.b = tmp_best_rev.b;
		tmp_best.total = move_a - tmp_best_rev.b;
	}
	return (tmp_best);
}

void	ft_optimize_moves(t_node **stack_a, t_node **stack_b)
{
	t_move	best;
	t_move	tmp_ptr;
	t_node	*tmp;
	int		move_a;
	int		len_a;

	tmp = (*stack_a);
	len_a = ft_count_node_stack(tmp);
	while (len_a > 3)
	{
		move_a = 0;
		tmp_ptr = ft_min_rotation_b_rot((*stack_b), (*stack_a)->rank, move_a);
		while (move_a < len_a)
		{
			best = ft_find_best_move(tmp, (*stack_b), move_a, tmp_ptr);
			tmp_ptr = best;
			tmp = tmp->next;
			move_a++;
		}
		ft_push_a_to_b(&(*stack_a), &(*stack_b), best);
		tmp_ptr = best;
		tmp = (*stack_a);
		len_a = ft_count_node_stack(tmp);
	}
}

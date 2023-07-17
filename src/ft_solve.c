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

void	ft_init_stack_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = (*stack_a);
	(*stack_a) = tmp->next;
	(*stack_a)->prev = tmp->prev;
	(*stack_a)->prev->next = tmp->next;
	(*stack_b) = tmp;
	(*stack_b)->prev = tmp;
	(*stack_b)->next = tmp;
	write(1, "pb\n", 3);
}

void	ft_start_stack_b(t_node **stack_a)
{
	int		stack_a_len;
	t_node	*stack_b;

	stack_a_len = ft_count_node_stack((*stack_a));
	if (stack_a_len == TWO_ELM)
		ft_swap(&(*stack_a), STACK_A);
	else if (stack_a_len == MIN_STACK)
		ft_solve_three_a(&(*stack_a));
	else if (stack_a_len > MIN_STACK && stack_a_len <= MIN_STACKB)
		ft_sort_small_stack_a(&(*stack_a));
	else if (stack_a_len > MIN_STACKB)
	{
		stack_b = ft_solve_three_b(&(*stack_a));
		ft_optimize_moves(&(*stack_a), &stack_b);
		if (ft_stack_asc_from_min((*stack_a)) == SORT_NO)
			ft_swap(&(*stack_a), STACK_A);
		ft_optimize_rotate_stack_a(&(*stack_a), &stack_b);
	}
	else
	{
		ft_clean_stack_a(&(*stack_a));
		exit(EXIT_SUCCESS);
	}
}

t_node	*ft_solve_three_b(t_node **a)
{
	t_node	*b;

	ft_init_stack_b(&(*a), &b);
	if (b->rank > (*a)->rank && b->rank > (*a)->next->rank)
	{
		ft_push(&(*a), &b, STACK_B);
		ft_swap(&b, STACK_B);
		ft_push(&(*a), &b, STACK_B);
		if (b->rank > b->next->next->rank)
			ft_swap(&b, STACK_B);
	}
	else
	{
		if ((*a)->rank > (*a)->next->rank)
			ft_swap(&(*a), STACK_A);
		ft_push(&(*a), &b, STACK_B);
		if (b->rank < b->next->rank)
			ft_swap(&b, STACK_B);
		ft_push(&(*a), &b, STACK_B);
	}
	return (b);
}

void	ft_sort_small_stack_a(t_node **stack_a)
{
	t_node	*stack_b;
	int		stack_a_len;

	stack_a_len = ft_count_node_stack((*stack_a));
	ft_init_stack_b(&(*stack_a), &stack_b);
	stack_a_len--;
	if (stack_a_len > MIN_STACK)
	{
		ft_push(&(*stack_a), &stack_b, STACK_B);
		if (stack_b->rank < stack_b->next->rank && \
		ft_stack_asc_from_min((*stack_a)) == SORT_NO)
			ft_both_swap(&(*stack_a), &stack_b, BOTH_SWAP);
		else if (ft_stack_asc_from_min((*stack_a)) == SORT_NO)
			ft_swap(&(*stack_a), STACK_A);
		else if (stack_b->rank < stack_b->next->rank)
			ft_swap(&stack_b, STACK_B);
	}
	else
		ft_solve_three_a(&(*stack_a));
	ft_optimize_rotate_stack_a(&(*stack_a), &stack_b);
}

void	ft_solve_three_a(t_node **a)
{
	if ((*a)->rank > (*a)->next->rank && (*a)->rank > (*a)->next->next->rank)
	{
		ft_rotate(&(*a), STACK_A);
		if ((*a)->rank > (*a)->next->rank)
			ft_swap(&(*a), STACK_A);
	}
	else if ((*a)->rank < (*a)->next->rank && \
	(*a)->rank < (*a)->next->next->rank)
	{
		if ((*a)->next->rank > (*a)->next->next->rank)
		{
			ft_reverse_rotate(&(*a), STACK_A);
			ft_swap(&(*a), STACK_A);
		}
	}
	else
	{
		if ((*a)->next->rank > (*a)->next->next->rank)
			ft_reverse_rotate(&(*a), STACK_A);
		else
			ft_swap(&(*a), STACK_A);
	}
}

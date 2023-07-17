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
#include "../includes/push_swap.h"
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
		free(&(*stack));
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

void	ft_clean_stack_b(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	max_a;
	int	max_b;

	i = ft_count_node_stack((*stack_b));
	max_a = ft_find_point_position((*stack_a), MAX);
	max_b = ft_find_point_position((*stack_b), MAX);
	while (i > 0)
	{
		if (max_b > max_a)
			max_a = max_b;
		if ((*stack_a)->prev->rank + 1 == (*stack_a)->rank)
			ft_reverse_rotate(&(*stack_a), STACK_A);
		else if ((*stack_a)->prev->rank == max_a && (*stack_a)->rank == MIN)
			ft_reverse_rotate(&(*stack_a), STACK_A);
		else
		{
			ft_push(&(*stack_b), &(*stack_a), STACK_A);
			i--;
		}
	}
}

void	ft_exit_stderror(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

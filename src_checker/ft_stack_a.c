/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:05:56 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:59 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/checker.h"
#include "../includes/libft.h"

int	ft_node_position(t_node **stack, t_node *current, int size_stack)
{
	t_node	*tmp;
	int		node;
	int		position;

	node = 0;
	position = 0;
	tmp = (*stack);
	while (node < size_stack)
	{
		if (tmp->number < current->number)
			position++;
		tmp = tmp->next;
		node++;
	}
	return (position);
}

void	ft_create_rank(t_node **stack)
{
	t_node	*current;
	int		size_stack;
	int		node;

	current = (*stack);
	size_stack = ft_count_node_stack(current);
	node = 0;
	while (node < size_stack)
	{
		current->rank = ft_node_position(&(*stack), current, size_stack);
		current = current->next;
		node++;
	}
}

t_node	*ft_make_stack(t_node *stack, t_node *number)
{
	if (stack == NULL)
		stack = number;
	else
	{
		number->prev = stack->prev;
		number->next = stack;
		stack->prev->next = number;
		stack->prev = number;
	}
	return (stack);
}

t_node	*ft_create_node_stack(char *arg)
{
	t_node	*node;

	node = (t_node *) malloc (sizeof(t_node));
	if (!node)
		return (NULL);
	node->number = ft_atoi(arg);
	node->prev = node;
	node->next = node;
	return (node);
}

t_node	*ft_create_stack(int size, char **array)
{
	int		i;
	t_node	*tmp;
	t_node	*stack_a;

	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		tmp = ft_create_node_stack(array[i]);
		stack_a = ft_make_stack(&(*stack_a), &(*tmp));
		i++;
	}
	ft_clean_array(size, &(*array));
	return (&(*stack_a));
}

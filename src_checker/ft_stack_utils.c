/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:05:56 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:59 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/checker.h"
#include "../includes/libft.h"

int	ft_stack_is_sorted(t_node *stack, int type_sort)
{
	t_node	*tmp;
	int		tmp_rank;

	if (!stack)
		return (SORT_NO);
	tmp = stack;
	tmp_rank = tmp->rank;
	tmp = tmp->next;
	while (tmp != stack)
	{
		if (type_sort == SORT_DES)
		{
			if (tmp_rank < tmp->rank)
				return (SORT_NO);
		}
		else
		{
			if (tmp_rank > tmp->rank)
				return (SORT_NO);
		}
		tmp_rank = tmp->rank;
		tmp = tmp->next;
	}
	return (SORT_YES);
}

int	ft_count_node_stack(t_node *stack)
{
	t_node	*tmp;
	int		i;

	if (!stack)
		ft_exit_stderror();
	tmp = stack;
	tmp = tmp->next;
	i = 1;
	while (tmp != stack)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_test_str_int(char *nptr, int i, int len, char *max_min)
{
	int	flag;
	int	signal_i;

	signal_i = i;
	flag = 0;
	while (i < len)
	{
		if (ft_isdigit(nptr[i]) != 0)
		{
			if (len + signal_i > 9 && flag == 0)
			{
				if (nptr[i] > max_min[i])
					return (NOT_INT);
				if (nptr[i] < max_min[i])
					flag = 1;
			}
		}
		else
			return (NOT_INT);
		i++;
	}
	return (INT);
}

int	ft_str_is_int(char *nptr)
{
	int		len;
	int		i;
	char	*max_min;
	int		result;

	len = ft_strlen(nptr);
	i = 0;
	if (len > 11 || (len == 11 && nptr[0] != '-'))
		return (NOT_INT);
	if (nptr[0] == '-')
	{
		max_min = MIN_POS;
		i++;
	}
	else
		max_min = MAX_POS;
	result = ft_test_str_int(nptr, i, len, max_min);
	return (result);
}

void	ft_clean_inst_list(t_action **list)
{
	t_action	*next;

	while (*list)
	{
		next = (*list)->next;
		free((*list)->mv);
		free((*list));
		(*list) = next;
	}
}

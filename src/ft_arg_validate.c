/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:05:56 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:05:59 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../includes/libft.h"

int	ft_find_point_position(t_node *stack, int point)
{
	t_node	*tmp;
	int		ranking;

	tmp = stack;
	ranking = tmp->rank;
	if (stack == stack->next)
		return (ranking);
	tmp = tmp->next;
	while (tmp != stack)
	{
		if (point == MIN)
		{
			if (tmp->rank < ranking)
				ranking = tmp->rank;
		}
		if (point == MAX)
		{
			if (tmp->rank > ranking)
				ranking = tmp->rank;
		}
		tmp = tmp->next;
	}
	return (ranking);
}

int	ft_max_from_ints(int a, int b)
{
	int	tmp;

	if (a > b)
		tmp = a;
	else
		tmp = b;
	return (tmp);
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

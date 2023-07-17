/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:00:54 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:01:00 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../includes/libft.h"

char	*ft_make_str(int size, int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		z;

	str = (char *) malloc (sizeof(char) * size);
	i = 0;
	j = 1;
	z = 0;
	while (i < size)
	{
		while (argv[j][z] != '\0' && j < argc)
			str[i++] = argv[j][z++];
		if (i == size - 1)
			str[i] = '\0';
		else
			str[i] = ' ';
		z = 0;
		i++;
		j++;
	}
	return (str);
}

int	ft_str_len(int argc, char **argv)
{
	int		i;
	int		size;
	int		tmp;

	i = 1;
	size = 0;
	while (i < argc)
	{
		tmp = ft_strlen(argv[i]) + 1;
		size += tmp;
		i++;
	}
	return (size);
}

int	ft_validate_arg(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == ' ')
		{
			i++;
			size++;
		}
		else
			size++;
	}
	return (size);
}

t_node	*ft_make_stack_from_str(char *str)
{
	int		size_str;
	char	**array;
	t_node	*tmp;

	size_str = ft_validate_arg(str);
	if (size_str == -1 || size_str == 0 || size_str == 1)
	{
		if ((size_str == 1 && ft_str_is_int(str) == NOT_INT) || size_str == -1)
		{
			free(str);
			ft_exit_stderror();
		}
		else
		{
			free(str);
			exit(EXIT_SUCCESS);
		}
	}
	array = ft_split(str, ' ');
	ft_test_int(&(*array), size_str, &(*str));
	tmp = ft_create_stack(size_str, &(*array));
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	char	*str;
	int		size;

	size = 0;
	if (argc == 2)
		str = ft_strdup(argv[1]);
	else if (argc > 2)
	{
		size = ft_str_len(argc, argv);
		str = ft_make_str(size, argc, argv);
	}
	else
		return (0);
	stack_a = ft_make_stack_from_str(&(*str));
	free(str);
	size = ft_count_node_stack(stack_a);
	ft_create_rank(&stack_a);
	ft_test_asc_dup(&stack_a, size);
	ft_start_stack_b(&stack_a);
	ft_clean_stack_a(&stack_a);
	return (0);
}

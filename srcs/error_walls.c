/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:07:07 by aclement          #+#    #+#             */
/*   Updated: 2022/12/21 16:02:03 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_size_lines(t_env *data)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	size = ft_strlen_prtctd(data->tab[data->size - 1]);
	i = 0;
	if (data->tab[data->size - 1][size - 1] != '\n')
		j = 1;
	while (i < data->size - 1)
	{
		if ((ft_strlen_prtctd(data->tab[i]) - j) != size)
		{
			ft_printf("Error\nplease give me lines with the same's sizes...\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_rwalls(t_env *data)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen_prtctd(data->tab[data->size - 1]);
	if (data->tab[data->size - 1][size - 1] == '\n')
		size--;
	while (i < data->size)
	{
		if (data->tab[i][size - 1] != '1')
		{
			ft_printf("Error\nplease give me a right wall...\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_dwalls(t_env *data)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen_prtctd(data->tab[data->size - 1]);
	if (data->tab[data->size - 1][size - 1] == '\n')
		size--;
	while (i < size)
	{
		if (data->tab[data->size - 1][i] != '1')
		{
			ft_printf("Error\nplease give me a down wall...\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_uwalls(t_env *data)
{
	int	i;
	int	size;

	size = ft_strlen_prtctd(data->tab[0]);
	i = 0;
	while (i < size - 1)
	{
		if (data->tab[0][i] != '1')
		{
			ft_printf("Error\nplease give me an up wall...\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_lwalls(t_env *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (data->tab[i][0] != '1')
		{
			ft_printf("Error\nplease give me a left wall...\n");
			return (0);
		}
		i++;
	}
	return (1);
}

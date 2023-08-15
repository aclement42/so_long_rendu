/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:35 by aclement          #+#    #+#             */
/*   Updated: 2022/12/21 16:04:06 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_size(t_env *data)
{
	int	width;
	int	lenght;

	width = data->size;
	lenght = ft_strlen_prtctd(data->tab[0]) - 1;
	if (width * lenght < 15 || (width < 3 || lenght < 3))
	{
		ft_printf("Error\nplease give me a bigger map\n");
		return (0);
	}
	if (width > 21 || lenght > 40)
	{
		ft_printf("Error\nmap size is too big for the screen\n");
		return (0);
	}
	return (1);
}

int	ft_check_collectible(t_env *data)
{
	int	i;

	i = 1;
	while (i < data->size - 1)
	{
		data->nbcollectible += (ft_c_in_str_so(data->tab[i], 'C'));
		i++;
	}
	if (data->nbcollectible > 0)
		return (1);
	ft_printf("Error\ncollectible is missing\n");
	return (0);
}

int	ft_check_exit(t_env *data)
{
	int	i;

	i = 1;
	while (i < data->size - 1)
	{
		data->nbexit += (ft_c_in_str_so(data->tab[i], 'E'));
		i++;
	}
	if (data->nbexit == 1)
		return (1);
	else if (data->nbexit > 1)
	{
		ft_printf("Error\nplease give me just one exit\n");
		return (0);
	}
	ft_printf("Error\nexit is missing\n");
	return (0);
}

int	ft_check_position(t_env *data)
{
	int	i;

	i = 1;
	while (i < data->size - 1)
	{
		data->nbpos += (ft_c_in_str_data(data->tab[i], 'P', data));
		i++;
	}
	if (data->nbpos == 1)
	{
		ft_keep_p_pos(data);
		return (1);
	}
	else if (data->nbpos > 1)
	{
		ft_printf("Error\nplease give me just one position\n");
		return (0);
	}
	ft_printf("Error\ninitial position is missing\n");
	return (0);
}

int	ft_check_bad_char(t_env *data, char *s)
{
	int	i;
	int	i_bis;
	int	j;

	i = 1;
	j = 0;
	while (i < data->size - 1)
	{
		i_bis = 0;
		while (data->tab[i][i_bis] != '\n')
		{
			j = 0;
			while (data->tab[i][i_bis] != s[j])
			{
				j++;
				if (!s[j])
					return (ft_printf("Error\ninvalid char in the map file\n"),
						0);
			}
			i_bis++;
		}
		i++;
	}
	return (1);
}

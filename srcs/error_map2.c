/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:59 by aclement          #+#    #+#             */
/*   Updated: 2022/12/21 16:02:15 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_keep_p_pos(t_env *data)
{
	int	i;

	i = 1;
	while (i < data->size - 1)
	{
		if (data->tab[i][data->p_pos.x] == 'P')
			data->p_pos.y = i;
		i++;
	}
}

int	ft_c_in_str_so(char *str, char c)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str && str[i] != '\n')
	{
		if (c == str[i])
				nb++;
			i++;
	}
	return (nb);
}

int	ft_c_in_str_data(char *str, char c, t_env *data)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str && str[i] != '\n')
	{
		if (c == str[i])
		{
			data->p_pos.x = i;
			nb++;
		}
		i++;
	}
	return (nb);
}

int	ft_ec_compare(t_env *data)
{
	if (data->c_collected != data->nbcollectible
		|| data->e_collected != data->nbexit)
	{
		ft_printf("Error\nPlayer cant access to exit\n");
		return (0);
	}
	return (1);
}

int	ft_errors_walls(t_env *data)
{
	if (ft_check_map_size(data) == 0)
		return (0);
	if (ft_check_size_lines(data) == 0)
		return (0);
	if (ft_check_dwalls(data) == 0)
		return (0);
	if (ft_check_rwalls(data) == 0)
		return (0);
	if (ft_check_uwalls(data) == 0)
		return (0);
	if (ft_check_lwalls(data) == 0)
		return (0);
	if (ft_check_collectible(data) == 0)
		return (0);
	if (ft_check_exit(data) == 0)
		return (0);
	if (ft_check_position(data) == 0)
		return (0);
	if (ft_check_bad_char(data, GOOD_CHAR) == 0)
		return (0);
	if (ft_run_map(data, CHAR_R) == 0)
		return (0);
	ft_reset_map(data, CHAR_RW);
	return (1);
}

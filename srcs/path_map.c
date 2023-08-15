/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:07:40 by aclement          #+#    #+#             */
/*   Updated: 2022/12/21 13:03:40 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_run_map(t_env *data, char *s)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->size - 1)
	{
		j = 1;
		while (data->tab[i][j] != '\n')
		{
			if (data->tab[i][j] == '0' || data->tab[i][j] == 'C'
				|| data->tab[i][j] == 'E')
			{
				if (ft_verif_char_sides(data, i, j, CHAR_SIDE) == 1)
				{
					ft_replace_char(data, i, j, s);
					i = 1;
					j = 0;
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_reset_map(t_env *data, char *s)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->size - 1)
	{
		j = 1;
		while (data->tab[i][j] != '\n')
		{
			if (data->tab[i][j] == 'X' || data->tab[i][j] == 'Y'
				|| data->tab[i][j] == 'Z')
			{
				if (ft_verif_char_sides(data, i, j, CHAR_SIDE_RES) == 1)
				{
					ft_replace_char(data, i, j, s);
					i = 1;
					j = 0;
				}
			}
			j++;
		}
		i++;
	}
}

int	ft_verif_char_sides(t_env *data, int i, int j, char *rrw)
{
	if (data->tab[i - 1][j] == rrw[0] || data->tab[i - 1][j] == rrw[1]
			|| data->tab[i - 1][j] == rrw[2] || data->tab[i - 1][j] == rrw[3])
		return (1);
	else if (data->tab[i + 1][j] == rrw[0] || data->tab[i + 1][j] == rrw[1]
			|| data->tab[i + 1][j] == rrw[2] || data->tab[i + 1][j] == rrw[3])
		return (1);
	else if (data->tab[i][j - 1] == rrw[0] || data->tab[i][j - 1] == rrw[1]
			|| data->tab[i][j - 1] == rrw[2] || data->tab[i][j - 1] == rrw[3])
		return (1);
	else if (data->tab[i][j + 1] == rrw[0] || data->tab[i][j + 1] == rrw[1]
			|| data->tab[i][j + 1] == rrw[2] || data->tab[i][j + 1] == rrw[3])
		return (1);
	return (0);
}

void	ft_replace_char(t_env *data, int i, int j, char *replace)
{
	if (data->tab[i][j] == replace[0])
		data->tab[i][j] = replace[1];
	else if (data->tab[i][j] == replace[2])
	{
		data->tab[i][j] = replace[3];
		if (replace[3] == 'Y')
			data->c_collected++;
	}
	else if (data->tab[i][j] == replace[4])
	{
		data->tab[i][j] = replace[5];
		if (replace[5] == 'Z')
			data->e_collected++;
	}
}

void	ft_show_img(t_mlx *mlx, int i, int j)
{
	if (mlx->env.tab[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr,
			mlx->win_ptr, mlx->img_wall, (j * 64), (i * 64));
	else if (mlx->env.tab[i][j] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr,
			mlx->win_ptr, mlx->img_floor, (j * 64), (i * 64));
	else if (mlx->env.tab[i][j] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr,
			mlx->win_ptr, mlx->img_player, (j * 64), (i * 64));
	else if (mlx->env.tab[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr,
			mlx->win_ptr, mlx->img_exit, (j * 64), (i * 64));
	else if (mlx->env.tab[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr,
			mlx->win_ptr, mlx->img_coll, (j * 64), (i * 64));
}

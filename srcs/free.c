/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:07:13 by aclement          #+#    #+#             */
/*   Updated: 2022/12/20 15:46:10 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_tab(t_env *data)
{
	int	i;

	i = 0;
	if (!data->tab)
		return ;
	while (i < data->size)
	{
		if (data->tab[i])
			free(data->tab[i]);
		i++;
	}
	if (data->tab)
		free(data->tab);
}

void	ft_free_mlx(t_mlx *mlx)
{
	ft_free_tab(&mlx->env);
}

int	ft_close_window(t_mlx *mlx)
{
	ft_free_tab(&mlx->env);
	if (mlx->mlx_ptr)
	{
		ft_free_sprites(mlx);
		if (mlx->win_ptr)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(10);
	return (0);
}

void	ft_free_sprites(t_mlx *mlx)
{
	if (mlx->img_coll)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_coll);
	if (mlx->img_exit)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_exit);
	if (mlx->img_floor)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_floor);
	if (mlx->img_player)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_player);
	if (mlx->img_wall)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_wall);
}

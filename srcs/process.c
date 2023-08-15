/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:07:46 by aclement          #+#    #+#             */
/*   Updated: 2022/12/21 15:56:01 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard(int key, t_mlx *mlx)
{
	if (key == 65307)
		return (ft_close_window(mlx));
	else if (key == 100)
		ft_move_player(&mlx->env, key, mlx);
	else if (key == 119)
		ft_moove_player(&mlx->env, key, mlx);
	else if (key == 115)
		ft_moove_player(&mlx->env, key, mlx);
	else if (key == 97)
		ft_move_player(&mlx->env, key, mlx);
	return (0);
}

int	ft_move_player(t_env *data, int key, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (key == 100)
	{
		if (data->tab[data->p_pos.y][data->p_pos.x + 1] == '1')
			return (0);
		i++;
		ft_printf("number of moove : %d\n", ++data->nb_moove);
		ft_move_joueur(mlx, data, i, j);
	}
	else if (key == 97)
	{
		if (data->tab[data->p_pos.y][data->p_pos.x - 1] == '1')
			return (0);
		i--;
		ft_printf("number of moove : %d\n", ++data->nb_moove);
		ft_move_joueur(mlx, data, i, j);
	}
	return (1);
}

int	ft_moove_player(t_env *data, int key, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (key == 119)
	{
		if (data->tab[data->p_pos.y - 1][data->p_pos.x] == '1')
			return (0);
		j--;
		ft_printf("number of moove : %d\n", ++data->nb_moove);
		ft_move_joueur(mlx, data, i, j);
	}
	else if (key == 115)
	{
		if (data->tab[data->p_pos.y + 1][data->p_pos.x] == '1')
			return (0);
		j++;
		ft_printf("number of moove : %d\n", ++data->nb_moove);
		ft_move_joueur(mlx, data, i, j);
	}
	return (1);
}

void	ft_move_joueur(t_mlx *mlx, t_env *data, int x, int y)
{
	if (data->tab[data->p_pos.y][data->p_pos.x] == 'C')
	{
		data->tab[data->p_pos.y][data->p_pos.x] = '0';
		data->c_collected++;
	}
	if (data->tab[data->p_pos.y][data->p_pos.x] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img_exit, data->p_pos.x * 64, data->p_pos.y * 64);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img_floor, data->p_pos.x * 64, data->p_pos.y * 64);
	data->p_pos.x += x;
	data->p_pos.y += y;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->img_player, data->p_pos.x * 64, data->p_pos.y * 64);
	if (data->tab[data->p_pos.y][data->p_pos.x] == 'E'
		&& mlx->env.c_collected == mlx->env.nbcollectible)
		ft_close_window(mlx);
}

void	ft_choose_sprites(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_init_sprites(mlx) == 0)
	{	
		ft_printf("Error\nan error occured on one of the sprite\n");
		ft_close_window(mlx);
	}
	if (ft_init_sprites2(mlx) == 0)
	{	
		ft_printf("Error\nan error occured on one of the sprite\n");
		ft_close_window(mlx);
	}
	while (i < mlx->env.size)
	{
		j = 0;
		while (j < ft_strlen_prtctd(mlx->env.tab[0]) - 1)
			ft_show_img(mlx, i, j++);
		i++;
	}
	mlx->env.c_collected = 0;
}

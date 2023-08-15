/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:08:28 by aclement          #+#    #+#             */
/*   Updated: 2022/12/21 16:00:45 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_recup_map(t_env *data, char **av)
{
	int			i;
	char		*stock;

	i = 0;
	stock = "";
	data->open_file = open(av[1], O_RDONLY);
	if (data->open_file == -1)
	{
		ft_printf("Error\ntoo much or too few args\n");
		ft_free_tab(data);
		exit(0);
	}
	while (stock != NULL)
	{
		stock = get_next_line(data->open_file);
		if (stock)
			free(stock);
		i++;
	}
	data->tab = malloc(sizeof(char *) * i);
	if (!(data->tab))
		return (-1);
	data->tab[i - 1] = NULL;
	close(data->open_file);
	return (i - 1);
}

void	ft_line_by_line(t_env *data, char **av)
{
	int	j;

	data->size = ft_recup_map(data, av);
	if (data->size == 0)
	{
		ft_printf("Error\nplease give me a map...\n");
		ft_free_tab(data);
		exit(0);
	}
	j = 0;
	data->open_file = open(av[1], O_RDONLY);
	while (j < data->size)
		data->tab[j++] = get_next_line(data->open_file);
	close(data->open_file);
	if (ft_errors_walls(data) == 0)
	{
		ft_free_tab(data);
		exit(0);
	}
	if (ft_ec_compare(data) == 0)
	{
		ft_free_tab(data);
		exit(0);
	}
}

int	ft_init_sprites(t_mlx *mlx)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	mlx->img_coll = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/collectible.xpm", &w, &h);
	if (!mlx->img_coll)
		return (0);
	mlx->img_exit = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/door.xpm", &w, &h);
	if (!mlx->img_exit)
		return (0);
	mlx->img_floor = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/sand.xpm", &w, &h);
	if (!mlx->img_floor)
		return (0);
	return (1);
}

int	ft_init_sprites2(t_mlx *mlx)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	mlx->img_player = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/crab.xpm", &w, &h);
	if (!mlx->img_player)
		return (0);
	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/bricks.xpm", &w, &h);
	if (!mlx->img_wall)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	ft_memset(&mlx, 0, sizeof(mlx));
	if (ac != 2)
		ft_printf("Error\ntoo much or too few args\n");
	else
	{
		ft_line_by_line(&mlx.env, av);
		mlx.mlx_ptr = mlx_init();
		if (mlx.mlx_ptr == NULL)
			return (1);
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,
				((ft_strlen_prtctd(mlx.env.tab[0]) - 1) * 64),
				(mlx.env.size * 64), "SO_LONG");
		if (!mlx.win_ptr)
			return (1);
		ft_choose_sprites(&mlx);
		mlx_hook(mlx.win_ptr, 17, 1L << 0, ft_close_window, &mlx);
		mlx_hook(mlx.win_ptr, 2, 1L << 0, keyboard, &mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	ft_free_mlx(&mlx);
	return (0);
}

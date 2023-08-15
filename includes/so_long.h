/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:58:04 by aclement          #+#    #+#             */
/*   Updated: 2022/12/21 15:02:01 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/mlx/mlx.h"
# include <X11/keysym.h>
# include "../lib/libft/libft.h"
# include "../includes/get_next_line_bis.h"
# define RES_1 2560
# define RES_2 1440
# define GOOD_CHAR "01CEP\n"
# define CHAR_R  "0XCYEZ\n"
# define CHAR_SIDE "YZXP"
# define CHAR_SIDE_RES "CE0P"
# define CHAR_RW "X0YCZE\n"
# define OCE "0CE"
# define ESC 27

typedef struct s_p_position
{
	int	x;
	int	y;
}	t_p_position;

typedef struct s_env
{
	int				open_file;
	int				size;
	char			**tab;
	int				nbcollectible;
	int				nbexit;
	int				nbpos;
	int				c_collected;
	int				e_collected;
	int				nb_moove;
	t_p_position	p_pos;
}	t_env;

typedef struct s_img
{
	void	*img_p;
	int		w;
	int		h;
}	t_img;

typedef struct s_mlx
{
	t_env	env;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_coll;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_floor;
	char	*addr;
	int		bits_per_pix;
	int		line_lenght;
	int		endian;
	char	*title;
}	t_mlx;

/*
error_walls.c
*/

int		ft_check_lwalls(t_env *data);
int		ft_check_uwalls(t_env *data);
int		ft_check_rwalls(t_env *data);
int		ft_check_dwalls(t_env *data);
int		ft_check_size_lines(t_env *data);

/*
error_map.c
*/

int		ft_check_map_size(t_env *data);
int		ft_check_collectible(t_env *data);
int		ft_check_exit(t_env *data);
int		ft_check_position(t_env *data);
int		ft_check_bad_char(t_env *data, char *s);

/*
error_map2.c
*/

int		ft_c_in_str_so(char *str, char c);
int		ft_c_in_str_data(char *str, char c, t_env *data);
void	ft_keep_p_pos(t_env *data);
int		ft_ec_compare(t_env *data);
int		ft_errors_walls(t_env *data);

/*
free.c
*/

void	ft_free_tab(t_env *data);
void	ft_free_mlx(t_mlx *mlx);
int		ft_close_window(t_mlx *mlx);
void	ft_free_sprites(t_mlx *mlx);

/*
gnl_utils.c


int     ft_strlen_prtctd(char *s);
int     ft_found_nl(char *s);
char    *ft_buff_adjust(char *s, size_t n);


gnl.c


static	char	*ft_line_builder(char *line, char *buff);
char	*get_next_line(int fd);
*/
/*
path_map.c
*/

int		ft_run_map(t_env *data, char *s);
void	ft_reset_map(t_env *data, char *s);
int		ft_verif_char_sides(t_env *data, int i, int j, char *rrw);
void	ft_replace_char(t_env *data, int i, int j, char *replace);
void	ft_show_img(t_mlx *mlx, int i, int j);

/*
process.c
*/

int		keyboard(int key, t_mlx *mlx);
int		ft_move_player(t_env *data, int key, t_mlx *mlx);
int		ft_moove_player(t_env *data, int key, t_mlx *mlx);
void	ft_move_joueur(t_mlx *mlx, t_env *data, int x, int y);
void	ft_choose_sprites(t_mlx *mlx);

void	ft_ft(t_env *data, int i, int j, char *str);
/*
so_long.c
*/

int		ft_recup_map(t_env *data, char **av);
void	ft_line_by_line(t_env *data, char **av);
int		ft_init_sprites(t_mlx *mlx);
int		ft_init_sprites2(t_mlx *mlx);
int		main(int ac, char **av);

#endif

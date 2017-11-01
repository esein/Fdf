/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerfdf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:27:39 by gcadiou           #+#    #+#             */
/*   Updated: 2017/11/01 04:21:39 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERFDF_H
# define HEADERFDF_H

#include <fcntl.h>

#include "Libft/libft.h"
#include "minilibx_macos/mlx.h"

# define USAGE       1
# define OPEN_ERROR  2
# define INVALID_MAP 3

# define MLX_WHITE 0x00FFFFFF
# define MLX_RED   0x00FF0000
# define MLX_GREEN 0x0000FF00
# define MLX_BLUE  0x000000FF

typedef union				u_color
{
	unsigned int		i;
	unsigned char	tab[4];
}							t_color;

typedef struct				s_map
{
	int		**tab;
	int		h;
	int		w;
	int		alt_max;
}							t_map;

typedef struct				s_img
{
	void	*adr;
	char	*data;
	int		bpp;
	int		s_line;
	int		endian;
	int		h;
	int		w;
	int		x;
	int		y;
	t_color	color;
}							t_img;

typedef struct				s_win
{
	t_map	map;
	t_img	img;
	void	*mlx;
	void	*win;
	int		h;
	int		h_start;
	int		w;
	int		w_start;
	int		tile_h;
	int		tile_w;
	int		alt;
	int		error_code;
}							t_win;

typedef struct				s_point
{
	int				x;
	int				y;
	int				rx;
	int				ry;
	int				ux;
	int				uy;
}							t_point;

int							init_win(t_win *win);

int							fdf_error(int error_code);

int							put_pixel_to_img(t_img *img, int x, int y);

int							parse_map(struct s_map *map, char **argv);

struct s_point				get_iso_point(t_win *win, int x, int y, int **tab);

void						draw_up(t_win *win, t_point *point);

void						draw_right(t_win *win, t_point *point);

int							draw_wire(t_win *win, t_point *point, int x, int y);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerfdf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:27:39 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/30 02:45:35 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERFDF_H
# define HEADERFDF_H

#include <fcntl.h>

#include "Libft/libft.h"
#include "minilibx_macos/mlx.h"

# define USAGE      1
# define OPEN_ERROR 2
# define INVALID_MAP  3

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
}							t_map;

typedef struct				s_img
{
	void	*adr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		h;
	int		w;
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
	int				dx;
	int				dy;
}							t_point;

int		fdf_error(int error_code);

int		put_pixel_to_img(t_img *img, int x, int y, t_color *color);

int		parse_map(struct s_map *map, char **argv);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerfdf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:27:39 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/27 21:53:46 by gcadiou          ###   ########.fr       */
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

typedef struct				s_map
{
	int		**tab;
	int		h;
	int		w;
}							t_map;

typedef struct				s_win
{
	t_map	map;
	void	*mlx;
	void	*win;
	int		h;
	int		w;
	int		error_code;
}							t_win;

typedef struct				s_img
{
	void	*adr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}							t_img;

typedef enum				e_color
{
	MLX_RED, MLX_GREEN, MLX_BLUE, MLX_ALPHA
}							t_color;

typedef union				u_pixel
{
	unsigned int		i;
	unsigned char	tab[4];
}							t_pixel;

int		fdf_error(int error_code);

void	put_pixel_to_img(t_img *img, int x, int y, t_pixel *pixel);

int		parse_map(struct s_map *map, char **argv);

#endif

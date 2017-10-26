/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerfdf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:27:39 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/26 21:25:03 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERFDF_H
# define HEADERFDF_H

#include "Libft/libft.h"
#include "minilibx_macos/mlx.h"

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

void	put_pixel_to_img(t_img *img, int x, int y, t_pixel *pixel);

#endif

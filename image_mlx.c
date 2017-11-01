/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:34:36 by gcadiou           #+#    #+#             */
/*   Updated: 2017/11/01 03:46:54 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"

int		put_pixel_to_img(t_img *img, int x, int y)
{
	if (x <= 0 || x >= img->w || y <= 0 || y >= img->h)
		return (0);
	if (img->endian == 0)
	{
		img->data[y * img->s_line + x *(img->bpp / 8)] = img->color.tab[0];
		img->data[y * img->s_line + x *(img->bpp / 8) + 1] = img->color.tab[1];
		img->data[y * img->s_line + x *(img->bpp / 8) + 2] = img->color.tab[2];
		img->data[y * img->s_line + x *(img->bpp / 8) + 3] = img->color.tab[3];
	}
	else
	{
		img->data[y * img->s_line + x * (img->bpp / 8)] = img->color.tab[3];
		img->data[y * img->s_line + x * (img->bpp / 8) + 1] =
															img->color.tab[2];
		img->data[y * img->s_line + x * (img->bpp / 8) + 2] =
															img->color.tab[1];
		img->data[y * img->s_line + x * (img->bpp / 8) + 3] =
															img->color.tab[0];
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:34:36 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/26 21:19:22 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"
/*
void	put_pixel_to_img(t_img *img, int x, int y, t_pixel *pixel)
{
	if (img->endian == 1)
	{
		img->data[(y * img->size_line + x *(img->bpp / *))] = pixel->r;
		img->data[(y * img->size_line + x *(img->bpp / *)) + 1] = pixel->g;
		img->data[(y * img->size_line + x *(img->bpp / *)) + 2] = pixel->b;
		img->data[(y * img->size_line + x *(img->bpp / *)) + 3] = pixel->a;
	}
	else
	{
		img->data[(y * img->size_line + x *(img->bpp / *))] = pixel->a;
		img->data[(y * img->size_line + x *(img->bpp / *)) + 1] = pixel->b;
		img->data[(y * img->size_line + x *(img->bpp / *)) + 2] = pixel->g;
		img->data[(y * img->size_line + x *(img->bpp / *)) + 3] = pixel->r;
	}
}
*/
void	put_pixel_to_img(t_img *img, int x, int y, t_pixel *pixel)
{
	if (img->endian == 0)
	{
		img->data[y * img->size_line + x *(img->bpp / 8)] = pixel->tab[0];
		img->data[y * img->size_line + x *(img->bpp / 8) + 1] = pixel->tab[1];
		img->data[y * img->size_line + x *(img->bpp / 8) + 2] = pixel->tab[2];
		img->data[y * img->size_line + x *(img->bpp / 8) + 3] = pixel->tab[3];
	}
	else
	{
		img->data[y * img->size_line + x * (img->bpp / 8)] = pixel->tab[3];
		img->data[y * img->size_line + x * (img->bpp / 8) + 1] = pixel->tab[2];
		img->data[y * img->size_line + x * (img->bpp / 8) + 2] = pixel->tab[1];
		img->data[y * img->size_line + x * (img->bpp / 8) + 3] = pixel->tab[0];
	}
}

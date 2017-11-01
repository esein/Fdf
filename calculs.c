/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:12:44 by gcadiou           #+#    #+#             */
/*   Updated: 2017/11/01 04:20:13 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"

struct s_point		get_iso_point(t_win *win, int x, int y, int **tab)
{
	struct s_point	point;

	point.x = ((x - y) * win->tile_w + win->w_start);
	point.y = ((x + y) * win->tile_h + win->h_start - (tab[y][x] * win->alt));
	if (x < (win->map.w - 1))
	{
		point.rx = ((x + 1 - y) * win->tile_w + win->w_start);
		point.ry = ((x + 1 + y) * win->tile_h + win->h_start -
												(tab[y][x + 1] * win->alt));
	}
	if (y > 0)
	{
		point.ux = ((x - (y - 1)) * win->tile_w + win->w_start);
		point.uy = ((x + (y - 1)) * win->tile_h + win->h_start -
												(tab[y - 1][x] * win->alt));
	}
	return (point);
}

void				draw_up(t_win *win, t_point *point)
{
	int c;
	int d;

	c = (point->y - point->uy) / (point->x - point->ux);
	d = point->y - (c * point->x);
	if (c <= 1 && c >= -1)
	{
		win->img.x = point->x;
		while (win->img.x < point->ux)
		{
			win->img.y = c * win->img.x + d;
			put_pixel_to_img(&win->img, win->img.x, win->img.y);
			win->img.x++;
		}
	}
	else
	{
		win->img.y = point->y;
		while (win->img.y != point->uy)
		{
			win->img.x = (win->img.y - d) / c;
			put_pixel_to_img(&win->img, win->img.x, win->img.y);
			win->img.y += (win->img.y < point->uy) ? 1 : -1;
		}
	}
}

void				draw_right(t_win *win, t_point *point)
{
	int c;
	int d;

	c = (point->y - point->ry) / (point->x - point->rx);
	d = point->y - (c * point->x);
	if (c <= 1 && c >= -1)
	{
		win->img.x = point->x;
		while (win->img.x < point->rx)
		{
			win->img.y = c * win->img.x + d;
						put_pixel_to_img(&win->img, win->img.x, win->img.y);
			win->img.x++;
		}
	}
	else
	{
		win->img.y = point->y;
		while (win->img.y < point->ry)
		{
			win->img.x = (win->img.y - d) / c;
			put_pixel_to_img(&win->img, win->img.x, win->img.y);
			win->img.y++;
		}
	}
}

int					draw_wire(t_win *win, t_point *point, int x, int y)
{
	if (y > 0)
		draw_up(win, point);
	if (x < (win->map.w - 1))
		draw_right(win, point);
	return (0);
}


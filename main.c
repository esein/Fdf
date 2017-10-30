/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:25:00 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/31 00:06:50 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"

struct s_point		get_iso_point(t_win *win, int x, int y, int **tab)
{
	struct s_point	point;

	point.x = ((x - y) * win->tile_w + win->w_start);
	point.y = ((x + y) * win->tile_h + win->h_start + (tab[y][x] * win->alt));
	if (x < (win->map.w - 1))
	{
		point.rx = ((x + 1 - y) * win->tile_w + win->w_start);
		point.ry = ((x + 1 + y) * win->tile_h + win->h_start + (tab[y][x + 1] * win->alt));
	
		ft_putnbr(x);
		ft_putchar(' ');
		ft_putnbr(tab[y][x + 1]);
	ft_putchar(' ');
		ft_putnbr(point.y);
	ft_putchar(' ');
	ft_putnbr(point.ry);
	ft_putchar('\n');

	}
	if (y > 0)
	{
		point.ux = ((x - (y - 1)) * win->tile_w + win->w_start);
		point.uy = ((x + (y - 1)) * win->tile_h + win->h_start + (tab[y - 1][x] * win->alt));
	}
	return (point);
}

void				draw_up(t_win *win, t_point *point)
{
	int c;
	int d;

	c = (point->y - point->uy) / (point->x - point->ux);
	d = point->y - (c * point->x);
	if (c <= 1 || c >= -1)
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
		while (win->img.y < point->uy)
		{
			win->img.x = (win->img.y - d) / c;
			put_pixel_to_img(&win->img, win->img.x, win->img.y);
			win->img.y++;
		}
	}
}

void				draw_right(t_win *win, t_point *point)
{
	int c;
	int d;

	c = (point->y - point->ry) / (point->x - point->rx);
	d = point->y - (c * point->x);
	if (c <= 1 || c >= -1)
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

int		map_to_iso(struct s_win *win)
{
	int				y;
	int				x;
	struct s_point	point;

	y = 0;
	x = 0;
	win->error_code = 0;
	while (win->map.tab[y])
		y++;
	while (y > 0)
	{
		y--;
		x = 0;
		while (x < win->map.w)
		{
			point = get_iso_point(win, x, y, win->map.tab);
			put_pixel_to_img(&win->img, point.x, point.y);
			draw_wire(win, &point,x ,y);
			x++;
		}
	}
	return (win->error_code);
}


int		main(int argc, char **argv)
{
	struct s_win	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1280, 720, "fdf");
	win.img.adr = mlx_new_image(win.mlx, 1280, 720);
	win.img.data = mlx_get_data_addr(win.img.adr, &(win.img.bpp),
											&win.img.s_line, &win.img.endian);
	win.img.color.i = 0x00FFFFFF;
	win.h_start = 100;
	win.w_start = 650;
	win.tile_w = 20;
	win.tile_h = 20;
	win.img.h = 720;
	win.img.w = 1280;
	win.alt = 2;
	if (argc < 2)
		return (fdf_error(USAGE));
	if ((win.error_code = parse_map(&win.map, argv)) != 0)
		return (fdf_error(win.error_code));
	if ((win.error_code = map_to_iso(&win)) != 0)
		return(fdf_error(win.error_code));
	mlx_put_image_to_window(win.mlx, win.win, win.img.adr, 0, 0);
	mlx_loop(win.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:25:00 by gcadiou           #+#    #+#             */
/*   Updated: 2017/11/01 04:20:16 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"

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

void			color_swap(t_win *win)
{
	if (win->img.color.i == MLX_WHITE)
		win->img.color.i = MLX_RED;
	else if (win->img.color.i == MLX_RED)
		win->img.color.i = MLX_GREEN;
	else if (win->img.color.i == MLX_GREEN)
		win->img.color.i = MLX_BLUE;
	else if (win->img.color.i == MLX_BLUE)
		win->img.color.i = MLX_WHITE;
}

int		key_hook(int k, t_win *win)
{
	if (k == 53)
		exit(0);
	else if (k == 12)
	{
		color_swap(win);
		map_to_iso(win);
		mlx_put_image_to_window(win->mlx, win->win, win->img.adr, 0, 0);
	}
	return (0);
}

int		init_win(t_win *win)
{
	win->img.color.i = 0x00FFFFFF;
	win->h_start = 300;
	win->w_start = 750;
	win->tile_w = 20;
	win->tile_h = 20;
	win->img.h = 1080;
	win->img.w = 1920;
	win->alt = 10;
	return (0);
}

int		main(int argc, char **argv)
{
	struct s_win	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1920, 1080, "fdf");
	win.img.adr = mlx_new_image(win.mlx, 1920, 1080);
	win.img.data = mlx_get_data_addr(win.img.adr, &(win.img.bpp),
											&win.img.s_line, &win.img.endian);
	if ((win.error_code = parse_map(&win.map, argv)) != 0)
		return (fdf_error(win.error_code));
	init_win(&win);
	if (argc < 2)
		return (fdf_error(USAGE));
	if ((win.error_code = map_to_iso(&win)) != 0)
		return(fdf_error(win.error_code));
	mlx_put_image_to_window(win.mlx, win.win, win.img.adr, 0, 0);
	mlx_key_hook(win.win, key_hook, &win);
	mlx_loop(win.mlx);
	return (0);
}

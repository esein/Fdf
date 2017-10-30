/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:25:00 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/30 02:45:34 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"

struct s_point		*get_iso_point(t_win *win, int x, int y, int **tab)
{
	struct s_point	*point;

	point = (t_point*)ft_memalloc(sizeof(t_point));
	point->x = ((x - y) * win->tile_w + win->w_start);
	point->y = ((x + y) * win->tile_h + win->h_start + (tab[x][y] * win->alt));
	point->rx = ((x + 1 - y) * win->tile_w + win->w_start);
	point->ry = ((x + 1 + y) * win->tile_h + win->h_start + (tab[x][y] * win->alt));
	point->dx = ((x - (y + 1)) * win->tile_w + win->w_start);
	point->dy = ((x + 1 + y) * win->tile_h + win->h_start + (tab[x][y] * win->alt));
	ft_putnbr(tab[x][y] * win->alt);
	ft_putchar('\n');
	return (point);
}

int					draw_wire(t_win *win, t_point *point)
{
	return (0);
}

int		map_to_iso(struct s_win *win)
{
	int				y;
	int				x;
	struct s_point	*point;

	y = 0;
	x = 0;
	win->error_code = 0;
	while (win->map.tab[y])
	{
		x = 0;
		while (x < win->map.w)
		{
			point = get_iso_point(win, x, y, win->map.tab);
			put_pixel_to_img(&win->img, point->x, point->y, &win->img.color);
			//			draw_wire(win, point);
			x++;
		}
		y++;
	}
	return (win->error_code);
}


int		main(int argc, char **argv)
{
	struct s_win	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1280, 720, "fdf");
	win.img.adr = mlx_new_image(win.mlx, 1280, 720);
	win.img.data = mlx_get_data_addr(win.img.adr, &(win.img.bpp), &win.img.size_line, &win.img.endian);
	win.img.color.i = 0x00FFFFFF;
	win.h_start = 150;
	win.w_start = 250;
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

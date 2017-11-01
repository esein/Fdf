/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:31:37 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/31 23:30:23 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"

int		main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		size_line;
	struct s_img	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "mlx 42");
	img.adr = mlx_new_image(mlx, 1000, 1000);
	img.data = mlx_get_data_addr(img.adr, &(img.bpp), &(img.s_line), &(img.endian));
	img.color.i = 0x00FFFFFF;
	y = 50;
	while (y < 750)
	{
		x = 50;
		img.color.i = 0x00FFFFFF;
		while (x < 750)
		{
			put_pixel_to_img(&img, x, y);
			img.color.tab[1]--;
//			img.color.tab[2]++;
			img.color.tab[0]--;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, img.adr, 0, 0);
	mlx_loop(mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:25:00 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/27 22:18:00 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"

int		main(int argc, char **argv)
{
	struct s_win	win;

	if (argc < 2)
		return (fdf_error(USAGE));
	if ((win.error_code = parse_map(&(win.map), argv)) != 0)
		return (fdf_error(win.error_code));
	return (0);
}

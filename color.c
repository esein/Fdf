/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:40:28 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/26 19:55:48 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"

void	init_color(t_pixel *pixel, int color)
{
	union u_conv	conv;

	conv.i = color;
	pixel->r = conv.tab[0];
	pixel->g = conv.tab[1];
	pixel->b = conv.tab[2];
	pixel->a = conv.tab[3];
}

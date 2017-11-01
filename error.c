/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:12:44 by gcadiou           #+#    #+#             */
/*   Updated: 2017/11/01 04:21:37 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"
#include "headerfdf.h"

int		fdf_error(int error_code)
{
	if (error_code == 0)
	{
		ft_puterror("undefined error");
		exit(1);
	}
	else if (error_code == USAGE)
		return (ft_puterror("usage : fdf [file]"));
	else if (error_code == OPEN_ERROR)
		return (ft_puterror("open error"));
	else if (error_code == INVALID_MAP)
		return (ft_puterror("invalid map"));
	return (1);
}

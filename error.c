/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:35:32 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/27 22:57:42 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (error_code == INVALID_MAP)
		return (ft_puterror("invalid map"));
	return (0);
}

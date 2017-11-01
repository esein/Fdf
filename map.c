/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:40:33 by gcadiou           #+#    #+#             */
/*   Updated: 2017/11/01 03:53:01 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"

int		check_file(struct s_map *map, int fd)
{
	char	*line;
	int		i;
	int		tmp;

	map->tab = ft_memalloc(sizeof(int*));
	map->w = 0;
	map->h = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			i++;
		}
		map->tab = ft_realloc(map->tab, sizeof(int*) * (map->h + 2),
								sizeof(int*) * (map->h + 1));
		tmp = map->w;
		map->w = ft_strsplit_atoi(&(map->tab[map->h]), line);
		if (tmp != map->w && tmp != 0)
			return (INVALID_MAP);
		map->h++;
	}
	return (0);
}

int		parse_map(struct s_map *map, char **argv)
{
	int		fd;

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (OPEN_ERROR);
	if (check_file(map, fd) != 0)
		return (INVALID_MAP);
	return (0);
}

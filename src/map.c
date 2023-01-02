/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:13:46 by tpaaso            #+#    #+#             */
/*   Updated: 2023/01/02 11:38:17 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_copy_tetri(t_pcs *pcs, const char *file)
{
	int		ret;
	int		i;
	int		fd;
	char	buf[22];

	i = 0;
	fd = open(file, O_RDONLY);
	ret = read(fd, buf, 21);
	while (pcs->amount > i)
	{
		buf[ret] = '\0';
		pcs->pieces[i] = ft_strsplit(buf, '\n');
		ft_move_mino(pcs->pieces[i]);
		i++;
		ret = read(fd, buf, 21);
	}
}

char	**ft_newmap(t_map *map)
{
	char	**kartta;
	int		x;
	int		y;

	kartta = (char **)malloc(sizeof(char *) * map->size);
	y = 0;
	if (kartta == NULL)
		ft_exit("error");
	while (y < map->size)
	{
		kartta[y] = ft_strnew(map->size + 1);
		x = 0;
		while (x < map->size)
		{
			kartta[y][x] = '.';
			x++;
		}
		y++;
	}
	return (kartta);
}

void	ft_delmap(t_map map)
{
	int	i;

	i = 0;
	while (i < map.size)
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
}

void	ft_putmap(t_map map)
{
	int	i;

	i = 0;
	while (i < map.size)
	{
		ft_putendl(map.map[i]);
		i++;
	}
}

void	ft_free(t_map map, t_pcs pcs)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	ft_delmap(map);
	while (y < pcs.amount)
	{
		while (x < 4)
		{
			free(pcs.pieces[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
	while (y < pcs.amount)
		free(pcs.pieces[y++]);
	free(pcs.pieces);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:04:32 by jhimanen          #+#    #+#             */
/*   Updated: 2020/01/24 12:33:33 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	delete_mino(t_map *map, int t)
{
	int x;
	int y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x <= map->size)
		{
			if (map->str[y][x] == 'A' + t)
				map->str[y][x] = '.';
			x++;
		}
		y++;
	}
}

static void	put_mino(t_map *map, t_pcs *block, int t)
{
	int		x;
	int		y;
	int		skip;

	y = 0;
	skip = 0;
	while (block->array[t][0][skip] == '.')
		skip++;
	skip = block->x - skip;
	while (block->y + y < map->size && y < 4)
	{
		x = -1;
		while (++x < 4 && skip + x < map->size)
		{
			if (ft_isupper(block->array[t][y][x])
			&& map->str[block->y + y][skip + x] == '.')
				map->str[block->y + y][skip + x] = 'A' + t;
		}
		y++;
	}
}

static int	fit_mino(t_map *map, t_pcs *block, int t)
{
	int		x;
	int		y;
	int		skip;
	int		count;

	y = 0;
	skip = 0;
	count = 0;
	while (block->array[t][0][skip] == '.')
		skip++;
	skip = block->x - skip;
	if (skip < 0)
		return (0);
	while (block->y + y < map->size && y < 4)
	{
		x = -1;
		while (++x < 4 && skip + x < map->size)
			if (ft_isupper(block->array[t][y][x])
			&& map->str[block->y + y][skip + x] == '.')
				count++;
		y++;
	}
	if (count == 4)
		return (1);
	return (0);
}

int			algorithm(t_map *map, t_pcs *block, int t)
{
	int	x;
	int	y;

	if (t == block->piece)
		return (1);
	y = -1;
	while (++y < map->size)
	{
		x = -1;
		while (++x < map->size)
			if (map->str[y][x] == '.')
			{
				block->x = x;
				block->y = y;
				if (fit_mino(map, block, t))
				{
					put_mino(map, block, t);
					if (algorithm(map, block, ++t))
						return (1);
					else
						delete_mino(map, --t);
				}
			}
	}
	return (0);
}

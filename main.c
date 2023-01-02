/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:12:34 by tpaaso            #+#    #+#             */
/*   Updated: 2023/01/02 11:49:01 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	ft_initmap(t_map *map, t_pcs *pcs)
{
	int	j;
	int	i;

	i = pcs->amount - 1;
	j = 2;
	while (j * j <= i * 4)
		j++;
	map->size = j;
	map->map = ft_newmap(map);
}

void	ft_initpcs(t_pcs *pcs, int count)
{
	int	i;

	i = 0;
	pcs->amount = 0;
	pcs->block = 0;
	pcs->pieces = (char ***)malloc(sizeof(char **) * count);
	if (pcs->pieces == NULL)
		ft_exit("error");
	i = 0;
}

int	algorithm(t_pcs *pcs, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	if (pcs->block == pcs->amount)
		return (1);
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (ft_fitmino(pcs, map, x, y))
			{
				ft_putmino(pcs, map, x, y);
				pcs->block++;
				if (algorithm(pcs, map))
					return (1);
				pcs->block--;
				ft_delmino(map, pcs->block);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_pcs	pcs;
	int		count;

	count = 0;
	if (ac != 2)
		ft_exit("Usage: ./fillit target_file");
	count = ft_count_tetri(av[1]);
	if (count > 26 || count == 0)
		ft_exit("error, ran out of alphabets :/");
	ft_initpcs(&pcs, count);
	pcs.amount = count;
	ft_initmap(&map, &pcs);
	ft_copy_tetri(&pcs, av[1]);
	while (algorithm(&pcs, &map) == 0)
	{
		ft_delmap(map);
		map.size++;
		map.map = ft_newmap(&map);
	}
	ft_putmap(map);
	ft_free(map, pcs);
	return (0);
}

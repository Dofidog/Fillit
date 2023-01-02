/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:16:16 by tpaaso            #+#    #+#             */
/*   Updated: 2022/04/08 12:40:59 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_count_tetri(char *file)
{
	int		i;
	int		ret;
	char	buf[22];
	int		fd;

	fd = open(file, O_RDONLY);
	ret = read(fd, buf, 21);
	i = 0;
	while (ret == 21)
	{
		buf[ret] = '\0';
		ft_validate(buf);
		if (buf[20] != '\n' && buf[20] != '\0')
			return (0);
		ret = read(fd, buf, 21);
		i++;
	}
	buf[ret] = '\0';
	ft_validate(buf);
	if (buf[20] != '\n' && buf[20] != '\0')
		ft_exit("error");
	fd = close(fd);
	i++;
	return (i);
}

int	ft_count_hash(char *buf)
{
	int	i;
	int	hashlen;
	int	dotlen;

	dotlen = 0;
	hashlen = 0;
	i = 0;
	while (i < 20 && (buf[i] == '.' || buf[i] == '\n' || buf[i] == '#'))
	{
		if (buf[i] == '#')
			hashlen++;
		if (buf[i] == '.')
			dotlen++;
		if (buf[i] == '\0')
			break ;
		if ((i == 4 || i == 9 | i == 14 || i == 19) && buf[i] != '\n')
			return (0);
		i++;
	}
	if (hashlen == 4 && i == 20 && dotlen == 12)
		return (1);
	return (0);
}

int	ft_fitmino(t_pcs *pcs, t_map *map, int x, int y)
{
	int	i;
	int	j;
	int	hashcount;

	j = 0;
	hashcount = 0;
	while (hashcount <= 4)
	{
		while (j < 4 && y + j < map->size)
		{
			i = 0;
			while (i < 4 && x + i < map->size)
			{
				if (map->map[y + j][x + i] == '.' &&
					pcs->pieces[pcs->block][j][i] == '#')
					hashcount++;
				i++;
			}
			j++;
		}
		break ;
	}
	if (hashcount == 4)
		return (1);
	return (0);
}

void	ft_putmino(t_pcs *pcs, t_map *map, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < 4 && y + j < map->size)
	{
		i = 0;
		while (i < 4 && x + i < map->size)
		{
			if (map->map[y + j][x + i] == '.' &&
				pcs->pieces[pcs->block][j][i] == '#')
				map->map[y + j][x + i] = 'A' + pcs->block;
			i++;
		}
		j++;
	}
}

void	ft_delmino(t_map *map, int i)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (map->map[y][x] == 'A' + i)
				map->map[y][x] = '.';
			x++;
		}
		y++;
	}
}

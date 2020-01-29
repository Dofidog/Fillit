/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhimanen <jhimanen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:30:10 by jhimanen          #+#    #+#             */
/*   Updated: 2020/01/21 19:39:39 by jhimanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		print_map(t_map map)
{
	int i;

	i = 0;
	while (i < map.size)
		ft_putendl(map.str[i++]);
}

static void		free_map(t_map map)
{
	int		i;

	i = 0;
	while (i < map.size)
		free(map.str[i++]);
	free(map.str);
}

static t_map	new_map(int mapsize)
{
	t_map	map;
	int		i;
	int		j;

	i = 0;
	map.size = mapsize;
	if (!(map.str = (char**)malloc(mapsize * sizeof(char*))))
		ft_exit("error\n");
	while (i < mapsize)
	{
		if (!(map.str[i] = (char*)malloc(mapsize + 1)))
			ft_exit("error\n");
		map.str[i][mapsize] = '\0';
		j = 0;
		while (j < mapsize)
			map.str[i][j++] = '.';
		map.str[i][j] = '\0';
		i++;
	}
	return (map);
}

static int		read_tetriminos(t_pcs *pcs, char **argv)
{
	char	buf[21];
	int		fd;
	int		ret;

	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		if ((ret = read(fd, buf, 20)) != 20)
			ft_exit("error\n");
		buf[ret] = '\0';
		validate(pcs, buf);
		ret = read(fd, buf, 1);
		if (buf[0] != '\n')
			break ;
	}
	if (ret != 0)
		ft_exit("error\n");
	ret = 2;
	while (4 * pcs->piece > ret * ret)
		ret++;
	return (ret);
}

int				main(int argc, char **argv)
{
	t_pcs	pcs;
	t_map	map;
	int		mapsize;

	if (argc != 2)
		ft_exit("usage: fillit source_file\n");
	pcs.x = 0;
	pcs.y = 0;
	pcs.piece = 0;
	mapsize = read_tetriminos(&pcs, argv);
	map = new_map(mapsize);
	while (!algorithm(&map, &pcs, 0))
	{
		free_map(map);
		map.size++;
		map = new_map(map.size);
	}
	print_map(map);
	free_map(map);
	return (0);
}

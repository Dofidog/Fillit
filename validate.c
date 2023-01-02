/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:42:00 by tpaaso            #+#    #+#             */
/*   Updated: 2022/04/08 12:58:09 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_move_leftx(char *str, int j)
{
	int		i;

	i = 0;
	while (i < 4 && j > 0)
	{
		if (str[i] == '#')
		{
			str[i - j] = '#';
			str[i] = '.';
		}
		i++;
	}
}

char	**ft_move_left(char **mino)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mino[0][j] == '.' && mino[1][j] == '.' &&
			mino[2][j] == '.' && mino[3][j] == '.')
	{
		j++;
	}
	while (i < 4)
	{
		ft_move_leftx(mino[i], j);
		i++;
	}
	return (mino);
}

void	ft_move_mino(char **mino)
{
	while (ft_strcmp(mino[0], "....") == 0)
	{
		ft_strcpy(mino[0], mino[1]);
		ft_strcpy(mino[1], mino[2]);
		ft_strcpy(mino[2], mino[3]);
		ft_strcpy(mino[3], "....");
	}
	ft_move_left(mino);
}

int	ft_shape_mino(char *mino)
{
	int		x;
	int		touch;
	int		ws;
	int		y;

	touch = 0;
	x = 0;
	ws = 0;
	y = 4;
	while (x + ws < (int)ft_strlen(mino))
	{
		if (x > 13)
			y = 0;
		if (mino[x + ws] == '\n')
			ws++;
		if (mino[x + ws] == '#')
		{
			if (mino[x + y + ws + 1] == '#')
			touch++;
			if (mino[x + ws + 1] == '#')
			touch++;
		}
		x++;
	}
	return (touch);
}

void	ft_validate(char *buf)
{
	if (!ft_count_hash(buf))
		ft_exit("error");
	if ((ft_shape_mino(buf)) < 3)
		ft_exit("error");
}

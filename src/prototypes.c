/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhimanen <jhimanen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:19:27 by jhimanen          #+#    #+#             */
/*   Updated: 2020/01/21 19:39:40 by jhimanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_exit(char *s)
{
	write(1, s, ft_strlen(s));
	exit(0);
}

static char	*str_move_left(char *s)
{
	int i;

	i = 0;
	while (i < 3)
	{
		s[i] = s[i + 1];
		i++;
	}
	s[3] = '.';
	return (s);
}

static void	rearrange_x(t_pcs *pcs)
{
	int		i;

	i = 0;
	while (i < 4)
		if (pcs->array[pcs->piece - 1][i++][0] != '.')
			i = 5;
	if (i == 4)
	{
		str_move_left(pcs->array[pcs->piece - 1][0]);
		str_move_left(pcs->array[pcs->piece - 1][1]);
		str_move_left(pcs->array[pcs->piece - 1][2]);
		str_move_left(pcs->array[pcs->piece - 1][3]);
		rearrange_x(pcs);
	}
}

void		rearrange_y(t_pcs *pcs)
{
	int		i;
	char	tmp[5];

	i = 0;
	while (i < 4)
		if (pcs->array[pcs->piece - 1][0][i++] != '.')
			i = 5;
	if (i == 4)
	{
		ft_strcpy(tmp, pcs->array[pcs->piece - 1][0]);
		ft_strcpy(pcs->array[pcs->piece - 1][0], pcs->array[pcs->piece - 1][1]);
		ft_strcpy(pcs->array[pcs->piece - 1][1], pcs->array[pcs->piece - 1][2]);
		ft_strcpy(pcs->array[pcs->piece - 1][2], pcs->array[pcs->piece - 1][3]);
		ft_strcpy(pcs->array[pcs->piece - 1][3], tmp);
		rearrange_y(pcs);
	}
	rearrange_x(pcs);
}

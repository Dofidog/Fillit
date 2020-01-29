/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhimanen <jhimanen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:14:13 by jhimanen          #+#    #+#             */
/*   Updated: 2020/01/21 19:20:16 by jhimanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	collect(t_pcs *pcs, int i, int htags)
{
	int		tmp;
	int		j;

	j = 0;
	if (htags > 4)
		ft_exit("error\n");
	tmp = i;
	while (tmp > 4)
	{
		j++;
		tmp -= 5;
	}
	pcs->array[pcs->piece - 1][j][tmp] = '@' + pcs->piece;
}

static int	touching(char *buf, int i)
{
	int touch;

	touch = 0;
	if (i > 4)
		if (buf[i - 5] == '#')
			touch++;
	if (i > 0)
		if (buf[i - 1] == '#')
			touch++;
	if (i < 19)
		if (buf[i + 1] == '#')
			touch++;
	if (i < 14)
		if (buf[i + 5] == '#')
			touch++;
	return (touch);
}

static void	validate_help(t_pcs *pcs, char *buf, t_param *p)
{
	if (buf[p->i] == '.')
		;
	else if (buf[p->i] == '#')
	{
		p->htags++;
		p->touch += touching(buf, p->i);
		collect(pcs, p->i, p->htags);
	}
	else
		ft_exit("error\n");
}

static void	init_array(t_pcs *pcs)
{
	int		i;
	int		j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
			pcs->array[pcs->piece - 1][j][i++] = '.';
		pcs->array[pcs->piece - 1][j++][4] = '\0';
	}
}

void		validate(t_pcs *pcs, char *buf)
{
	t_param		p;

	p.htags = 0;
	p.touch = 0;
	p.i = 0;
	pcs->piece++;
	if (pcs->piece > 26)
		ft_exit("error\n");
	init_array(pcs);
	while (buf[p.i])
	{
		if ((p.i + 1) % 5 == 0)
		{
			if (buf[p.i] != '\n')
				ft_exit("error\n");
		}
		else
			validate_help(pcs, buf, &p);
		p.i++;
	}
	rearrange_y(pcs);
	if (p.htags != 4 || p.touch < 6)
		ft_exit("error\n");
}

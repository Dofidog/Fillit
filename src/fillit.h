/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:46:52 by jhimanen          #+#    #+#             */
/*   Updated: 2020/01/23 14:50:36 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_pcs
{
	char			array[26][4][5];
	int				x;
	int				y;
	int				piece;
}					t_pcs;

typedef	struct		s_param
{
	int				i;
	int				htags;
	int				touch;
}					t_param;

typedef	struct		s_map
{
	int				size;
	char			**str;
}					t_map;

void				validate(t_pcs *pcs, char *buf);
void				rearrange_y(t_pcs *pcs);
void				ft_exit(char *s);
int					algorithm(t_map *map, t_pcs *block, int t);
#endif

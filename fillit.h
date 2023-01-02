/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:30:12 by tpaaso            #+#    #+#             */
/*   Updated: 2023/01/02 11:37:39 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_pcs
{
	int		amount;
	int		block;
	char	***pieces;
}				t_pcs;

typedef struct s_map
{
	int		size;
	char	**map;
}				t_map;

int		ft_count_tetri(char *file);
void	ft_move_mino(char **mino);
void	ft_validate(char *buf);
void	ft_exit(char *str);
char	**ft_newmap(t_map *map);
void	ft_delmap(t_map map);
void	ft_putmap(t_map map);
int		ft_find_tetri(t_pcs *pcs, int fd);
void	ft_move_leftx(char *str, int j);
char	**ft_move_left(char **mino);
int		ft_shape_mino(char *mino);
int		ft_count_hash(char *buf);
void	ft_initmap(t_map *map, t_pcs *pcs);
void	ft_initpcs(t_pcs *pcs, int count);
int		algorithm(t_pcs *pcs, t_map *map);
int		ft_fitmino(t_pcs *pcs, t_map *map, int x, int y);
void	ft_putmino(t_pcs *pcs, t_map *map, int x, int y);
void	ft_delmino(t_map *map, int i);
void	ft_free(t_map map, t_pcs pcs);
char	*ft_newrow(size_t size, char *tmp);
void	ft_copy_tetri(t_pcs *pcs, const char *str);

#endif

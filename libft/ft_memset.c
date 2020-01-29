/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:44:42 by tpaaso            #+#    #+#             */
/*   Updated: 2019/10/29 10:44:48 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	unsigned char *s;

	s = dst;
	while (len)
	{
		*s = (unsigned char)c;
		s++;
		len--;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:39:15 by tpaaso            #+#    #+#             */
/*   Updated: 2019/11/05 11:07:21 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	char	*ptr2;
	char	*result;

	if (!s || !(result = ft_memalloc((size_t)ft_strlen((char *)s) + 1)))
		return (NULL);
	ptr = (char *)s;
	ptr2 = result;
	while (*ptr)
		*(ptr2++) = f(*ptr++);
	return (result);
}

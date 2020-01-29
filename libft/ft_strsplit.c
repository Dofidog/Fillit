/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:46:43 by tpaaso            #+#    #+#             */
/*   Updated: 2019/11/05 12:49:44 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cword(const char *str, char c)
{
	int word;

	word = 0;
	if (*str != c && *str)
	{
		str++;
		word++;
	}
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				word++;
		}
		str++;
	}
	return (word);
}

int		ft_cchar(char const *s, char c)
{
	int ans;

	ans = 0;
	while (*s != c && *s)
	{
		ans++;
		s++;
	}
	return (ans);
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**sa;

	i = 0;
	j = 0;
	if (!s || !(sa = (char **)malloc(sizeof(char *) * ft_cword(s, c) + 1)))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!(sa[j] = (char *)malloc(sizeof(char) * (ft_cchar(s, c) + 1))))
				return (NULL);
			while (*s != c && *s)
				sa[j][i++] = (char)*s++;
			sa[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	sa[j] = NULL;
	return (sa);
}

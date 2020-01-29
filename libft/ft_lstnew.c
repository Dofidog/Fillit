/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:08:56 by tpaaso            #+#    #+#             */
/*   Updated: 2019/12/17 20:17:59 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!malloc (t_list *)malloc(sizeof(size_t)))
		return (NULL);
	new->content = content;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:57:48 by pchalmin          #+#    #+#             */
/*   Updated: 2024/12/04 20:12:53 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	tmp = new;
	while (lst && lst->next)
	{
		if (!tmp)
			return (NULL);
		tmp->next = ft_lstnew(f(lst->next->content));
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}

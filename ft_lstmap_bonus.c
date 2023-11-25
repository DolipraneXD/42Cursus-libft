/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:05:21 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/17 19:36:09 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*nnode;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	nlist = NULL;
	while (lst)
	{
		content = f(lst -> content);
		nnode = ft_lstnew(content);
		if (nnode == NULL)
		{
			free(content);
			ft_lstclear(&nlist, del); 
			return (NULL);
		}
		else
			ft_lstadd_back(&nlist, nnode);
		lst = lst -> next;
	}
	return (nlist);
}

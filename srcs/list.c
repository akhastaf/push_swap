/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:32:27 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/22 17:35:09 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*p;

	tmp = *lst;
	if (lst && del)
	{
		while (tmp)
		{
			p = tmp;
			tmp = tmp->next;
			ft_lstdelone(p, del);
		}
		*lst = NULL;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->data);
		free(lst);
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (temp)
	{
		temp = ft_lstlast(temp);
		(temp)->next = new;
	}
	else
		*alst = new;
}

void	ft_lstprint(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
}
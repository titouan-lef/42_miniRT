/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:10:16 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/13 17:45:47 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTION_H
# define COLLECTION_H

typedef struct s_element
{
	int					nbr;
	struct s_element	*next;
}	t_element;
typedef struct s_queue
{
	t_element	*head;
	t_element	*tail;
}	t_queue;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* queue */
int		ft_queue_is_empty(t_queue *queue);
int		ft_queue_push(t_queue *queue, int nbr);
int		ft_queue_pop(t_queue *queue);
void	ft_queue_clear(t_queue *queue);
t_queue	ft_queue_create(void);

/* list */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstremove_front(t_list *lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
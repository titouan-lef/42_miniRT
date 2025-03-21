/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_primitive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:39:27 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/13 18:38:22 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_queue_is_empty(t_queue *queue)
{
	return (queue->head == NULL);
}

int	ft_queue_push(t_queue *queue, int nbr)
{
	t_element	*element;

	element = (t_element *)malloc(sizeof(t_element));
	if (!element)
	{
		ft_queue_clear(queue);
		ft_putendl_error("Error");
		return (1);
	}
	element->nbr = nbr;
	element->next = NULL;
	if (ft_queue_is_empty(queue))
		queue->head = element;
	else
		queue->tail->next = element;
	queue->tail = element;
	return (0);
}

/*
* Goal: Remove the first element of the queue.
*
* Warning: Queue mustn't be null.
*/
int	ft_queue_pop(t_queue *queue)
{
	t_element	*element;
	int			nbr;

	element = queue->head;
	queue->head = element->next;
	nbr = element->nbr;
	free(element);
	if (queue->head == NULL)
		queue->tail = NULL;
	return (nbr);
}

void	ft_queue_clear(t_queue *queue)
{
	t_element	*element;

	while (!ft_queue_is_empty(queue))
	{
		element = queue->head;
		queue->head = element->next;
		free(element);
	}
	queue->tail = NULL;
}

t_queue	ft_queue_create(void)
{
	t_queue	queue;

	queue.head = NULL;
	queue.tail = NULL;
	return (queue);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:27 by hnam              #+#    #+#             */
/*   Updated: 2019/07/13 20:49:46 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*init_queue(void)
{
	t_queue	*queue;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
		return (NULL);
	queue->front = NULL;
	queue->back = NULL;
	queue->size = 0;
	queue->idx = 0;
	return (queue);
}

void	enqueue(t_queue *queue, t_room *room)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return ;
	node->room = room;
	node->next = NULL;
	node->key = 0;
	if (!queue->front)
	{
		queue->front = node;
		queue->back = node;
	}
	else
	{
		queue->back->next = node;
		queue->back = node;
	}
	queue->size++;
}

t_room	*dequeue(t_queue *queue)
{
	t_node	*tmp;
	t_room	*room;

	if (!queue->front)
		return (NULL);
	tmp = queue->front;
	queue->front = tmp->next;
	if (!queue->front)
		queue->back = NULL;
	room = tmp->room;
	free(tmp);
	queue->size--;
	return (room);
}

void	free_queue(t_queue *queue)
{
	t_node	*node;
	t_node	*tmp;

	if ((node = queue->front))
	{
		while (node)
		{
			tmp = node;
			node = node->next;
			free(tmp);
		}
	}
	free(queue);
}

int		isempty_queue(t_queue *queue)
{
	return (!queue->front);
}

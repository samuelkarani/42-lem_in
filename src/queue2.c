/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 01:10:12 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/13 20:52:20 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*next_queue(t_queue *queue)
{
	t_node	*node;
	int		i;

	if ((node = queue->front))
	{
		i = -1;
		while (++i < queue->idx)
			node = node->next;
		queue->idx++;
	}
	return (node ? node->room : NULL);
}

t_room	*next_queue_unvisited(t_queue *queue)
{
	t_room	*room;

	room = NULL;
	if (queue->front)
		while ((room = next_queue(queue)) && room->visited)
			;
	return (room);
}

void	reset_queue(t_queue *queue)
{
	queue->idx = 0;
}

int		delete_queue(t_queue **queue, t_room *room)
{
	t_node	*node;
	t_node	*prev;

	if ((node = (*queue)->front))
	{
		prev = NULL;
		while (node)
		{
			if (node->room == room)
			{
				if (prev)
					prev->next = node->next;
				else
					(*queue)->front = node->next;
				node == (*queue)->back ? (*queue)->back = prev : NOP();
				(*queue)->idx ? (*queue)->idx-- : NOP();
				(*queue)->size--;
				free(node);
				return (1);
			}
			prev = node;
			node = node->next;
		}
	}
	return (0);
}

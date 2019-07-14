/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 20:47:03 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/13 20:47:17 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		contains_queue(t_queue *queue, t_room *room)
{
	t_node	*node;

	if ((node = queue->front))
	{
		while (node)
		{
			if (node->room == room)
				return (1);
			node = node->next;
		}
	}
	return (0);
}

void	swap(t_node *a, t_node *b)
{
	t_room	*room;
	int		key;

	room = a->room;
	key = a->key;
	a->key = b->key;
	a->room = b->room;
	b->key = key;
	b->room = room;
}

void	sort_queue(t_queue *queue)
{
	t_node			*node;
	t_node			*i;
	t_node			*j;

	if ((node = queue->front))
	{
		i = node;
		while (i->next)
		{
			j = node;
			while (j->next)
			{
				if (j->room->n > j->next->room->n)
					swap(j, j->next);
				j = j->next;
			}
			i = i->next;
		}
	}
}

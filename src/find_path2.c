/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:44:48 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/13 19:55:16 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	direct_to_start2(t_hash *hash, t_room *neighbor)
{
	t_room	*next;

	while (!neighbor->is_start)
	{
		next = neighbor;
		neighbor = neighbor->prev;
		delete_queue(&next->neighbors, neighbor);
		if (!neighbor->is_start)
		{
			delete_except(neighbor, neighbor->prev, next);
			hash_insert(hash, neighbor);
		}
	}
}

void	delete_to_start(t_hash *hash, t_room *neighbor)
{
	t_room	*next;

	while (!neighbor->is_start)
	{
		next = neighbor;
		neighbor = neighbor->prev;
		if (!hash_find(hash, next->name))
			delete_queue(&neighbor->neighbors, next);
	}
}

void	delete_except(t_room *room, t_room *prev, t_room *next)
{
	t_node	*node;
	t_room	*neighbor;
	int		n;
	int		i;

	n = room->neighbors->size;
	i = -1;
	if (!contains_queue(prev->neighbors, room))
		enqueue(prev->neighbors, room);
	while (++i < n)
	{
		if ((node = room->neighbors->front))
		{
			while (node)
			{
				neighbor = node->room;
				if (neighbor != prev && neighbor != next)
					delete_queue(&room->neighbors, neighbor);
				node = node->next;
			}
		}
	}
}

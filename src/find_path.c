/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:36:34 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/13 19:54:39 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	direct_to_start(t_hash *hash, t_room *neighbor)
{
	t_room	*next;
	t_room	*p;
	int		n;

	p = neighbor;
	n = 0;
	while (!neighbor->is_start)
	{
		next = neighbor;
		neighbor = neighbor->prev;
		if (hash_find(hash, neighbor->name))
			return ;
		if (!neighbor->is_start)
			neighbor->n = ++n;
	}
	direct_to_start2(hash, p);
}

int		traverse(t_hash *hash, t_queue *queue, t_room *room)
{
	t_room	*neighbor;
	int		i;

	i = 0;
	while ((neighbor = next_queue_unvisited(room->neighbors)))
	{
		if (hash_find(hash, neighbor->name))
			delete_to_start(hash, neighbor);
		else
		{
			neighbor->prev = room;
			if (neighbor->is_end)
				direct_to_start(hash, neighbor);
			else
			{
				neighbor->visited = 1;
				enqueue(queue, neighbor);
			}
		}
		i++;
	}
	return (i);
}

void	unique_paths(t_room *start)
{
	t_hash	*hash;
	t_queue	*queue;
	t_room	*room;

	hash = init_hash(CAPACITY);
	queue = init_queue();
	start->visited = 1;
	enqueue(queue, start);
	while (!isempty_queue(queue))
	{
		room = dequeue(queue);
		if (!traverse(hash, queue, room))
			delete_to_start(hash, room);
		reset_queue(room->neighbors);
	}
	free_hash(hash, 0);
	free_queue(queue);
}

void	handle_start(t_hash *hash, t_queue *queue)
{
	t_room	*start;
	t_room	*next;
	int		n;
	int		i;

	start = hash->start;
	n = start->ants->size < start->neighbors->size
		? start->ants->size : start->neighbors->size;
	i = 0;
	sort_queue(start->neighbors);
	while (i < n)
	{
		next = next_queue(start->neighbors);
		print_move(move_ants(start, next), next->name, i);
		if (!next->is_end)
			enqueue(queue, next);
		i++;
	}
	!n ? exit_error("no path to end") : NOP();
	FP("\n");
	if (!isempty_ants(start->ants))
	{
		reset_queue(start->neighbors);
		enqueue(queue, start);
	}
}

void	algo(t_hash *hash)
{
	t_room	*room;
	t_room	*next;
	t_queue	*queue;
	int		i;
	int		n;

	queue = init_queue();
	unique_paths(hash->start);
	handle_start(hash, queue);
	while (!isempty_queue(queue))
	{
		i = -1;
		n = queue->size;
		while (++i < n)
		{
			room = dequeue(queue);
			next = next_queue(room->neighbors);
			print_move(move_ants(room, next), next->name, i);
			!next->is_end ? enqueue(queue, next) : NOP();
			!isempty_ants(room->ants) ? enqueue(queue, room) : NOP();
			reset_queue(room->neighbors);
		}
		FP("\n");
	}
	free_queue(queue);
}

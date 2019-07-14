/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:29 by hnam              #+#    #+#             */
/*   Updated: 2019/07/13 20:54:49 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		initialize_data(t_hash *hash)
{
	char	*line;
	int		a;
	int		n;

	a = -1;
	line = NULL;
	while ((n = get_next_line(STDIN_FILENO, &line) > 0))
	{
		if (!ft_strncmp(line, "##", 2))
			check_start_end(hash, &line);
		else if (*line == '#')
			NOP();
		else if (a == -1)
			a = check_ants(line);
		else if (check_room_n(line) && ft_strchr(line, ' '))
			check_room(hash, line, 0, 0);
		else if (check_room_n(line) && ft_strchr(line, '-'))
			check_link(hash, line);
		else
			exit_error("non-compliant line or empty line");
		free(line);
	}
	final_checks(hash, n);
	return (a);
}

t_room	*init_room(t_file_room f_room)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	room->name = f_room.name;
	room->point.x = f_room.x;
	room->point.y = f_room.y;
	room->is_start = f_room.is_start;
	room->is_end = f_room.is_end;
	room->prev = NULL;
	room->n = 0;
	room->visited = 0;
	room->neighbors = init_queue();
	room->ants = init_ants();
	return (room);
}

void	add_room(t_hash *hash, t_file_room f_room)
{
	t_room	*room;

	room = init_room(f_room);
	hash_insert(hash, room);
	if (f_room.is_start)
	{
		if (hash->start)
			exit_error("cannot have multiple starts");
		hash->start = room;
	}
	if (f_room.is_end)
	{
		if (hash->end)
			exit_error("cannot have multiple ends");
		hash->end = room;
	}
}

void	add_neighbor(t_hash *hash, t_file_link f_link)
{
	t_room	*room;
	t_room	*neighbor;

	room = hash_find(hash, f_link.a);
	neighbor = hash_find(hash, f_link.b);
	if (!room || !neighbor || room == neighbor)
		exit_error("error adding link");
	enqueue_neighbor(room, neighbor);
}

void	enqueue_neighbor(t_room *room, t_room *neighbor)
{
	t_node	*tmp;

	tmp = room->neighbors->front;
	while (tmp)
	{
		if (tmp->room == neighbor)
			return ;
		tmp = tmp->next;
	}
	enqueue(room->neighbors, neighbor);
	tmp = neighbor->neighbors->front;
	while (tmp)
	{
		if (tmp->room == room)
			return ;
		tmp = tmp->next;
	}
	enqueue(neighbor->neighbors, room);
}

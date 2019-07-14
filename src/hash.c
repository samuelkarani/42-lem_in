/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:23 by hnam              #+#    #+#             */
/*   Updated: 2019/07/13 20:35:50 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_hash	*init_hash(int capacity)
{
	t_hash	*hash;
	int		i;

	hash = malloc(sizeof(t_hash));
	if (!(hash->n = (t_node **)malloc(sizeof(t_node *) * capacity)))
		return (NULL);
	i = 0;
	while (i < capacity)
		hash->n[i++] = NULL;
	hash->capacity = capacity;
	hash->size = 0;
	hash->start = NULL;
	hash->end = NULL;
	return (hash);
}

int		get_hash(char *key, int capacity)
{
	int	res;
	int	i;

	res = 0;
	i = -1;
	while (key[++i])
		res += key[i];
	res += ft_strlen(key);
	return (res % capacity);
}

void	hash_insert(t_hash *hash, t_room *room)
{
	t_node	*node;
	t_node	*tmp;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return ;
	node->key = get_hash(room->name, hash->capacity);
	node->room = room;
	node->next = NULL;
	if (!hash->n[node->key])
		hash->n[node->key] = node;
	else
	{
		tmp = hash->n[node->key];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	hash->size++;
}

t_room	*hash_find(t_hash *hash, char *name)
{
	int		k;
	t_node	*node;

	k = get_hash(name, hash->capacity);
	if (!(node = hash->n[k]))
		return (NULL);
	if (!ft_strcmp(node->room->name, name))
		return (node->room);
	while ((node = node->next))
		if (!ft_strcmp(node->room->name, name))
			return (node->room);
	return (NULL);
}

void	free_hash(t_hash *hash, int r)
{
	int		i;
	t_node	*tmp;
	t_node	*node;

	i = -1;
	while (++i < hash->capacity)
	{
		node = hash->n[i];
		while (node)
		{
			if (r)
			{
				free(node->room->name);
				free_ants(node->room->ants);
				free_queue(node->room->neighbors);
				free(node->room);
			}
			tmp = node;
			node = node->next;
			free(tmp);
		}
	}
	free(hash->n);
	free(hash);
}

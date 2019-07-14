/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:56:44 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/13 19:56:18 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ants	*init_ants(void)
{
	t_ants	*ants;

	ants = malloc(sizeof(t_ants));
	ants->front = NULL;
	ants->back = NULL;
	ants->size = 0;
	return (ants);
}

void	add_ants(t_ants *ants, int no)
{
	t_ant	*ant;

	ant = malloc(sizeof(t_ant));
	ant->no = no;
	ant->next = NULL;
	if (!ants->front)
	{
		ants->front = ant;
		ants->back = ant;
	}
	else
	{
		ants->back->next = ant;
		ants->back = ant;
	}
	ants->size++;
}

int		remove_ants(t_ants *ants)
{
	t_ant	*ant;
	int		no;

	if (!ants->front)
		return (0);
	ant = ants->front;
	ants->front = ant->next;
	if (!ants->front)
		ants->back = NULL;
	no = ant->no;
	free(ant);
	ants->size--;
	return (no);
}

void	free_ants(t_ants *ants)
{
	t_ant	*ant;
	t_ant	*tmp;

	if ((ant = ants->front))
	{
		while (ant)
		{
			tmp = ant;
			ant = ant->next;
			free(tmp);
		}
	}
	free(ants);
}

int		isempty_ants(t_ants *ants)
{
	return (!ants->front);
}

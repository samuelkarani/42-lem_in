/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:55:51 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/13 19:56:30 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_ants(t_ants *ants, int n)
{
	int	i;

	i = 0;
	while (++i <= n)
		add_ants(ants, i);
}

int		move_ants(t_room *from, t_room *to)
{
	int no;

	no = remove_ants(from->ants);
	add_ants(to->ants, no);
	return (no);
}

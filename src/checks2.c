/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 20:30:25 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/13 20:55:01 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_room_n(char *name)
{
	return (*name != '#' && *name != 'L');
}

int		check_no(char *no)
{
	while (*no)
	{
		if (!ft_isdigit(*no))
			return (0);
		no++;
	}
	return (1);
}

void	final_checks(t_hash *hash, int n)
{
	if (n == -1)
		exit_error("error reading file");
	check_hash(hash);
}

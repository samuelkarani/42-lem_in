/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:42:11 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/13 20:49:55 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_strings(char **info)
{
	int	i;

	i = -1;
	while (info[++i])
		free(info[i]);
	free(info);
}

void	exit_error(char *msg)
{
	FP("ERROR: %s\n", msg);
	exit(1);
}

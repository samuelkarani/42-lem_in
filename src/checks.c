/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:22:21 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/13 20:32:41 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_ants(char *line)
{
	int n;

	if (!check_no(line))
		exit_error("ants not a number");
	n = ft_atoi(line);
	if (n <= 0)
		exit_error("no ants cannot zero or be negative");
	if (n > CAPACITY)
		exit_error("ants greater than capacity");
	return (n);
}

void	check_start_end(t_hash *hash, char **line)
{
	int	s;

	if ((s = !ft_strcmp(*line, "##start")) || !ft_strcmp(*line, "##end"))
	{
		free(*line);
		if (get_next_line(STDIN_FILENO, line) > 0)
			s ? check_room(hash, *line, 1, 0) : check_room(hash, *line, 0, 1);
		else
			exit_error("error processing start/end command");
	}
}

void	check_room(t_hash *hash, char *line, int is_start, int is_end)
{
	t_file_room	ret;
	char		**info;
	int			x;
	int			y;
	char		*name;

	info = ft_strsplit(line, ' ');
	if (!info || !info[0] || !info[1] || !info[2])
		exit_error("could not process room");
	if (!check_no(info[1]) || !check_no(info[2]))
		exit_error("x or y is not a number");
	name = ft_strdup(info[0]);
	x = ft_atoi(info[1]);
	y = ft_atoi(info[2]);
	if (!name || !*name || !check_room_n(name))
		exit_error("room name is invalid");
	if (x < 0)
		exit_error("x cannot be negative");
	if (y < 0)
		exit_error("y cannot be negative");
	ret = (t_file_room){name, x, y, is_start, is_end};
	add_room(hash, ret);
	free_strings(info);
}

void	check_link(t_hash *hash, char *line)
{
	t_file_link	ret;
	char		**names;

	names = ft_strsplit(line, '-');
	if (!names || !names[0] || !names[1])
		exit_error("could not process link");
	if (!check_room_n(names[0]) || !check_room_n(names[1]))
		exit_error("invalid room name(s) in link");
	ret = (t_file_link){names[0], names[1]};
	add_neighbor(hash, ret);
	free_strings(names);
}

void	check_hash(t_hash *hash)
{
	if (!hash->size)
		exit_error("invalid file or no rooms were found");
	if (!hash->start)
		exit_error("start room not found");
	if (!hash->end)
		exit_error("end room not found");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/07/13 21:23:31 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

# define CAPACITY 42000
# define NOP() ({;})

typedef	struct		s_file_room
{
	char			*name;
	int				x;
	int				y;
	int				is_start;
	int				is_end;
}					t_file_room;

typedef	struct		s_file_link
{
	char			*a;
	char			*b;
}					t_file_link;

typedef struct		s_ant
{
	struct s_ant	*next;
	int				no;
}					t_ant;

typedef struct		s_ants
{
	t_ant			*front;
	t_ant			*back;
	int				size;
}					t_ants;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_room
{
	char			*name;
	t_point			point;
	int				is_start;
	int				is_end;
	int				n;
	int				visited;
	struct s_room	*prev;
	struct s_ants	*ants;
	struct s_queue	*neighbors;
}					t_room;

typedef struct		s_node
{
	int				key;
	t_room			*room;
	struct s_node	*next;
}					t_node;

typedef struct		s_hash
{
	t_node			**n;
	t_room			*start;
	t_room			*end;
	int				size;
	int				capacity;
}					t_hash;

typedef struct		s_queue
{
	int				size;
	int				idx;
	t_node			*front;
	t_node			*back;
}					t_queue;

t_ants				*init_ants(void);
void				add_ants(t_ants *ants, int no);
int					remove_ants(t_ants *ants);
void				free_ants(t_ants *ants);
int					isempty_ants(t_ants *ants);
void				start_ants(t_ants *ants, int n);
int					move_ants(t_room *from, t_room *to);

t_room				*init_room(t_file_room f_room);
int					initialize_data(t_hash *hash);
void				add_room(t_hash *hash, t_file_room f_room);
void				add_neighbor(t_hash *hash, t_file_link f_link);
void				enqueue_neighbor(t_room *room, t_room *neighbor);

t_queue				*init_queue(void);
void				enqueue(t_queue *queue, t_room *room);
t_room				*dequeue(t_queue *queue);
void				free_queue(t_queue *queue);
int					isempty_queue(t_queue *queue);
int					delete_queue(t_queue **queue, t_room *room);
t_room				*next_queue(t_queue *queue);
t_room				*next_queue_unvisited(t_queue *queue);
void				reset_queue(t_queue *queue);
void				swap(t_node *a, t_node *b);
void				sort_queue(t_queue *queue);
int					contains_queue(t_queue *queue, t_room *room);

t_hash				*init_hash(int capacity);
int					get_hash(char *key, int capacity);
void				hash_insert(t_hash *hash, t_room *room);
t_room				*hash_find(t_hash *hash, char *key);
void				free_hash(t_hash *hash, int r);

void				print_move(int no, char *dst, int i);
void				print_entry(t_room *room);
void				print_rooms(t_hash *hash);
void				print_neighbors(t_hash *visited, t_node *n);
void				print_links(t_hash *hash);

void				exit_error(char *msg);
void				free_strings(char **info);

int					check_room_n(char *name);
int					check_no(char *no);
int					check_ants(char *line);
void				check_start_end(t_hash *hash, char **line);
void				check_room(t_hash *hash, char *line, int s, int e);
void				check_link(t_hash *hash, char *line);
void				check_hash(t_hash *hash);
void				final_checks(t_hash *hash, int n);

void				direct_to_start(t_hash *hash, t_room *neighbor);
int					traverse(t_hash *hash, t_queue *queue, t_room *room);
void				unique_paths(t_room *start);
void				handle_start(t_hash *hash, t_queue *queue);
void				algo(t_hash *hash);
void				direct_to_start2(t_hash *hash, t_room *neighbor);
void				delete_to_start(t_hash *hash, t_room *neighbor);
void				delete_except(t_room *room, t_room *prev, t_room *next);

#endif

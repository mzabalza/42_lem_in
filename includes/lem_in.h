/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:08:06 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/17 13:08:35 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"
#include "../includes/get_next_line.h"

/*
** pos 2 end
** pos 0 other
*/

typedef struct 		s_node
{
	char			*id;
	int				x;
	int				y;
	int				pos;
	int 			*occupied;
	int 			*passed;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct 		s_glist
{
	t_node			*head;
	t_node			*tail;
	struct s_glist 	*next;
	struct s_glist 	*prev;
}					t_glist;

typedef struct 		s_adjlist
{
	int 			st_end;
	int				nb_room;
	int				nb_ant;
	t_glist			*start;
	t_glist			*end;
}					t_adjlist;

typedef struct  	s_path
{
	char			*id;
	int 			total_cost; //quitar
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;

typedef struct  	s_gpath
{
	t_path			*path_head;
	int 			nb_nodes; //quitar
	struct s_path	*next;
	struct s_path	*prev;
}					t_gpath;


typedef struct 		s_prev
{
	char			*current;
	char			*previous;
	struct s_prev	*next;
	struct s_prev	*prev;
}					t_prev;

typedef struct 		s_stack
{
	t_glist			*glist;
	struct s_stack	*next;
}					t_stack;

int 			main();
int				goto_alist(char *tab0, char *tab1, t_glist *tmp_list, t_adjlist *alist);
t_glist 		*pointer_2_glist(char *id_room, t_glist *tmp_glist);
t_glist			*find_start(t_glist *glist);

/*
**----------  PARSING + MAP GENERATION  ---------------------------------------
*/
int 			get_data(t_adjlist *adjlist);
int				get_nb_ants();
int				line_type(char *line, char c);
int				get_nb_ants();
void			skip_comment(char *line);
int 			is_integer(char *str);
t_adjlist		*init_adjlist();
t_node 			*init_node();
void			add_glist(t_node *node, t_adjlist *alist);
void			add_node(char *room, t_glist *list, t_adjlist *alist);
int				add_connection(char *line, t_adjlist *alist);

/*
**----------GRAPH SEARCH ALGO--------------------------------------------------
*/

t_prev			*breath_first_search(t_glist *glist_start);
void			add_2_queue(t_stack **queue_tail, t_glist *glist);
int				rm_from_queue(t_stack **queue_head);
void 			add_2_prev(t_prev **prev, char *current, char *previous);
t_prev			*find_previous(char *id, t_prev *tail);
t_path			*create_path(t_prev *reverse_path);
void			reset_map(t_glist *glist_start, t_path **path);
t_path			*add_node_2_path(char *id, t_path *path);
char			*find_free_node(t_node *node);
t_path			*init_path(char *start);
t_path			*rm_node_from_path(t_path *path);

/*
**----------  SHOW   --------------------------------------------------
*/

void			print_graph(t_adjlist *adjlist);
void			show_path(t_path *path);
void			show_nodes(t_node *node);
void			show_prev_list(t_prev *prev_list);
void			show_queue(t_stack *queue_head);
void			show_answer(t_path **all_paths, t_adjlist *alist, int nb_path);



#endif

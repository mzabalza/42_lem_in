/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:17:30 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/18 21:34:30 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			show_nodes(t_node *node)
{
	int i;

	i = 1;
	ft_putendl("******");
	while (node)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putstr(node->id);
		ft_putchar(' ');
		ft_putnbr(*(node->passed));
		ft_putchar('\n');
		node = node->next;
		i++;
	}
	ft_putendl("******");
}

void			show_gpaths(t_gpath *gpath)
{
	while (gpath)
	{
		ft_putstr("nb of nodes: ");
		ft_putnbr(gpath->nb_nodes);
		ft_putstr("nb of ants: ");
		ft_putnbr(gpath->nb_ants);
		ft_putchar('\n');
		show_path(gpath->path_head);
		gpath = gpath->next;
	}
}

void			show_path(t_path *path)
{
	ft_putendl("------");
	while (path)
	{
		ft_putnbr(path->ant);
		ft_putchar(' ');
		ft_putendl(path->id);
		path = path->next;
	}
	ft_putendl("------");
}

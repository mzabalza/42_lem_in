/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:17:30 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/11 12:17:35 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			show_nodes(t_node *node)
{
	int i;

	i = 1;
	ft_putendl("******");
	while(node)
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

void			show_path(t_path *path)
{
	ft_putendl("------");
	while(path)
	{
		ft_putnbr(path->total_cost);
		ft_putchar(' ');
		ft_putendl(path->id);
		path = path->next;
	}
	ft_putendl("------");
}
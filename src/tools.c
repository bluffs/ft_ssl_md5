/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:04:50 by jyakdi            #+#    #+#             */
/*   Updated: 2019/09/06 16:47:05 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"

//TODO return t_elem in case begin is NULL
void		ft_readFile(char* file, t_elem *begin)
{
	//read file with GNL and create elem with the full content of the file
	t_elem	*tmp;

	tmp = begin;
	ft_putstr("gonna read file : ");
	ft_putendl(file);
}

void		ft_do_cmd(int argc, char **argv)
{
	if (ft_strcmp(argv[1], "md5") == 0)
	{
		md5(argc, argv);
		//ft_putendl("gonna hash with md5");
	}
	else
	{
		ft_error_cmd(argv[1]);
	}
}

t_elem*		ft_create_elem(char *str, t_elem *begin)
{
	t_elem	*elem;
	t_elem	*tmp;

	tmp = begin;
	if (!(elem = ft_memalloc(sizeof(t_elem))))
		return (NULL);
	elem->str = str;
	if (!tmp)
		return (elem);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (begin);
}

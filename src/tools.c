/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:04:50 by jyakdi            #+#    #+#             */
/*   Updated: 2019/09/07 15:40:50 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_elem		*ft_readFile(char* file, t_elem *begin)
{
	//read file with GNL and create elem with the full content of the file
	char		*str;
	int			fd;
	char		*str2;
	char		*str3;

	str3 = NULL;
	if ((fd = open(file, O_RDONLY)) <= 0)
		return (NULL);
	while (get_next_line(fd, &str) > 0)
	{
		str2 = str3;
		if (str2)
		{
			str3 = ft_strjoin(str2, "\n");
			ft_strdel(&str2);
			str2 = str3;
		}
		str3 = ft_strjoin(str2, str);
		if (str2)
			ft_strdel(&str2);
	}
	if (str)
		ft_strdel(&str);
	return (ft_create_elem(str3, begin));
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

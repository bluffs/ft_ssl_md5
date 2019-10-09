/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:04:50 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/09 17:06:58 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int			ft_read_file(char *file, char **finalstr)
{
	char		*str;
	int			fd;
	char		*str2;
	char		*str3;

	str3 = NULL;
	str2 = NULL;
	if (!(str = ft_memalloc(2)))
		exit(0);
	if ((fd = open(file, O_RDONLY)) <= 0)
	{
		ft_no_file(file);
		return (0);
	}
	while (read(fd, str, 1) > 0)
	{
		str2 = str3;
		str3 = ft_strjoin(str2, str);
		if (str2)
			ft_strdel(&str2);
	}
	ft_strdel(&str);
	if (str2)
		ft_strdel(&str2);
	*finalstr = str3;
	return (1);
}

void		ft_do_cmd(int argc, char **argv)
{
	if (ft_strcmp(argv[1], "md5") == 0)
	{
		md5(argc, argv);
	}
	else
	{
		ft_error_cmd(argv[1]);
	}
}

t_elem		*ft_create_elem(char *str, t_elem *begin)
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

char		ft_itoh(unsigned int nb)
{
	char *str;

	str = "0123456789abcdef";
	return (str[nb]);
}

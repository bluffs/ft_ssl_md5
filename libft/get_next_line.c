/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:37:35 by jyakdi            #+#    #+#             */
/*   Updated: 2019/09/07 15:37:37 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** On verifie si ce fd a des restes d'un appel precedent a gnl
*/

static char		**check_fd(int fd, t_rest **save)
{
	t_rest	*tmp;

	if (!save)
		save = (t_rest**)malloc(sizeof(t_rest*));
	else
	{
		tmp = (*save);
		while (tmp)
		{
			if (tmp->fd == fd)
				return (&tmp->restes);
			tmp = tmp->next;
		}
	}
	tmp = (t_rest*)malloc(sizeof(t_rest));
	tmp->restes = ft_strnew(1);
	tmp->fd = fd;
	tmp->next = *save;
	*save = tmp;
	return (&tmp->restes);
}

/*
** On fait un read sur le fd qu'on stock dans les restes correspondant au fd
*/

static int		read_fd(int fd, char **restes, char *line)
{
	int		i;
	int		n;
	short	stop;
	char	*tmp;

	stop = 0;
	n = 0;
	line = (char*)ft_strnew(BUFF_SIZE);
	while (stop == 0 && (n = read(fd, line, BUFF_SIZE)))
	{
		i = 0;
		while (n--)
		{
			if (line[i] == '\n' || line[i] == '\0')
				stop = 1;
			i++;
		}
		line[i] = '\0';
		tmp = *restes;
		*restes = ft_strjoin(*restes, line);
		free(tmp);
	}
	free(line);
	return (n);
}

/*
** On check d'abord si ce fd est deja stock et si oui est-ce qu'il a un \n
** Sinon on cree les restes pour ce fd issus de reads jusqu'au 1er \n
** VAR : inc = compteurs read, lenLine, s = tab de restesDesFD, rest = restFD
*/

int				get_next_line(const int fd, char **line)
{
	int					i;
	int					n;
	static t_rest		*s;
	char				*tmp;
	char				**rest;

	if (fd < 0 || line == NULL || read(fd, *line, 0) < 0)
		return (-1);
	rest = check_fd(fd, &s);
	if (ft_strchr(*rest, '\n') == NULL)
	{
		i = read_fd(fd, rest, *line);
		if (i == 0 && ft_strlen(*rest) == 0)
			return (0);
	}
	if (ft_strchr(*rest, '\n') != NULL)
		n = (int)(ft_strchr(*rest, '\n') - *rest);
	else
		n = ft_strlen(*rest);
	*line = ft_strsub(*rest, 0, n);
	tmp = *rest;
	*rest = ft_strsub(*rest, n + 1, ft_strlen(*rest) - ft_strlen(*line));
	free(tmp);
	return (1);
}

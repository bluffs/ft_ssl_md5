/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_md5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:47:12 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/29 13:22:17 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <stdlib.h>

void	ft_print_file_md5(char *str, char *hash, int flag)
{
	if (flag == 0)
	{
		ft_putstr("MD5 (");
		ft_putstr(str);
		ft_putstr(") = ");
		ft_putendl(hash);
	}
	else if (flag == 1)
	{
		ft_putstr(hash);
		ft_putstr(" ");
		ft_putstr(str);
		ft_putendl("");
	}
	else
		ft_putendl(hash);
	if (hash != NULL)
		free(hash);
}

void	ft_print_md5(char *str, char *hash, int flag)
{
	if (flag == 0)
	{
		ft_putstr("MD5 (\"");
		ft_putstr(str);
		ft_putstr("\") = ");
		ft_putendl(hash);
	}
	else if (flag == 1)
	{
		ft_putstr(hash);
		ft_putstr(" \"");
		ft_putstr(str);
		ft_putendl("\"");
	}
	else if (flag == 3)
	{
		ft_putstr(str);
		ft_putendl(hash);
	}
	else
		ft_putendl(hash);
	if (hash != NULL)
		free(hash);
}

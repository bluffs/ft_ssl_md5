/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:01:25 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/09 16:01:00 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <stdlib.h>
#include <stdio.h>

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
	else
		ft_putendl(hash);
}

int		ft_flag_check(char **argv, int i, int *p_flag, int *qr_flag)
{
	int		n;

	n = 1;
	while (argv[i][n])
	{
		if (argv[i][n] == 'p')
			(*p_flag)++;
		else if (argv[i][n] == 'q')
			*qr_flag = 2;
		else if (argv[i][n] == 'r')
			*qr_flag = (*qr_flag != 2) ? 1 : 2;
		else if (argv[i][n] == 's')
		{
			if (argv[i][n + 1] != 0)
			{
				ft_print_md5(&argv[i][n + 1], ft_hash_md5(&argv[i][n + 1], 0, 0), *qr_flag);
				return (0);
			}
			else
				return (1);
		}
		else
		{
			ft_usage(argv[i][n]);
			exit(0);
		}
		n++;
	}
	return (0);
}

void	md5(int argc, char **argv)
{
	int	i;
	int	p_flag;
	int	qr_flag;
	int	files;

	files = 0;
	p_flag = 0;
	qr_flag = 0;
	i = 1;
	while (++i < argc)
	{
		if (files == 0 && argv[i][0] == '-')
		{
			if (ft_flag_check(argv, i, &p_flag, &qr_flag) == 1)
			{
				if (i + 1 < argc)
				{
					i++;
					ft_print_md5(argv[i], ft_hash_md5(argv[i], 0, 0), qr_flag);
				}
			}
		}
		else
		{
			files = 1;
			if (ft_read_file(argv[i], &argv[0]) == 1)
				ft_print_file_md5(argv[i], ft_hash_md5(argv[0], 0, 0), qr_flag);
		}
	}
}

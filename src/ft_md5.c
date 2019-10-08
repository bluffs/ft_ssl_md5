/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:01:25 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/08 18:23:48 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"

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

void	md5(int argc, char **argv)
{
	int	i;
	int	p_flag;
	int	qr_flag;
	int	files;

	files = 0;
	p_flag = 0;
	qr_flag = 0;
	i = 2;
	while (i < argc)
	{
		if (files == 0 && ft_strcmp(argv[i], "-p") == 0)
			p_flag++;
		else if (files == 0 && ft_strcmp(argv[i], "-q") == 0)
			qr_flag = 2;
		else if (files == 0 && ft_strcmp(argv[i], "-r") == 0)
			qr_flag = (qr_flag != 2) ? 1 : 2;
		else if (files == 0 && ft_strcmp(argv[i], "-s") == 0)
		{
			if (i + 1 < argc)
			{
				i++;
				ft_print_md5(argv[i], ft_hash_md5(argv[i], 0, 0), qr_flag);
			}
			else
				ft_usage();
		}
		else
		{
			files = 1;
			//TODO not working
			ft_print_md5(argv[i], ft_hash_md5(ft_read_file(argv[i]), 0, 0), qr_flag);
		}
		i++;
	}
}

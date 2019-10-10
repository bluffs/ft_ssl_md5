/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:01:25 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/10 19:16:39 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <stdlib.h>

int		ft_flag(char c, int *p_flag, int *qr_flag)
{
	if (c == 'p')
	{
		(*p_flag)++;
		return (1);
	}
	else if (c == 'q')
	{
		*qr_flag = 2;
		return (1);
	}
	else if (c == 'r')
	{
		*qr_flag = (*qr_flag != 2) ? 1 : 2;
		return (1);
	}
	return (0);
}

void	ft_do_stdin(char c, int nb)
{
	char	*str;

	if (c == 'p' && nb == 1)
	{
		ft_read_file(NULL, &str, NULL, 0);
		ft_print_md5(str, ft_hash_md5(str, 0, 0), 3);
	}
	else if (c == 'p' && nb == 0)
	{
		ft_read_file(NULL, &str, NULL, 0);
		ft_print_md5(str, ft_hash_md5(str, 0, 0), 4);
	}
}

int		ft_flag_check(char **argv, int i, int *p_flag, int *qr_flag)
{
	int		n;

	n = 0;
	while (argv[i][++n])
	{
		if (ft_flag(argv[i][n], p_flag, qr_flag))
			ft_do_stdin(argv[i][n], 1);
		else if (argv[i][n] == 's')
		{
			if (argv[i][n + 1] != 0)
			{
				ft_print_md5(&argv[i][n + 1], ft_hash_md5(&argv[i][n + 1],
							0, 0), *qr_flag);
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
	}
	return (0);
}

int		ft_do_string(int argc, int *i, char **argv, int qr_flag)
{
	if (*i + 1 < argc)
	{
		(*i)++;
		ft_print_md5(argv[*i], ft_hash_md5(argv[*i], 0, 0), qr_flag);
		return (1);
	}
	else
	{
		ft_usage(0);
		return (0);
	}
}

void	md5(int argc, char **argv, int i, int files)
{
	int	p_flag;
	int	qr_flag;
	int	tmp;

	p_flag = 0;
	qr_flag = 0;
	while (++i < argc)
	{
		if (files == 0 && argv[i][0] == '-')
		{
			tmp = ft_flag_check(argv, i, &p_flag, &qr_flag);
			if (tmp == 1)
				p_flag += ft_do_string(argc, &i, argv, qr_flag);
		}
		else
		{
			files = 1;
			if (ft_read_file(argv[i], &argv[0], NULL, 1) == 1)
				ft_print_file_md5(argv[i], ft_hash_md5(argv[0], 0, 0), qr_flag);
		}
	}
	if (p_flag == 0 && files == 0)
		ft_do_stdin('p', 0);
}

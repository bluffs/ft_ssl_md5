/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:42:37 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/29 13:48:49 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <stdlib.h>

void	ft_do_stdin_sha256(char c, int nb)
{
	char	*str;

	if (c == 'p' && nb == 1)
	{
		ft_read_file(NULL, &str, NULL, 0);
		ft_print_sha256(str, ft_hash_sha256(str, 0, 0), 3);
	}
	else if (c == 'p' && nb == 0)
	{
		ft_read_file(NULL, &str, NULL, 0);
		ft_print_sha256(str, ft_hash_sha256(str, 0, 0), 4);
	}
}

int		ft_flag_check_sha256(char **argv, int i, int *p_flag, int *qr_flag)
{
	int		n;

	n = 0;
	while (argv[i][++n])
	{
		if (ft_flag(argv[i][n], p_flag, qr_flag))
			ft_do_stdin_sha256(argv[i][n], 1);
		else if (argv[i][n] == 's')
		{
			if (argv[i][n + 1] != 0)
			{
				ft_print_sha256(&argv[i][n + 1], ft_hash_sha256(&argv[i][n + 1],
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

int		ft_do_string_sha256(int argc, int *i, char **argv, int qr_flag)
{
	if (*i + 1 < argc)
	{
		(*i)++;
		ft_print_sha256(argv[*i], ft_hash_sha256(argv[*i], 0, 0), qr_flag);
		return (1);
	}
	else
	{
		ft_usage_sha256(0);
		return (0);
	}
}

void	sha256(int argc, char **argv, int i, int files)
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
			tmp = ft_flag_check_sha256(argv, i, &p_flag, &qr_flag);
			if (tmp == 1)
				p_flag += ft_do_string_sha256(argc, &i, argv, qr_flag);
		}
		else
		{
			files = 1;
			if (ft_read_file(argv[i], &argv[0], NULL, 1) == 1)
				ft_print_file_sha256(argv[i],
						ft_hash_sha256(argv[0], 0, 0), qr_flag);
		}
	}
	if (p_flag == 0 && files == 0)
		ft_do_stdin_sha256('p', 0);
}

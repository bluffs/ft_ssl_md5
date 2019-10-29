/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sha256.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:44:03 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/29 13:44:09 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <stdlib.h>

void	ft_sha_to_hex(unsigned int num, char *hash, int start)
{
	int				i;
	unsigned int	nb;

	i = 0;
	while (i < 4)
	{
		nb = (num >> (24 - 8 * i)) & 0xFF;
		hash[start + (i * 2)] = ft_itoh(nb / 16);
		hash[start + (i * 2) + 1] = ft_itoh(nb % 16);
		i++;
	}
}

void	ft_print_file_sha256(char *str, char *hash, int flag)
{
	if (flag == 0)
	{
		ft_putstr("sha256 (");
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
	if (hash)
		free(hash);
}

void	ft_print_sha256(char *str, char *hash, int flag)
{
	if (flag == 0)
	{
		ft_putstr("sha256 (\"");
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
	if (hash)
		free(hash);
}

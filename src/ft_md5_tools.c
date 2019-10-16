/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:22:46 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/15 18:50:17 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <stdlib.h>
#include <stdio.h>

int	g_var[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

void	ft_round(int i, int *f, int *g, t_var *tab)
{
	if (i < 16)
	{
		*f = (tab->b & tab->c) | ((~(tab->b)) & tab->d);
		*g = i;
	}
	else if (i < 32)
	{
		*f = (tab->d & tab->b) | (~(tab->d) & tab->c);
		*g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		*f = tab->b ^ tab->c ^ tab->d;
		*g = (3 * i + 5) % 16;
	}
	else
	{
		*f = tab->c ^ (tab->b | ~(tab->d));
		*g = (7 * i) % 16;
	}
}

void	ft_operate(t_var *tab, unsigned char *str)
{
	int				i;
	int				f;
	int				g;
	unsigned int	*test;
	unsigned int	x;

	x = 0;
	test = ft_chunk(str, tab);
	i = 0;
	while (i < 64)
	{
		ft_round(i, &f, &g, tab);
		x = (tab->a + f + test[g] + tab->k[i]);
		tab->a = tab->b + ((x << g_var[i]) | (x >> (32 - g_var[i])));
		x = tab->b;
		tab->b = tab->a;
		tab->a = tab->d;
		tab->d = tab->c;
		tab->c = x;
		i++;
	}
	tab->h0 = tab->h0 + tab->a;
	tab->h1 = tab->h1 + tab->b;
	tab->h2 = tab->h2 + tab->c;
	tab->h3 = tab->h3 + tab->d;
}

void	ft_reverse(unsigned int num, char *hash, int start)
{
	int				i;
	unsigned int	nb;

	i = 0;
	while (i < 4)
	{
		nb = (num >> 8 * i) & 0xFF;
		hash[start + (i * 2)] = ft_itoh(nb / 16);
		hash[start + (i * 2) + 1] = ft_itoh(nb % 16);
		i++;
	}
}

char	*ft_final_print(t_var *tab)
{
	char	*hash;

	if (!(hash = ft_memalloc(33)))
		exit(0);
	ft_reverse(tab->h0, hash, 0);
	ft_reverse(tab->h1, hash, 8);
	ft_reverse(tab->h2, hash, 16);
	ft_reverse(tab->h3, hash, 24);
	return (hash);
}

char	*ft_hash_md5(char *str, int i, int j)
{
	int				size;
	unsigned char	*tmp;
	t_var			tab;
	unsigned char	*str1;

	init_tab(&tab);
	str1 = ft_padding(str, &size);
	while (size - i > 0)
	{
		if (i != 0)
			free(tmp);
		if (!(tmp = ft_memalloc(65)))
			exit(0);
		j = 0;
		while (j < 64)
		{
			tmp[j] = str1[i + j];
			j++;
		}
		i += 64;
		ft_operate(&tab, tmp);
	}
	return (ft_final_print(&tab));
}

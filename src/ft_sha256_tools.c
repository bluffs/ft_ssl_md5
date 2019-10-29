/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:43:19 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/29 14:05:35 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/ssl.h"

void	ft_operate_sha256_2(t_256 *tab, int choice)
{
	if (choice == 1)
	{
		tab->h0 += tab->a;
		tab->h1 += tab->b;
		tab->h2 += tab->c;
		tab->h3 += tab->d;
		tab->h4 += tab->e;
		tab->h5 += tab->f;
		tab->h6 += tab->g;
		tab->h7 += tab->h;
	}
	else
	{
		tab->a = tab->h0;
		tab->b = tab->h1;
		tab->c = tab->h2;
		tab->d = tab->h3;
		tab->e = tab->h4;
		tab->f = tab->h5;
		tab->g = tab->h6;
		tab->h = tab->h7;
	}
}

void	ft_operate_sha256(t_256 *tab, unsigned char *str)
{
	int				i;

	i = -1;
	ft_operate_sha256_2(tab, 0);
	while (++i < 64)
	{
		tab->t1 = tab->h + ft_big_sigma_one(tab->e)
			+ ft_ch(tab->e, tab->f, tab->g) + tab->k[i]
			+ ft_get_unsigned(&str[i * 4]);
		tab->t2 = ft_big_sigma_zero(tab->a) + ft_maj(tab->a, tab->b, tab->c);
		tab->h = tab->g;
		tab->g = tab->f;
		tab->f = tab->e;
		tab->e = tab->d + tab->t1;
		tab->d = tab->c;
		tab->c = tab->b;
		tab->b = tab->a;
		tab->a = tab->t1 + tab->t2;
	}
	ft_operate_sha256_2(tab, 1);
}

char	*ft_final_print_256(t_256 *tab)
{
	char	*hash;

	if (!(hash = ft_memalloc(65)))
		exit(0);
	ft_sha_to_hex(tab->h0, hash, 0);
	ft_sha_to_hex(tab->h1, hash, 8);
	ft_sha_to_hex(tab->h2, hash, 16);
	ft_sha_to_hex(tab->h3, hash, 24);
	ft_sha_to_hex(tab->h4, hash, 32);
	ft_sha_to_hex(tab->h5, hash, 40);
	ft_sha_to_hex(tab->h6, hash, 48);
	ft_sha_to_hex(tab->h7, hash, 56);
	return (hash);
}

void	ft_init_msg(unsigned char *str)
{
	int				i;
	unsigned int	nb;

	i = 16;
	while (i < 64)
	{
		nb = ft_small_sigma_one(ft_get_unsigned(&str[(i - 2) * 4]));
		nb += ft_get_unsigned(&str[(i - 7) * 4]);
		nb += ft_small_sigma_zero(ft_get_unsigned(&str[(i - 15) * 4]));
		nb += ft_get_unsigned(&str[(i - 16) * 4]);
		ft_set_unsigned(&str[i * 4], nb);
		i++;
	}
}

char	*ft_hash_sha256(char *str, int i, int j)
{
	int				size;
	unsigned char	*tmp;
	t_256			tab;
	unsigned char	*str1;

	init_tab_sha256(&tab);
	str1 = ft_padding_sha256(str, &size);
	while (size - i > 0)
	{
		if (i != 0)
			free(tmp);
		if (!(tmp = ft_memalloc(65 * 4)))
			exit(0);
		j = -1;
		while (++j < 64 * 4)
			tmp[j] = str1[i + j];
		i += 16 * 4;
		ft_init_msg(tmp);
		ft_operate_sha256(&tab, tmp);
	}
	if (size != 0)
		free(tmp);
	if (size != 0)
		free(str1);
	return (ft_final_print_256(&tab));
}

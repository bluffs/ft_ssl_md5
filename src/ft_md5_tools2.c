/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:32:02 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/08 17:50:25 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <stdlib.h>

unsigned char		*ft_padding(char *str, int *size)
{
	unsigned char	*tmp;
	int				i;
	int				nb;
	int				len;

	len = ft_strlen(str);
	nb = 1;
	while (((len + nb) % 64) != 56)
		nb++;
	if (!(tmp = ft_memalloc(len + nb + 8)))
		exit(0);
	*size = len + nb + 8;
	i = -1;
	while (++i < len)
		tmp[i] = (unsigned char)(str[i]);
	tmp[i++] = 0b10000000;
	while (i < len + nb)
		tmp[i++] = 0;
	len *= 8;
	tmp[i++] = (len >> 0) & 0xFF;
	tmp[i++] = (len >> 8) & 0xFF;
	tmp[i++] = (len >> 16) & 0xFF;
	tmp[i++] = (len >> 24) & 0xFF;
	return (tmp);
}

unsigned int		*ft_chunk(unsigned char *str, t_var *tab)
{
	int				i;
	int				j;
	unsigned int	*test;

	test = ft_memalloc(sizeof(int) * 16);
	i = 0;
	while (i < 16)
	{
		j = 0;
		test[i] = 0;
		while (j < 4)
		{
			test[i] += str[i * 4 + j] << (j * 8);
			j++;
		}
		i++;
	}
	tab->a = tab->h0;
	tab->b = tab->h1;
	tab->c = tab->h2;
	tab->d = tab->h3;
	return (test);
}

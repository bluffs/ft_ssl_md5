/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:43:36 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/29 13:56:51 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <stdlib.h>

unsigned long		ft_strlong(char *str)
{
	unsigned long	len;

	len = 0;
	if (str == 0)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void				ft_padding_sha256_2(unsigned char *tmp, unsigned long i,
									unsigned long len)
{
	tmp[i++] = (len >> 56) & 0xFF;
	tmp[i++] = (len >> 48) & 0xFF;
	tmp[i++] = (len >> 40) & 0xFF;
	tmp[i++] = (len >> 32) & 0xFF;
	tmp[i++] = (len >> 24) & 0xFF;
	tmp[i++] = (len >> 16) & 0xFF;
	tmp[i++] = (len >> 8) & 0xFF;
	tmp[i++] = (len >> 0) & 0xFF;
}

unsigned char		*ft_padding_sha256(char *str, int *size)
{
	unsigned char	*tmp;
	unsigned long	i;
	unsigned long	nb;
	unsigned long	len;

	len = ft_strlong(str);
	nb = 1;
	while (((len + nb) % 64) != 56)
		nb++;
	if (!(tmp = ft_memalloc(len + nb + 8)))
		exit(0);
	*size = len + nb + 4;
	i = -1;
	while (++i < len)
		tmp[i] = (unsigned char)(str[i]);
	tmp[i++] = 0b10000000;
	while (i < len + nb)
		tmp[i++] = 0;
	len *= 8;
	ft_padding_sha256_2(tmp, i, len);
	return (tmp);
}

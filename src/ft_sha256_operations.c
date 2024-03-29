/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:42:55 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/29 13:50:50 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"

unsigned int		ft_ch(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) ^ (~(x) & z));
}

unsigned int		ft_maj(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

unsigned int		ft_rotr(unsigned int x, int n)
{
	return ((x >> n) | (x << (32 - n)));
}

unsigned int		ft_shr(unsigned int x, int n)
{
	return (x >> n);
}

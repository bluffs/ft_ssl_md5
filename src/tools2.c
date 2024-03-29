/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:51:10 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/29 13:51:13 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"

unsigned int	ft_get_unsigned(unsigned char *str)
{
	return ((str[0] << 24) + (str[1] << 16)
				+ (str[2] << 8) + str[3]);
}

void			ft_set_unsigned(unsigned char *str, unsigned int nb)
{
	str[0] = (nb >> 24) & 0xFF;
	str[1] = (nb >> 16) & 0xFF;
	str[2] = (nb >> 8) & 0xFF;
	str[3] = (nb) & 0xFF;
}

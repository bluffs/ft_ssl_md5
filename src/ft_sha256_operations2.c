/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_operations2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:46:16 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/29 13:46:28 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"

unsigned int		ft_big_sigma_zero(unsigned int x)
{
	return (ft_rotr(x, 2) ^ ft_rotr(x, 13) ^ ft_rotr(x, 22));
}

unsigned int		ft_big_sigma_one(unsigned int x)
{
	return (ft_rotr(x, 6) ^ ft_rotr(x, 11) ^ ft_rotr(x, 25));
}

unsigned int		ft_small_sigma_zero(unsigned int x)
{
	return (ft_rotr(x, 7) ^ ft_rotr(x, 18) ^ ft_shr(x, 3));
}

unsigned int		ft_small_sigma_one(unsigned int x)
{
	return (ft_rotr(x, 17) ^ ft_rotr(x, 19) ^ ft_shr(x, 10));
}

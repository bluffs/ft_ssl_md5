/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:16:09 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/29 13:35:15 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <math.h>

void	init_tab(t_var *tab)
{
	int	i;

	i = 0;
	while (i < 64)
	{
		tab->k[i] = floor(fabs(sin(i + 1)) * pow(2, 32));
		i++;
	}
	tab->h0 = 0x67452301;
	tab->h1 = 0xEFCDAB89;
	tab->h2 = 0x98BADCFE;
	tab->h3 = 0x10325476;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:22:46 by jyakdi            #+#    #+#             */
/*   Updated: 2019/09/17 18:35:25 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char	*ft_padding(char *str)
{
	char	*tmp;
	int		i;

	printf("sizeof the message = %lu\n", ft_strlen(str) * 8);
	printf("message = %s\n", str);
	int len = ft_strlen(str);
	int nb = 1; // the 1 after msg
	while (((len + nb) % 64) != 56)
		nb++;
	printf ("nb char to add = %d\n", nb);
	if (!(tmp = ft_memalloc(len + nb + 7)))
		//malloc error
		exit(0);
	i = 0;
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i++] = 0b1000000;
	while (i < len + nb)
	{
		tmp[i] = 0;
		i++;
	}
	len *= 8;
	tmp[i++] = (len >> 24) & 0xFF;
	tmp[i++] = (len >> 16) & 0xFF;
	tmp[i++] = (len >> 8) & 0xFF;
	tmp[i++] = len & 0xFF;
	return (tmp);
}

char	*ft_hash_md5(char *str)
{
	int r[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
	unsigned int	k[64];
	int				h0;
	int				h1;
	int				h2;
	int				h3;

	h0 = 0x67452301;
	h1 = 0xEFCDAB89;
	h2 = 0x98BADCFE;
	h3 = 0x10325476;
	int	i;
	i = 0;
	while (i < 64)
	{
		k[i] = floor(fabs(sin(i + 1)) * pow(2, 32));
		//printf("%x\n", k[i]);
		i++;
	}
	str = ft_padding(str);
	/*int n = 0;
	while (n < 63)
	{
		printf("%c\n", str[n]);
		n++;
	}*/
	return (NULL);
}

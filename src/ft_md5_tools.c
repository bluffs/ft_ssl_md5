/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:22:46 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/02 18:09:33 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <stdio.h>
#include <stdlib.h>

int g_var[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

unsigned char	*ft_padding(char *str, int *size)
{
	unsigned char	*tmp;
	int		i;

	int len = ft_strlen(str);
	int nb = 1; // the 1 after msg
	while (((len + nb) % 64) != 56)
		nb++;
	if (!(tmp = ft_memalloc(len + nb + 8))) // 8 for size of the message to append
		exit(0);
	*size = len + nb + 8;
	i = 0;
	while (i < len)
	{
		tmp[i] = (unsigned char)(str[i]);
		i++;
	}
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
	int	i;
	int	j;
	unsigned int	*test;

	test = ft_memalloc(sizeof(int) * 16);
	/*i = 0;
	while (i < 16)
	{
		test[i] = ft_memalloc(5);
		i++;
	}*/
	i = 0;
	while (i < 16)
	{
		j = 0;
		test[i] = 0;
		while (j < 4)
		{
			//m[i][j] = str[i * 4 + j];
			//printf("copying str[nb] = %c\n", str[i * 4 + j]);
			//printf("i = %d, j = %d, adding : %u\n", i, j, str[i * 4 + j]);
			test[i] += str[i * 4 + j] << (j * 8);
			j++;
		}
		i++;
	}
	/*int n = 0;
	while (n < 16)
	{
		printf("test[%u] = %u\n", n, test[n]);
		n++;
	}*/
	tab->a = tab->h0;
	tab->b = tab->h1;
	tab->c = tab->h2;
	tab->d = tab->h3;
	return (test);
}

void	ft_operate(t_var *tab, unsigned char *str)
{
	int		i;
	int		F;
	int		g;
	unsigned int	*test;
	unsigned int	temp;

	/*int u = 0;
	while (u < 16)
	{
		printf("[%d] = %d\n", u, ((unsigned int *)str)[u]);
		u++;
	}*/

	test = ft_chunk(str, tab);
	/*int nb = 0;
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';

	nb += str[0] << 24;
	nb += str[1] << 16;
	nb += str[2] << 8;
	nb += str[3] << 0;
	
	printf("nb = %d\n", nb);*/
	/*int n = 0;
	while (n < 16)
	{
		printf("test[%d] = %d\n", n, test[n]);
		n++;
	}*/
	
	//printf ("A = %u, B = %u, C = %u, D = %u\n", tab->a, tab->b, tab->c, tab->d);
	i = 0;
	//printf("b = %u, ~c = %u, b & c = %u\n", tab->b, tab->c, (tab->b & tab->c));
	unsigned int x = 0;
	while (i < 64) // TODO change to 64
	{
		if (i < 16)
		{
			F = (tab->b & tab->c) | ((~(tab->b)) & tab->d);
			g = i;
		}
		else if (i < 32)
		{
			F = (tab->d & tab->b) | (~(tab->d) & tab->c);
			g = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			F = tab->b ^ tab->c ^ tab->d;
			g = (3 * i + 5) % 16;
		}
		else
		{
			F = tab->c ^ (tab->b | ~(tab->d));
			g = (7 * i) % 16;
		}
		//printf("b = %u, a = %u, c = %u, test[g] = %d, k[i] = %u, g_var[i] = %u\n", tab->b, tab->a, tab->c, test[g], tab->k[i], g_var[i]);
		//printf(" +\n%u\n", (tab->a + ((tab->b & tab->c) | ((~(tab->b)) & tab->d)) + test[g] + tab->k[i]));
		x = ((tab->b & tab->c) | ((~(tab->b)) & tab->d));
		//printf("x = %u\n", x);
		//printf("a = %u, f = %u, k[i] = %u, w[g] = %u\n", tab->a, x, tab->k[i], test[g]);
		//printf("test = %u\n", tab->b + (tab->a + F + test[g] + tab->k[i]));
		x = (tab->a + F + test[g] + tab->k[i]);
		tab->a = tab->b + ((x << g_var[i]) | (x >> (32 - g_var[i])));
		//printf("tab->a = %u\n", tab->a);
		//F = F + tab->a + tab->k[i] + test[g];
		temp = tab->b;
		tab->b = tab->a;
		tab->a = tab->d;
		tab->d = tab->c;
		tab->c = temp;
		//tab->b += (F << g_var[i]) | (F >> (32 - g_var[i]));
		// TODO try this then change the leftrotate function
		//tab->b = tab->b + (F << g_var[i]);
		printf ("[i = %d] A = %u, B = %u, C = %u, D = %u\n", i, tab->a, tab->b, tab->c, tab->d);
		i++;
	}
	// Testing the last part
	//tab->a = 1713794056;
	//tab->b = 2214950333;
	//tab->c = 3935568332;
	//tab->d = 3867267760;
	tab->h0 = tab->h0 + tab->a;
	tab->h1 = tab->h1 + tab->b;
	tab->h2 = tab->h2 + tab->c;
	tab->h3 = tab->h3 + tab->d;
	printf("h0_Hex = %x, h1_Hex = %x, h2_Hex = %x, h3_Hex = %x\n", tab->h0, tab->h1, tab->h2, tab->h3);
}

char	*ft_hash_md5(char *str)
{
	int				size;
	unsigned char			*tmp;
	t_var			tab;
	int				i;
	int				j;
	unsigned char	*str1;
	
	/*int u = 0;
	while (u < 16)
	{
		printf("[%d] = %u\n", u, ((unsigned int *)str)[u]);
		u++;
	}*/

	init_tab(&tab);
	str1 = ft_padding(str, &size);
	//printf("size of message after padding : %d\n", size);
	//for each 512 bits (64 bytes) of the message, do the hashing rounds
	i = 0;
	while (size - i > 0)
	{
		if (i != 0)
			free(tmp);
		if (!(tmp = ft_memalloc(64)))
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
	/*int n = 0;
	while (n < 63)
	{
		printf("%c\n", str[n]);
		n++;
	}*/
	return (NULL);
}

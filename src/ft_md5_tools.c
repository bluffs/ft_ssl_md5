/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:22:46 by jyakdi            #+#    #+#             */
/*   Updated: 2019/09/24 18:50:00 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"
#include <stdio.h>
#include <stdlib.h>

int g_var[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

char	*ft_padding(char *str, int *size)
{
	char	*tmp;
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
		tmp[i] = str[i];
		i++;
	}
	tmp[i++] = 0b1000000;
	while (i < len + nb)
		tmp[i++] = 0;
	len *= 8;
	tmp[i++] = (len >> 24) & 0xFF;
	tmp[i++] = (len >> 16) & 0xFF;
	tmp[i++] = (len >> 8) & 0xFF;
	tmp[i++] = len & 0xFF;
	return (tmp);
}

void	ft_chunk(char *str, char m[16][4], t_var *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 4)
		{
			m[i][j] = str[i * 4 + j];
			j++;
		}
		i++;
	}
	tab->a = tab->h0;
	tab->b = tab->h1;
	tab->c = tab->h2;
	tab->d = tab->h3;
}

void	ft_operate(t_var *tab, char *str)
{
	char	m[16][4];
	int		i;
	int		F;
	int		g;

	ft_chunk(str, m, tab);
	i = 0;
	while (i < 64)
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
		F = F + tab->a + tab->k[i] + (int)m[g];
		tab->a = tab->d;
		tab->d = tab->c;
		tab->c = tab->b;
		// TODO try this then change the leftrotate function
		tab->b = tab->b + (F << g_var[i]);
		i++;
	}
	tab->h0 = tab->h0 + tab->a;
	tab->h1 = tab->h1 + tab->b;
	tab->h2 = tab->h2 + tab->c;
	tab->h3 = tab->h3 + tab->d;

}

char	*ft_hash_md5(char *str)
{
	int				size;
	char			*tmp;
	t_var			tab;
	int				i;
	int				j;
	
	init_tab(&tab);
	str = ft_padding(str, &size);
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
			tmp[j] = str[i + j];
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

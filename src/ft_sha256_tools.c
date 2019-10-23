#include <stdlib.h>
#include "../inc/ssl.h"
#include <stdio.h>

/*void	ft_reverse(unsigned int num, char *hash, int start)
{
	int				i;
	unsigned int	nb;

	i = 0;
	while (i < 4)
	{
		nb = (num >> 8 * i) & 0xFF;
		hash[start + (i * 2)] = ft_itoh(nb / 16);
		hash[start + (i * 2) + 1] = ft_itoh(nb % 16);
		i++;
	}
}

char	*ft_final_print(t_var *tab)
{
	char	*hash;

	if (!(hash = ft_memalloc(33)))
		exit(0);
	ft_reverse(tab->h0, hash, 0);
	ft_reverse(tab->h1, hash, 8);
	ft_reverse(tab->h2, hash, 16);
	ft_reverse(tab->h3, hash, 24);
	return (hash);
}*/

void	ft_round_sha256(int i, int *f, int *g, t_var *tab)
{
/*	if (i < 16)
	{
		*f = (tab->b & tab->c) | ((~(tab->b)) & tab->d);
		*g = i;
	}
	else if (i < 32)
	{
		*f = (tab->d & tab->b) | (~(tab->d) & tab->c);
		*g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		*f = tab->b ^ tab->c ^ tab->d;
		*g = (3 * i + 5) % 16;
	}
	else
	{
		*f = tab->c ^ (tab->b | ~(tab->d));
		*g = (7 * i) % 16;
	}*/
}

void	ft_operate_sha256(t_256 *tab, unsigned char *str)
{
/*	int				i;
	int				f;
	int				g;
	unsigned int	*test;
	unsigned int	x;

	x = 0;
	test = ft_chunk(str, tab);
	i = 0;
	while (i < 64)
	{
		ft_round(i, &f, &g, tab);
		x = (tab->a + f + test[g] + tab->k[i]);
		tab->a = tab->b + ((x << g_var[i]) | (x >> (32 - g_var[i])));
		x = tab->b;
		tab->b = tab->a;
		tab->a = tab->d;
		tab->d = tab->c;
		tab->c = x;
		i++;
	}
	tab->h0 = tab->h0 + tab->a;
	tab->h1 = tab->h1 + tab->b;
	tab->h2 = tab->h2 + tab->c;
	tab->h3 = tab->h3 + tab->d;*/
}

char	*ft_final_print_256(t_256 *tab)
{
	char	*hash;

	if (!(hash = ft_memalloc(33)))
		exit(0);
	ft_reverse(tab->h0, hash, 0);
	ft_reverse(tab->h1, hash, 8);
	ft_reverse(tab->h2, hash, 16);
	ft_reverse(tab->h3, hash, 24);
	return (hash);
}

void	ft_init_msg(unsigned char *str)
{
	int	i;

	i = 16;
	while (i < 64)
	{
		//printf("init w%d\n", i);
		ft_putstr("init for w");
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_print_binary(&str[i * 4]);
		ft_putendl("");
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
	ft_init_msg(str1);
	{
		int n = 0;
		while (n < 64)
		{
			ft_putnbr(n);
			ft_putstr(". ");
			ft_print_binary(&str1[n * 4]);
			ft_putchar('\n');
			n++;
		}
		ft_putchar('\n');
	}
	//testing block
	/*{
		int i = 0;
		while (i < 64)
		{
			printf("i = %d : %c%c%c%c\n", i, str1[i], str1[i + 1], str1[i + 2], str[i + 3]);
			i += 4;
		}
	}*/
	while (size - i > 0)
	{
		if (i != 0)
			free(tmp);
		if (!(tmp = ft_memalloc(65)))
			exit(0);
		j = 0;
		while (j < 64)
		{
			tmp[j] = str1[i + j];
			j++;
		}
		i += 64;
		ft_operate_sha256(&tab, tmp);
	}
	return (ft_final_print_256(&tab));
}

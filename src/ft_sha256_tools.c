#include <stdlib.h>
#include "../inc/ssl.h"
#include <stdio.h>

void	ft_operate_sha256(t_256 *tab, unsigned char *str)
{
	int				i;

	i = 0;
	while (i < 64)
	{
		tab->t1 = tab->h + ft_big_sigma_one(tab->e) + ft_ch(tab->e, tab->f, tab->g) + tab->k[i] + ft_get_unsigned(&str[i * 4]);
		tab->t2 = ft_big_sigma_zero(tab->a) + ft_maj(tab->a, tab->b, tab->c);
		tab->h = tab->g;
		tab->g = tab->f;
		tab->f = tab->e;
		tab->e = tab->d + tab->t1;
		tab->d = tab->c;
		tab->c = tab->b;
		tab->b = tab->a;
		tab->a = tab->t1 + tab->t2;
		i++;
	}
	tab->h0 += tab->a;
	tab->h1 += tab->b;
	tab->h2 += tab->c;
	tab->h3 += tab->d;
	tab->h4 += tab->e;
	tab->h5 += tab->f;
	tab->h6 += tab->g;
	tab->h7 += tab->h;
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

	if (!(hash = ft_memalloc(65)))
		exit(0);
	ft_reverse(tab->h0, hash, 0);
	ft_reverse(tab->h1, hash, 8);
	ft_reverse(tab->h2, hash, 16);
	ft_reverse(tab->h3, hash, 24);
	ft_reverse(tab->h4, hash, 32);
	ft_reverse(tab->h5, hash, 40);
	ft_reverse(tab->h6, hash, 48);
	ft_reverse(tab->h7, hash, 56);
	return (hash);
}

void	ft_init_msg(unsigned char *str)
{
	int				i;
	unsigned int	nb;

	i = 16;
	//str[50 * 4 + 2] = 43;
	while (i < 64)
	{
		nb = ft_small_sigma_one(ft_get_unsigned(&str[(i - 1) * 4]));
		nb += ft_get_unsigned(&str[(i - 7) * 4]);
		nb += ft_small_sigma_zero(ft_get_unsigned(&str[(i - 1) * 4]));
		nb += ft_get_unsigned(&str[(i - 16) * 4]);
		ft_set_unsigned(&str[i * 4], nb);
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
	ft_init_msg(str1); //TODO this should be done for each block in the while loop
	/*{
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
	}*/
	printf("size = %d\n", size);
	while (size - i > 0)
	{
		if (i != 0)
			free(tmp);
		if (!(tmp = ft_memalloc(65 * 4)))
			exit(0);
		j = 0;
		while (j < 64 * 4)
		{
			tmp[j] = str1[i + j];
			j++;
		}
		i += 64 * 4;
		ft_operate_sha256(&tab, tmp);
	}
	return (ft_final_print_256(&tab));
}

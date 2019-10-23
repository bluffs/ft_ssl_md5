#include "../inc/ssl.h"
#include <stdlib.h>
#include <stdio.h>

unsigned char		*ft_padding_sha256(char *str, int *size)
{
	unsigned char	*tmp;
	int				i;
	int				nb;
	int				len;

	len = ft_strlen(str);
	nb = 1;
	while (((len + nb) % 64) != 60)
		nb++;
	if (!(tmp = ft_memalloc((len + nb + 4) * 4)))
		exit(0);
	*size = len + nb + 4;
	i = -1;
	while (++i < len)
		tmp[i] = (unsigned char)(str[i]);
	tmp[i++] = 0b10000000;
	while (i < len + nb)
		tmp[i++] = 0;
	len *= 8;
	//printf("len = %d\n", len);
	//printf("i = %d\n", i);
	tmp[i++] = (len >> 24) & 0xFF;
	tmp[i++] = (len >> 16) & 0xFF;
	tmp[i++] = (len >> 8) & 0xFF;
	tmp[i++] = (len >> 0) & 0xFF;
	{
		/*int n = 0;
		while (n <= 60)
		{
			printf("n = %d : %x\n", n / 4 + 1, (tmp)[n + 0]);
			printf("n = %d : %x\n", n / 4 + 1, (tmp)[n + 1]);
			printf("n = %d : %x\n", n / 4 + 1, (tmp)[n + 2]);
			printf("n = %d : %x\n", n / 4 + 1, (tmp)[n + 3]);
			n += 4;
		}*/
		int n = 0;
		while (n < 64)
		{
			ft_putnbr(n);
			ft_putstr(". ");
			ft_print_binary(&tmp[n * 4]);
			ft_putchar('\n');
			n++;
		}
		ft_putchar('\n');
	}
	return (tmp);
}

unsigned int 		ft_ch(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) + (~(x) & z));
}

unsigned int		ft_maj(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) + (x & z) + (y & z));
}

unsigned int		ft_rotr(unsigned int x, int n)
{
	return ((x >> n) & (x << (32 - n)));
}

unsigned int		ft_shr(unsigned int x, int n)
{
	return (x >> n);
}

unsigned int		ft_big_sigma_zero(unsigned int x)
{
	return (ft_rotr(x, 2) + ft_rotr(x, 13) + ft_rotr(x, 22));
}

unsigned int		ft_big_sigma_one(unsigned int x)
{
	return (ft_rotr(x, 6) + ft_rotr(x, 11) + ft_rotr(x, 25));
}

unsigned int		ft_small_sigma_zero(unsigned int x)
{
	return (ft_rotr(x, 7) + ft_rotr(x, 18) + ft_shr(x, 3));
}

unsigned int		ft_small_sigma_one(unsigned int x)
{
	return (ft_rotr(x, 17) + ft_rotr(x, 19) + ft_shr(x, 10));
}

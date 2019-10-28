#include "../inc/ssl.h"
#include <stdlib.h>
#include <stdio.h>

unsigned long		ft_strlong(char *str)
{
	unsigned long	len;

	len = 0;
	if (str == 0)
		return (0);
	while (str[len])
		len++;
	return (len);
}

unsigned char		*ft_padding_sha256(char *str, int *size)
{
	unsigned char	*tmp;
	unsigned long	i;
	unsigned long	nb;
	unsigned long	len;

	len = ft_strlong(str);
	nb = 1;
	while (((len + nb) % 64) != 56)
		nb++;
	if (!(tmp = ft_memalloc(len + nb + 8)))
		exit(0);
	*size = len + nb + 4;
	i = -1;
	while (++i < len)
		tmp[i] = (unsigned char)(str[i]);
	tmp[i++] = 0b10000000;
	while (i < len + nb)
		tmp[i++] = 0;
	len *= 8;
	tmp[i++] = (len >> 56) & 0xFF;
	tmp[i++] = (len >> 48) & 0xFF;
	tmp[i++] = (len >> 40) & 0xFF;
	tmp[i++] = (len >> 32) & 0xFF;
	tmp[i++] = (len >> 24) & 0xFF;
	tmp[i++] = (len >> 16) & 0xFF;
	tmp[i++] = (len >> 8) & 0xFF;
	tmp[i++] = (len >> 0) & 0xFF;
	/*{
		int n = 0;
		while (n < 64)
		{
			ft_putnbr(n + 1);
			ft_putstr(". ");
			ft_print_binary(&tmp[n * 4]);
			ft_putchar('\n');
			n++;
		}
		ft_putchar('\n');
	}*/
	return (tmp);
}

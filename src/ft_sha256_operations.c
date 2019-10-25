#include "../inc/ssl.h"
#include <stdio.h>

unsigned int 		ft_ch(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) ^ (~(x) & z));
}

unsigned int		ft_maj(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

unsigned int		ft_rotr(unsigned int x, int n)
{
	//printf("into rotr\n");
	//printf("1.1 = %u\n", x >> n);
	//printf("1.2 = %u\n", x << (32 - n));
	return ((x >> n) | (x << (32 - n)));
}

unsigned int		ft_shr(unsigned int x, int n)
{
	return (x >> n);
}

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
	//printf("x = %u\n", x);
	//printf("1 = %u\n", ft_rotr(x, 17));
	//printf("returning %u\n", ft_rotr(x, 17) ^ ft_rotr(x, 19) ^ ft_shr(x, 10));
	return (ft_rotr(x, 17) ^ ft_rotr(x, 19) ^ ft_shr(x, 10));
}

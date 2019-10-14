#include "../inc/ssl.h"

void	ft_print_file_sha256(char *str, char *hash, int flag)
{
	if (flag == 0)
	{
		ft_putstr("sha256 (");
		ft_putstr(str);
		ft_putstr(") = ");
		ft_putendl(hash);
	}
	else if (flag == 1)
	{
		ft_putstr(hash);
		ft_putstr(" ");
		ft_putstr(str);
		ft_putendl("");
	}
	else
		ft_putendl(hash);
}

void	ft_print_sha256(char *str, char *hash, int flag)
{
	if (flag == 0)
	{
		ft_putstr("sha256 (\"");
		ft_putstr(str);
		ft_putstr("\") = ");
		ft_putendl(hash);
	}
	else if (flag == 1)
	{
		ft_putstr(hash);
		ft_putstr(" \"");
		ft_putstr(str);
		ft_putendl("\"");
	}
	else if (flag == 3)
	{
		ft_putstr(str);
		ft_putendl(hash);
	}
	else
		ft_putendl(hash);
}

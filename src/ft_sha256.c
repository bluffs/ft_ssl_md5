#include "../inc/ssl.h"

void	ft_do_stdin_sha256(char c, int nb)
{
	char	*str;

	if (c == 'p' && nb == 1)
	{
		ft_read_file(NULL, &str, NULL, 0);
		ft_print_sha256(str, ft_hash_sha256(str, 0, 0), 3);
	}
	else if (c == 'p' && nb == 0)
	{
		ft_read_file(NULL, &str, NULL, 0);
		ft_print_sha256(str, ft_hash_sha256(str, 0, 0), 4);
	}
}

int		ft_do_string_sha256(int argc, int *i, char **argv, int qr_flag)
{
	if (*i + 1 < argc)
	{
		(*i)++;
		ft_print_sha256(argv[*i], ft_hash_sha256(argv[*i], 0, 0), qr_flag);
		return (1);
	}
	else
	{
		ft_usage_sha256(0);
		return (0);
	}
}

void	sha256(int argc, char **argv, int i, int files)
{
	int	p_flag;
	int	qr_flag;
	int	tmp;

	p_flag = 0;
	qr_flag = 0;
	while (++i < argc)
	{
		if (files == 0 && argv[i][0] == '-')
		{
			tmp = ft_flag_check(argv, i, &p_flag, &qr_flag);
			if (tmp == 1)
				p_flag += ft_do_string_sha256(argc, &i, argv, qr_flag);
		}
		else
		{
			files = 1;
			if (ft_read_file(argv[i], &argv[0], NULL, 1) == 1)
				ft_print_file_sha256(argv[i], ft_hash_sha256(argv[0], 0, 0), qr_flag);
		}
	}
	if (p_flag == 0 && files == 0)
		ft_do_stdin_sha256('p', 0);
}
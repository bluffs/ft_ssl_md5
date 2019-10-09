/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:37:27 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/09 15:49:57 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_error_cmd(char *str)
{
	ft_putstr("ft_ssl: Error: '");
	ft_putstr(str);
	ft_putendl("' is an invalid command.\n");
	ft_putendl("Standard commands:\n");
	ft_putendl("Message Digest commands:");
	ft_putendl("md5");
	ft_putendl("sha256");
	ft_putendl("Cipher commands:");
}

void	ft_usage(char c)
{
	ft_putstr_fd("md5: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: md5 [-pqr] [-s string] [files ...]", 2);
}

void	ft_no_file(char *file)
{
	ft_putstr_fd("MD5: ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": No such file or directory", 2);

}

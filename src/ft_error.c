/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:37:27 by jyakdi            #+#    #+#             */
/*   Updated: 2019/09/02 17:42:44 by jyakdi           ###   ########.fr       */
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

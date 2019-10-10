/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:53:08 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/10 15:43:31 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/ssl.h"

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
	{
		ft_putendl_fd("usage: ft_ssl command [command opts] [command args]", 2);
	}
	ft_do_cmd(argc, argv);
	return (0);
}

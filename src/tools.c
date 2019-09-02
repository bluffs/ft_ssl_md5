/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:04:50 by jyakdi            #+#    #+#             */
/*   Updated: 2019/09/02 17:46:32 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/ssl.h"

void	ft_do_cmd(int argc, char **argv)
{
	if (argc >= 2)
	{
		//ft_putendl(argv[1]);
	}
	if (ft_strcmp(argv[1], "md5") == 0)
	{
		ft_putendl("gonna hash with md5");
	}
	else
	{
		ft_error_cmd(argv[1]);
	}
}

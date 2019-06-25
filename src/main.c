/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 02:53:15 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/25 06:02:09 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "ft_select.h"

static void		main_loop(t_list *args)
{
	refresh_display_table(args);
	while (1)
	{
		display_args(args);
	}
}

int			main(int ac, char *av[])
{
	t_list	*args;

	if (ac < 2)
		print_usage();
	else
	{
		init_config();
		args = argv_to_list(ac -1, av + 1, arg_to_lst_elem);
		main_loop(args);
		reset_config();
	}
	return (0);
}

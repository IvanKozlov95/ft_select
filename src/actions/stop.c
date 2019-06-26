/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:33:05 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 00:36:22 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ft_select.h"

#include <stdlib.h>

static void		free_arg(void *arg, size_t size)
{
	(void)size;
	ft_free(1, ((t_arg *)arg)->value);
}

void			ft_select_stop(t_list *args, bool print_selected)
{
	reset_config();
	if (print_selected)
		print_selected_args(args);
	ft_lstdel(&args, free_arg);
	exit(0);
}

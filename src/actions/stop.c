/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:33:05 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 21:05:52 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ft_select.h"

#include <stdlib.h>

void			ft_select_free_arg(void *arg, size_t size)
{
	(void)size;
	ft_free(2, ((t_arg *)arg)->value, arg);
}

void			ft_select_stop(t_dlist *args, bool print_selected)
{
	reset_config();
	if (print_selected)
		print_selected_args(args);
	dlstdel(&args, ft_select_free_arg);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:03:18 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 01:51:49 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ft_select.h"

#include <unistd.h>

static void		toggle_selected(t_list *args)
{
	t_info		*info;
	t_arg		*active;

	info = get_set_info();
	active = (t_arg *)info->active_arg->content;
	active->selected = !active->selected;
	if (active->selected)
		info->active_arg = info->active_arg->next;
	if (info->active_arg == NULL)
		info->active_arg = args;
}

void			user_input(t_list *args)
{
	long	c;

	c = 0;
	read(STDIN_FILENO, &c, 8);
	if (c == KSPACE)
		toggle_selected(args);
	else if (c == KENTER)
		ft_select_stop(args, true);
	else if (c == KESC)
		ft_select_stop(args, false);
}

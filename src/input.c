/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:03:18 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 21:12:07 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ft_select.h"

#include <unistd.h>

static void		toggle_selected(t_dlist *args)
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

static void		delete_active_arg(t_dlist **args)
{
	t_dlist		*next;
	t_dlist		*active;

	active = get_set_info()->active_arg;
	next = active->next ? active->next : *args;
	dlstremove(args, active, ft_select_free_arg);
	get_set_info()->active_arg = next;
}

void			user_input(t_dlist **args)
{
	int		c;

	c = 0;
	read(STDERR_FILENO, &c, 4);
	if (c == ' ')
		toggle_selected(*args);
	else if (c == KENTER)
		ft_select_stop(*args, true);
	else if (c == KESC)
		ft_select_stop(*args, false);
	else if (c == KBSPACE || c == KDELETE)
		delete_active_arg(args);
	else if (c == KUP || c == KDOWN || c == KLEFT || c == KRIGHT)
		move_active(c, *args);
}

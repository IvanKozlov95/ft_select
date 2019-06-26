/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 06:34:43 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 08:09:30 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		left(t_dlist *args)
{
	get_set_info()->active_arg = get_set_info()->active_arg->prev;
	if (!get_set_info()->active_arg)
		get_set_info()->active_arg = dlstlast(args);
}

static void		right(t_dlist *args)
{
	get_set_info()->active_arg = get_set_info()->active_arg->next;
	if (!get_set_info()->active_arg)
		get_set_info()->active_arg = args;
}

static void		up(t_dlist *args)
{
	size_t		i;
	size_t		cols;
	size_t		count;
	t_dlist		*active_arg;

	active_arg = get_set_info()->active_arg;
	i = dlstindexof(args, active_arg);
	count = dlstcount(args);
	cols = get_set_info()->display_table.cols;
	if (i < cols)
		cols = count % cols + cols * (i >= count % cols);
	while (cols-- > 0)
		left(args);
}

static void		down(t_dlist *args)
{
	size_t		i;
	size_t		cols;
	size_t		count;
	t_dlist		*active_arg;

	active_arg = get_set_info()->active_arg;
	i = dlstindexof(args, active_arg);
	count = dlstcount(args);
	cols = get_set_info()->display_table.cols;
	cols = i + cols < count ? cols : count - i + i % cols;
	while (cols-- > 0)
		right(args);
}

void		move_active(int key_id, t_dlist *args)
{
	static t_move_action dispatch[] = {
		0, &left, 0, &up, 0, &right, 0, 0, 0, &down,
	};

	(*dispatch[key_id % 10])(args);
}

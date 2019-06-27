/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 02:17:31 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 21:04:15 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"
#include "colors.h"
#include "ftstring.h"
#include "ft_select.h"
#include "ft_printf.h"

#include "ftstring.h"

static char		*get_arg_highlight(t_arg *arg)
{
	t_arg	*selected_arg;

	selected_arg = get_set_info()->active_arg->content;
	if (arg->selected)
		return (UNDLINE""REVERSE);
	return (selected_arg == arg ? UNDLINE : "");
}

static char		*get_arg_color(t_arg *arg)
{
	(void)arg;
	return ("");
}

static void		display_arg(t_dlist *arglist, size_t idx, t_dlist *list)
{
	t_arg		*arg;
	t_info		*info;
	char		*color;
	char		*highlight;

	(void)list;
	arg = (t_arg *)arglist->content;
	info = get_set_info();
	if (idx % info->display_table.cols == 0)
		ft_dprintf(STDERR_FILENO, "\n");
	color = get_arg_color(arg);
	highlight = get_arg_highlight(arg);
	ft_dprintf(STDERR_FILENO, "%s%s%-*s%s", color, highlight,
		info->display_table.col_width, arg->value, RESET);
}

void			refresh_display_table(t_dlist *args)
{
	size_t		tmp;
	t_info		*info;

	info = get_set_info();
	info->display_table.col_width = get_longest_arg(args)->length + 1;
	tmp = dlstcount(args);
	info->display_table.cols = TERMWIDTH / info->display_table.col_width;
	info->display_table.rows = tmp / info->display_table.cols
		+ tmp % info->display_table.cols != 0;
}

void			display_args(t_dlist *args)
{
	t_info		*info;

	info = get_set_info();
	SETTERMCMD("cl");
	if (info->display_table.rows > TERMHEIGHT)
		return ;
	dlstforeachif(args, display_arg, NULL);
}

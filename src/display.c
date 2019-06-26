/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 02:17:31 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 02:03:33 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "output.h"
#include "colors.h"
#include "ft_select.h"
#include "ft_printf.h"

#include "ftstring.h"

static char		*get_arg_highlight(t_arg *arg)
{
	if (arg->selected)
		return (REVERSE);
	return ("");
}

static char		*get_arg_color(t_arg *arg)
{
	return ("");
}

static void		display_arg(size_t idx, t_list *arglist)
{
	t_arg		*arg;
	t_info		*info;
	char		*color;
	char		*highlight;

	arg = (t_arg *)arglist->content;
	info = get_set_info();
	if (idx % info->display_table.cols == 0)
		ft_printf("\n");
	color = get_arg_color(arg);
	highlight = get_arg_highlight(arg);
	ft_printf("%s%s%-*s%s", color, highlight,
		info->display_table.col_width, arg->value, RESET);
}

void			refresh_display_table(t_list *args)
{
	size_t		tmp;
	t_info		*info;

	info = get_set_info();
	info->display_table.col_width = get_longest_arg(args)->length + 1;
	// todo: use count if
	tmp = ft_lstcount(args);
	info->display_table.cols = TERMWIDTH / info->display_table.col_width;
	info->display_table.rows = tmp / info->display_table.cols
		+ tmp % info->display_table.cols != 0;
}

void		display_args(t_list *args)
{
	t_arg		*arg;
	t_info		*info;

	info = get_set_info();
	SETTERMCMD("cl");
	if (info->display_table.rows > TERMHEIGHT)
		return ;
	ft_lstiteriif(args, display_arg, NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:22:06 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 21:07:10 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "ft_printf.h"

static bool				is_selected(size_t idx, t_dlist *arg)
{
	(void)idx;
	return (((t_arg *)arg->content)->selected);
}

static void				print_selected_arg(t_dlist *arg,
	size_t idx, t_dlist *list)
{
	static char		*separator;

	(void)idx;
	(void)list;
	if (arg == NULL)
	{
		separator = "";
		return ;
	}
	ft_printf("%s%s", separator, ((t_arg *)arg->content)->value);
	separator = " ";
}

void					print_selected_args(t_dlist *args)
{
	print_selected_arg(NULL, 0, NULL);
	dlstforeachif(args, print_selected_arg, is_selected);
}

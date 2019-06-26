/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:22:06 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 00:29:08 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "ft_printf.h"

static bool				is_selected(size_t idx, t_list *arg)
{
	return (((t_arg *)arg->content)->selected);
}

static void				print_selected_arg(size_t idx, t_list *arg)
{
	static char		*separator;

	(void)idx;
	if (arg == NULL)
	{
		separator = "";
		return ;
	}
	ft_printf("%s%s", separator, ((t_arg *)arg->content)->value);
	separator = " ";
}

void					print_selected_args(t_list *args)
{
	print_selected_arg(0, NULL);
	ft_lstiteriif(args, print_selected_arg, is_selected);
}
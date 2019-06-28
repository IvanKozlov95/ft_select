/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 22:57:49 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/28 02:20:20 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ft_select.h"

t_info		*get_set_info(void)
{
	static t_info		info;

	return (&info);
}

void		init_info(void)
{
	t_info		*info;

	info = get_set_info();
	info->search = string_init(0);
}

void		destroy_info(void)
{
	t_info		*info;

	info = get_set_info();
	string_destroy(info->search, FALSE);
}

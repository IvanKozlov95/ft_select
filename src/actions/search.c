/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 02:07:03 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/28 03:23:22 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "dlist.h"
#include "chars.h"
#include "memory.h"
#include "ftstring.h"
#include "ft_select.h"

static	void	match(t_dlist *arglist, size_t idx, t_dlist *list)
{
	t_arg			*arg;
	t_string		*search;

	search = get_set_info()->search;
	arg = (t_arg *)arglist->content;
	arg->search_match = ft_strstr(arg->value, search->content) == arg->value;
}

void			ft_select_search(int c, t_dlist *args)
{
	t_string		*search;
	static char		buf[2] = {0};

	buf[0] = (char)c;
	search = get_set_info()->search;
	if (c < 0 && search->length > 0)
	{
		search->content[search->length - 1] = 0;
		search->length--;
	}
	else if (c > 0)
		string_append(search, buf);
	if (search->length > 0)
		dlstforeachif(args, match, NULL);
}

void			ft_select_clear_search(int c)
{
	if ((c != KBSPACE && !ISPRINT(c)) || ISSPACE(c))
	{
		ft_bzero(get_set_info()->search->content,
			get_set_info()->search->length);
		get_set_info()->search->length = 0;
	}
}

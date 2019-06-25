/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 01:42:12 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/25 04:35:34 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "memory.h"
#include "ftstring.h"
#include "ft_select.h"

static t_file_type		get_file_type(char *path)
{
	(void)path;
	// todo: not implemented
	return (UNKNW);
}

t_arg					*get_longest_arg(t_list *args)
{
	t_arg	*ret;
	t_arg	*arg;

	ret = NULL;
	while (args)
	{
		arg = (t_arg *)args->content;
		if (ret == NULL || arg->length > ret->length)
			ret = arg;
		args = args->next;
	}
	return (ret);
}

t_list					*arg_to_lst_elem(char *arg)
{
	t_arg		newarg;

	ft_bzero(&newarg, sizeof(t_arg));
	newarg.value = ft_strdup(arg);
	newarg.length = ft_strlen(arg);
	newarg.type = get_file_type(arg);
	return (ft_lstnew(&newarg, sizeof(t_arg)));
}

t_list					*argv_to_list(int ac, char *av[], t_list *(new_elem)(char *))
{
	int			i;
	t_list		*ret;

	i = -1;
	ret = NULL;
	while (++i < ac)
		LST_ADDCREATE(ret, new_elem(av[i]));
	return (ret);
}

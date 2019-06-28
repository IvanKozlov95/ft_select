/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 01:42:12 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/28 03:37:13 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ftstring.h"
#include "ft_select.h"

#include <sys/stat.h>

static t_file_type		get_file_type(char *path)
{
	char			*name;
	t_file_type		ret;
	struct stat		f;

	ret = UNKNW;
	name = getfilename(path);
	if (lstat(path, &f))
		ret = UNKNW;
	else if (S_ISDIR(f.st_mode))
		ret = DIR;
	else if (f.st_mode & S_IXUSR)
		ret = EXECFILE;
	else if (strendswith(name, ".c"))
		ret = CFILE;
	else if (strendswith(name, ".o"))
		ret = OFILE;
	else if (strendswith(name, ".h"))
		ret = HFILE;
	else if (ft_strequ(name, "Makefile"))
		ret = MAKEFILE;
	else if (name[0] == '.')
		ret = DOTFILE;
	ft_free(1, name);
	return (ret);
}

t_arg					*get_longest_arg(t_dlist *args)
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

t_dlist					*arg_to_lst_elem(char *arg)
{
	t_arg		newarg;

	ft_bzero(&newarg, sizeof(t_arg));
	newarg.value = ft_strdup(arg);
	newarg.length = ft_strlen(arg);
	newarg.type = get_file_type(arg);
	return (dlstnew(&newarg, sizeof(t_arg)));
}

t_dlist					*argv_to_list(int ac, char *av[],
	t_dlist *(new_elem)(char *))
{
	int			i;
	t_dlist		*ret;

	i = -1;
	ret = NULL;
	while (++i < ac)
		DLIST_ADDCREATE(ret, new_elem(av[i]));
	return (ret);
}

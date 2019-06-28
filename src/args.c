/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 01:42:12 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/27 17:30:47 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ftstring.h"
#include "ft_select.h"

#include <sys/stat.h>

static t_file_type		get_file_type(char *path)
{
	char			*name;
	struct stat		f;

	name = getfilename(path);
	if (lstat(path, &f))
		return (UNKNW);
	if (S_ISDIR(f.st_mode))
		return (DIR);
	if (f.st_mode & S_IXUSR)
		return (EXECFILE);
	if (strendswith(name, ".c"))
		return (CFILE);
	if (strendswith(name, ".o"))
		return (OFILE);
	if (strendswith(name, ".h"))
		return (HFILE);
	if (ft_strequ(name, "Makefile"))
		return (MAKEFILE);
	if (name[0] == '.')
		return (DOTFILE);
	return (UNKNW);
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

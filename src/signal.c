/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 09:05:30 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 10:27:37 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

#include <signal.h>

static void		ft_select_stop_signal(int signo, t_dlist **args)
{
	static t_dlist	**saved = NULL;

	if (signo == -1)
		saved = args;
	else
		ft_select_stop(*saved, false);
}

static void		ft_select_suspend_signal(int signo)
{
	(void)signo;
	reset_config();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDOUT_FILENO, TIOCSTI, "\x1A");
}

static void		ft_select_continue_signal(int signo, t_dlist **args)
{
	static t_dlist	**saved = NULL;

	if (signo == -1)
		saved = args;
	else
	{
		init_config();
		inti_signal_handlers(saved);
		display_args(*saved);
	}
}

static void		ft_select_resize_signal(int signo, t_dlist **args)
{
	static t_dlist	**saved = NULL;

	saved = saved ? saved : args;
	if (signo == SIGWINCH)
	{
		refresh_display_table(*saved);
		display_args(*saved);
	}
}

void			inti_signal_handlers(t_dlist **args)
{
	signal(SIGINT, (void (*)(int))ft_select_stop_signal);
	signal(SIGABRT, (void (*)(int))ft_select_stop_signal);
	signal(SIGSTOP, (void (*)(int))ft_select_stop_signal);
	signal(SIGKILL, (void (*)(int))ft_select_stop_signal);
	signal(SIGQUIT, (void (*)(int))ft_select_stop_signal);
	signal(SIGWINCH, (void (*)(int))ft_select_resize_signal);
	signal(SIGTSTP, &ft_select_suspend_signal);
	signal(SIGCONT, (void (*)(int))ft_select_continue_signal);
	ft_select_stop_signal(-1, args);
	ft_select_resize_signal(-1, args);
	ft_select_continue_signal(-1, args);
}

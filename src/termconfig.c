/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termconfig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 22:54:21 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 21:09:21 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ft_select.h"

#include <stdlib.h>
#include <unistd.h>

static void		init_terminal_data(void)
{
	int		success;
	char	*termtype;
	char	buf[1024];

	termtype = getenv("TERM");
	if (termtype == NULL)
		fatal(EXIT_ERROR, "Specify a terminal type with\
`setenv TERM <yourtype>'.\n");
	success = tgetent(buf, termtype);
	if (success < 0)
		fatal(EXIT_ERROR, "Could not access the termcap data base.\n");
	if (success == 0)
		fatal(EXIT_ERROR, "Terminal type `%s' is not defined.\n", termtype);
}

void			reset_config(void)
{
	t_info		*info;

	info = get_set_info();
	tcsetattr(STDERR_FILENO, TCSANOW, &(info->default_attr));
	SETTERMCMD("ve");
	SETTERMCMD("te");
}

void			init_config(void)
{
	t_info		*info;

	init_terminal_data();
	info = get_set_info();
	tcgetattr(STDERR_FILENO, &(info->default_attr));
	ft_memcpy(&(info->attr), &(info->default_attr), sizeof(struct termios));
	info->attr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDERR_FILENO, TCSANOW, &(info->attr));
	SETTERMCMD("ti");
	SETTERMCMD("vi");
}

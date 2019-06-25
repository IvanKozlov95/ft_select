/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:43:07 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/25 00:53:21 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "dlist.h"

# include <term.h>
# include <curses.h>
# include <stdbool.h>
# include <termcap.h>
# include <termios.h>

enum						e_file_type
{
	UNKNW,
};
typedef enum e_file_type	t_file_type;

struct						s_arg
{
	char					*value;
	bool					selected;
};
typedef struct s_arg		t_arg;

struct						s_info
{
	struct termios		attr;
	struct termios		default_attr;
};
typedef struct s_info		t_info;

void						print_usage();

/*
** src/info.c
*/

t_info						*get_set_info(void);

/*
** src/termconfig.c
*/

void						init_config(void);
void						reset_config(void);

/*
** src/error.c
*/

void						fatal(const int exitcode, const char *fmt, ...);

/*
** MACROS
*/

# define EXIT_ERROR -1
# define _W struct winsize w
# define _GETWINSIZE(w) ioctl(STDOUT_FILENO, TIOCGWINSZ, &w)
# define SETTERMCMD(id) ({char *v = tgetstr(id, 0); tputs(v, 1, ft_putc);})

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:43:07 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/25 02:00:43 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include "list.h"

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
	t_file_type				type;
	char					*value;
	bool					deleted;
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
** src/args.c
*/

t_list						*argv_to_list(int ac, char *av[],
	t_list *(new_elem)(char *));
t_list						*arg_to_lst_elem(char *arg);

/*
** MACROS
*/

# define EXIT_ERROR -1
# define _W struct winsize w
# define _GETWINSIZE(w) ioctl(STDOUT_FILENO, TIOCGWINSZ, &w)
# define SETTERMCMD(id) ({char *v = tgetstr(id, 0); tputs(v, 1, ft_putc);})

#endif

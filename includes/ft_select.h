/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:43:07 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/27 17:27:57 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "dlist.h"
# include "output.h"

# include <term.h>
# include <curses.h>
# include <unistd.h>
# include <stdbool.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>

enum						e_file_type
{
	CFILE = 0,
	OFILE,
	HFILE,
	MAKEFILE,
	DOTFILE,
	DIR,
	EXECFILE,
	UNKNW,
};
typedef enum e_file_type	t_file_type;

struct						s_arg
{
	t_file_type				type;
	char					*value;
	size_t					length;
	bool					selected;
};
typedef struct s_arg		t_arg;

struct						s_table
{
	size_t					rows;
	size_t					cols;
	size_t					col_width;
};
typedef struct s_table		t_table;

struct						s_info
{
	struct termios		attr;
	struct termios		default_attr;
	t_table				display_table;
	t_dlist				*active_arg;
};
typedef struct s_info		t_info;

typedef void				(*t_move_action)(t_dlist *);

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

t_dlist						*argv_to_list(int ac, char *av[],
	t_dlist *(new_elem)(char *));
t_dlist						*arg_to_lst_elem(char *arg);
t_arg						*get_longest_arg(t_dlist *args);

/*
** src/display.c
*/

void						display_args(t_dlist *args);
void						refresh_display_table(t_dlist *args);

/*
** src/arg_print.c
*/

void						print_selected_args(t_dlist *args);

/*
** src/input.c
*/

void						user_input(t_dlist **args);

/*
** src/signal.c
*/

void						inti_signal_handlers(t_dlist **args);

/*
** src/actions/stop.c
*/

void						ft_select_free_arg(void *arg, size_t size);
void						ft_select_stop(t_dlist *args, bool print_selected);

/*
** src/actions/stop.c
*/

void						move_active(int key_id, t_dlist *args);

/*
** MACROS
*/

# define EXIT_ERROR -1
# define _W struct winsize w
# define _GETWINSIZE(w) ioctl(STDERR_FILENO, TIOCGWINSZ, &w)
# define TERMWIDTH ({ _W; _GETWINSIZE(w); w.ws_col; })
# define TERMHEIGHT ({ _W; _GETWINSIZE(w); w.ws_row; })
# define SETTERMCMD(id) ({char *v = tgetstr(id, 0); tputs(v, 1, ft_putc_err);})

#endif

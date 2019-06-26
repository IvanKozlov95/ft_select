/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:43:07 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/26 01:54:23 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "list.h"

# include <term.h>
# include <curses.h>
# include <unistd.h>
# include <stdbool.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>

enum						e_file_type
{
	UNKNW,
};
typedef enum e_file_type	t_file_type;

struct						s_arg
{
	t_file_type				type;
	char					*value;
	size_t					length;
	bool					deleted;
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
	t_list				*active_arg;
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
t_arg						*get_longest_arg(t_list *args);

/*
** src/display.c
*/

void						display_args(t_list *args);
void						refresh_display_table(t_list *args);

/*
** src/arg_print.c
*/

void						print_selected_args(t_list *args);

/*
** src/input.c
*/

void						user_input(t_list *args);

/*
** src/actions/stop.c
*/

void						ft_select_stop(t_list *args, bool print_selected);

/*
** MACROS
*/

# define EXIT_ERROR -1
# define _W struct winsize w
# define _GETWINSIZE(w) ioctl(STDOUT_FILENO, TIOCGWINSZ, &w)
# define TERMWIDTH ({ _W; _GETWINSIZE(w); w.ws_col; })
# define TERMHEIGHT ({ _W; _GETWINSIZE(w); w.ws_row; })
# define SETTERMCMD(id) ({char *v = tgetstr(id, 0); tputs(v, 1, ft_putc);})

#endif

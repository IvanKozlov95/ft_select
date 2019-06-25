/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:43:07 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/24 22:19:25 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "dlist.h"

# include <stdbool.h>

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


void						print_usage();

#endif

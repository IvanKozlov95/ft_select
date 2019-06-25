/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 23:15:24 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/25 00:53:11 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdlib.h>

void			fatal(const int exitcode, const char *fmt, ...)
{
	va_list		args;

	va_start(args, fmt);
	ft_printf(fmt, args);
	va_end(args);
	exit(exitcode);
}

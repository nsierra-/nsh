/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 03:59:45 by gbir              #+#    #+#             */
/*   Updated: 2014/03/26 15:25:56 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static size_t		st_strlen(const char *str)
{
	const char		*s;

	s = str;
	while (*s)
		++s;
	return ((size_t)(s - str));
}

int					ft_print(const char *str, int fd, int ret)
{
	write(fd, str, st_strlen(str));
	return (ret);
}

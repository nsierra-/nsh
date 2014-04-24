/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 07:00:10 by nsierra-          #+#    #+#             */
/*   Updated: 2014/03/26 15:26:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

static size_t		st_strlen(const char *str)
{
	const char		*keep;

	keep = str;
	if (str)
	{
		while (*str != '\0')
			++str;
	}
	return ((size_t)(str - keep));
}

void				ft_putendl(const char *str)
{
	size_t			str_size;

	str_size = st_strlen(str);
	write(1, str, str_size);
	write(1, "\n", (size_t)1);
}

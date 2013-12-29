/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 09:03:06 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/29 13:37:51 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t		ft_strlen(const char *s)
{
	char			*save;

	save = (char*)s;
	while (*save != '\0')
		++save;
	return (save - s);
}

void			ft_putendl(char const *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void			ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

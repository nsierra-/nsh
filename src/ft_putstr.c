/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:12:26 by nsierra-          #+#    #+#             */
/*   Updated: 2014/03/27 05:15:40 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_strlen(const char *str)
{
	const char	*keep;

	keep = str;
	if (str)
	{
		while (*keep != '\0')
			++keep;
		return ((size_t)(keep - str));
	}
	else
		return (0);
}

void			ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

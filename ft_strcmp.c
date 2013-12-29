/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:32:41 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/29 09:35:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && n)
	{
		if (*s1 == '\0')
			return (0);
		--n;
		++s1;
		++s2;
	}
	if (n == 0)
		return (0);
	if (*s1 > *s2)
		return (1);
	if (*s1 < *s2)
		return (-1);
	return (0);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		++s1;
		++s2;
	}
	if (*s1 > *s2)
		return (1);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makepath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 09:41:03 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/29 09:59:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		ft_strend(char **str)
{
	while (**str != '\0')
		++(*str);
}

static char		*ft_strcat(char *s1, const char *s2)
{
	char		*save;

	save = s1;
	ft_strend(&save);
	while (*s2 != '\0')
	{
		*save = *s2;
		++save;
		++s2;
	}
	*save = '\0';
	return (s1);
}

static size_t	ft_strlen(const char *s)
{
	char		*save;

	save = (char*)s;
	while (*save != '\0')
		++save;
	return (save - s);
}

char			*ft_makepath(char const *s1, char const *s2)
{
	char	*s;
	size_t	n;

	if (s1 && s2)
	{
		n = ft_strlen(s1) + ft_strlen(s2);
		s = (char*)malloc(sizeof(char) * (n + 2));
		if (s != NULL)
		{
			*s = '\0';
			s = ft_strcat(s, s1);
			s = ft_strcat(s, "/");
			s = ft_strcat(s, s2);
			return (s);
		}
	}
	return (0);
}

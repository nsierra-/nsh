/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 10:50:59 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/29 12:18:30 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t		ft_strlen(const char *s)
{
	char			*save;

	save = (char*)s;
	while (*save != '\0')
		++save;
	return (save - s);
}

char				*ft_strdup(const char *s1)
{
	char			*dup;
	int				i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dup == NULL)
		return (NULL);
	else
	{
		while (s1[i] != '\0')
		{
			dup[i] = s1[i];
			i = i + 1;
		}
	}
	dup[i] = '\0';
	return (dup);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathbuilder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 00:21:44 by nsierra-          #+#    #+#             */
/*   Updated: 2014/04/24 00:22:54 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_pathbuilder(char *path, char *file)
{
	char		*new_str;
	char		*keep;

	if (!(new_str = malloc(ft_strlen(path) + ft_strlen(file) + 2)))
		return (NULL);
	keep = new_str;
	while (*path != '\0')
	{
		*new_str = *path;
		++new_str;
		++path;
	}
	if (*(path - 1) != '/')
		*new_str++ = '/';
	while (*file != '\0')
	{
		*new_str = *file;
		++new_str;
		++file;
	}
	*new_str = '\0';
	return (keep);
}

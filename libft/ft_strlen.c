/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 03:54:24 by nsierra-          #+#    #+#             */
/*   Updated: 2014/03/26 15:26:55 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t			ft_strlen(const char *str)
{
	const char	*keep;

	keep = str;
	while (*str != '\0')
		++str;
	return ((size_t)(str - keep));
}

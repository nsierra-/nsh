/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sisnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 23:04:27 by nsierra-          #+#    #+#             */
/*   Updated: 2014/03/26 15:26:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_sisnum(const char *str)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			++str;
		else
			return (0);
	}
	return (1);
}
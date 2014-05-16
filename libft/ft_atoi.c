/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 07:42:13 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/19 07:43:30 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		nb;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\v')
		++i;
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		++i;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign = -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		++i;
	}
	return (sign * nb);
}
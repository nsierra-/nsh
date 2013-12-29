/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 15:04:29 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/29 15:04:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

int				error(int must_exit, char *err_message)
{
	ft_putendl(err_message);
	if (must_exit == TRUE)
		return (EXIT_FAILURE);
	else
		return (SUCCESS);
}
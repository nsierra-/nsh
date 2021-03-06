/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execlst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 07:54:42 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 10:20:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <errors.h>
#include <qd_sh.h>

t_exelst		new_command(void)
{
	t_exelst	*new_elem;

	new_elem = NULL;
	if (!(new_elem = malloc(sizeof(t_exelst))))
		die(ERROR(SH, E_GENERIC), EXIT_FAILURE);
}

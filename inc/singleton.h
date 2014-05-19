/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 05:43:38 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 06:13:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLETON_H
# define SINGLETON_H
# define TMPTAB_SIZE 1024

typedef enum		e_action
{
	get,
	set,
	reset
}					t_action;

typedef enum		e_stype
{
	cmd,
	in,
	out
}					t_stype;

typedef struct		s_tmptab
{
	char			*tab[TMPTAB_SIZE];
	int				i;
}					t_tmptab;

t_tmptab			*singleton(t_action action, t_stype type, char *token);

#endif

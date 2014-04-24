/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_extra_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:50:43 by nsierra-          #+#    #+#             */
/*   Updated: 2014/03/27 05:42:24 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <stdio.h>
#include "qd_sh.h"
#include "errors.h"
#include "libft.h"
#include "env.h"

void					set_extra_infos(t_env *e)
{
	t_passwd			*passwd;
	t_utsname			uts_name;

	if (!(passwd = getpwuid(getuid())))
		return ;
	env_setenv_var(e, "LOGNAME", passwd->pw_name);
	env_setenv_var(e, "USER", passwd->pw_name);
	env_setenv_var(e, "SHELL", passwd->pw_shell);
	env_setenv_var(e, "HOME", passwd->pw_dir);
	endpwent();
	if (uname(&uts_name) < 0)
		return ;
	env_setenv_var(e, "HOST", uts_name.nodename);
	env_setenv_var(e, "MACHTYPE", uts_name.machine);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:04:55 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/12 18:01:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define EXPAND(A, B) # A # B
# define ERROR(A, B) EXPAND(A, B)
# define SH ft_minishell2 :\t
# define SETENV setenv :\t
# define UNSETENV unsetenv :\t
# define ECHO echo :t
# define EXIT exit :\t
# define CD cd :\t
# define E_GENERIC An error occured.\n
# define E_TOO_MANY_ARG Error. Too many arguments.\n
# define E_NOT_ENOUGH_ARG Error. Not enough arguments.\n
# define E_INPUT Error on input. Is your input reasonnable ?\n
# define E_ENVBROK env variable may be brocken.\n
# define E_ENVFAIL unsable to set env variable (use setenv ?)\n
# define E_HOMEBROK home variable may be broken.\n
# define E_PATHBROK path variable may be broken.\n
# define E_OWDBROK owd (old pwd) variable may be broken.\n
# define E_CWDBROK cwd (pwd) variable may be broken.\n
# define E_TERMBROK term variable may be broken.\n
# define E_VARNOTSET a var requested is unknown.\n
# define E_HOMEDOUBT home variable may not be set correctly.\n
# define E_INVALID_OPTION invalid option.\n
# define E_PATHNEXISTS requested path does not exists.\n
# define E_NODIR requested path is not a directory.\n
# define E_NO_OWD OLDPWD is unset.\n
# define E_NOHOME HOME var is unset.\n
# define E_WRGFILETYPE wrong filetype.\n
# define E_NOTX file is not executable.\n
# define E_NOFILEORDIR no such file or directory.\n
# define E_CMDNOTFOUND command not found.\n

#endif

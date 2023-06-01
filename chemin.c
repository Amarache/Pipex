/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chemin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:11:24 by yamarach          #+#    #+#             */
/*   Updated: 2023/04/17 12:32:29 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_path(char *av, char **cmd, char **envp)
{
	if (strchr_slash(av) == 1)
	{
		if ((access(av, F_OK)) == 0)
		{
			execve(av, cmd, envp);
		}
	}
}

int	strchr_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:56:39 by yamarach          #+#    #+#             */
/*   Updated: 2023/04/17 14:15:08 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_cmd(t_vars *all, char **cmd, int *fd)
{
	if (cmd == NULL || !cmd[0])
	{
		write(2, "zsh: command not found:\n", 24);
		close (fd[1]);
		free_path(all->all_path);
		free(all);
		if (cmd)
			free(cmd);
		exit(1);
	}
}

void	exe_cmd2(t_vars *all, char **cmd, int *fd)
{
	if (cmd == NULL || !cmd[0])
	{
		write(2, "zsh: command not found2:\n", 25);
		close (fd[0]);
		free_path(all->all_path);
		free(all);
		if (cmd)
			free(cmd);
		exit(1);
	}
}

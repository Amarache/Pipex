/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:14:24 by yamarach          #+#    #+#             */
/*   Updated: 2023/04/17 15:59:24 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(char **av, t_vars *all, int *fd, char **envp)
{
	char	**cmd;
	char	*path;
	int		infile;

	close (fd[0]);
	cmd = ft_split(av[2], ' ');
	exe_cmd(all, cmd, fd);
	path = test_cmd(all->all_path, cmd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		free_child1(all, fd, cmd, path);
	dup2(infile, 0);
	dup2(fd[1], 1);
	exe_path(cmd[0], cmd, envp);
	echec_cmd(path, all, cmd, fd);
	execve(path, cmd, envp);
}

void	child2(char **av, t_vars *all, int *fd, char **envp)
{
	char	**cmd;
	char	*path;
	int		outfile;

	close(fd[1]);
	cmd = ft_split(av[3], ' ');
	exe_cmd2(all, cmd, fd);
	path = test_cmd(all->all_path, cmd[0]);
	outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (outfile < 0)
		free_child2(all, cmd, path);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	exe_path(cmd[0], cmd, envp);
	echec_cmd2(path, all, cmd, outfile, fd);
	execve(path, cmd, envp);
}

void	echec_cmd(char *path, t_vars *all, char **cmd, int *fd)
{
	if (path == NULL)
	{
		write(2, "zsh: command not found1:\n", 25);
		close(fd[1]);
		close (fd[0]);
		free_path(all->all_path);
		free_path(cmd);
		free(all);
		exit(1);
	}
}

void	echec_cmd2(char *path, t_vars *all, char **cmd, int outfile, int *fd)
{
	if (path == NULL)
	{
		write(2, "zsh: command not found2:\n", 25);
		close (fd[0]);
		close(outfile);
		free_path(all->all_path);
		free_path(cmd);
		free(all);
		exit(1);
	}
}

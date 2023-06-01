/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:54:41 by yamarach          #+#    #+#             */
/*   Updated: 2023/04/17 14:08:14 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_parent_process(t_vars *all)
{
	int	wstatus;
	int	exitcode;

	waitpid(all->pid, NULL, 0);
	waitpid(all->pid2, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		exitcode = WEXITSTATUS(wstatus);
	}
	return (exitcode);
}

int	main(int ac, char **av, char **envp)
{
	t_vars	*all;
	int		statuscode;
	int		fd[2];

	all = malloc(sizeof(t_vars));
	if (ac != 5)
		return (free(all), (write (2, "wrong numbers of argument\n", 26), 1));
	all->all_path = ft_path(envp);
	if (pipe(fd) == -1)
		return (1);
	all->pid = fork();
	if (all->pid == 0)
		child1(av, all, fd, envp);
	all->pid2 = fork();
	if (all->pid2 == 0)
		child2(av, all, fd, envp);
	close(fd[0]);
	close(fd[1]);
	statuscode = ft_parent_process(all);
	return (free_path(all->all_path), free(all), (statuscode));
}

char	**ft_path(char **envp)
{
	int		i;
	int		j;
	char	**path;

	path = NULL;
	i = 0;
	if (envp)
	{
		while (envp[i])
		{
			j = 0;
			if (envp[i][j] == 'P' && envp[i][j + 1] == 'A' &&
					envp[i][j + 2] == 'T' && envp[i][j + 3] == 'H'
						&& envp[i][j + 4] == '=')
			{
				envp[i] += 5;
				path = ft_split (envp[i], ':');
				break ;
			}
			i++;
		}
	}
	return (path);
}

char	*test_cmd(char **path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*command;

	i = 0;
	if (path)
	{
		while (path[i])
		{
			tmp = ft_strjoin(path[i], "/");
			command = ft_strjoin(tmp, cmd);
			if ((access(command, F_OK)) == 0)
			{
				free(tmp);
				return (command);
			}
			free(command);
			free(tmp);
			i++;
		}
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:48:55 by yamarach          #+#    #+#             */
/*   Updated: 2023/04/17 14:20:55 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	free_child1(t_vars *all, int *fd, char **cmd, char *path)
{
	write (1, "no such file or directory1:\n", 28);
	close (fd[1]);
	free_path(all->all_path);
	free_path(cmd);
	free(path);
	free(all);
	exit(1);
}

void	free_child2(t_vars *all, char **cmd, char *path)
{
	write (1, "no such file or directory1:\n", 28);
	free_path(all->all_path);
	free_path(cmd);
	free(path);
	free(all);
	exit(1);
}

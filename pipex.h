/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:42:41 by yamarach          #+#    #+#             */
/*   Updated: 2023/04/17 15:58:01 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/types.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_vars
{
	char	**all_path;
	char	*cmd;
	int		ac;
	char	**av;
	char	**envp;
	int		infile;
	int		outfile;
	pid_t	pid;
	pid_t	pid2;
}			t_vars;

/////////// LIBFT ///////////
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);

/////////// PIPEX ///////////
char	**ft_path(char **envp);
char	*test_cmd(char **path, char *cmd);
void	child1(char **av, t_vars *all, int *fd, char **envp);
void	child2(char **av, t_vars *all, int *fd, char **envp);
void	free_path(char **str);
int		strchr_slash(char *str);
void	echec_cmd(char *path, t_vars *all, char **cmd, int *fd);
void	exe_cmd(t_vars *all, char **cmd, int *fd);
void	exe_cmd2(t_vars *all, char **cmd, int *fd);
void	exe_path(char *av, char **cmd, char **envp);
int		ft_parent_process(t_vars *all);
void	free_child1(t_vars *all, int *fd, char **cmd, char *path);
void	free_child2(t_vars *all, char **cmd, char *path);
void	echec_cmd2(char *path, t_vars *all, char **cmd, int outfile, int *fd);

#endif

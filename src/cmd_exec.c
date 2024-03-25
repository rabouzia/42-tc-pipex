/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:17:30 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/21 10:48:46 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exec(char **env, char *avn)
{
	char	**res;
	int		i;
	char	**cmd_args;
	char	*tmp2;
	char	*result;

	result = NULL;
	i = 0;
	res = NULL;
	while (env[i] && strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (env[i])
		res = ft_split(env[i], ':');
	cmd_args = ft_split(avn, ' '); // av[3] pour le 2
	i = 0;
	while (res[i])
	{
		tmp2 = ft_strjoin(res[i], "/");
		result = ft_strjoin(tmp2, cmd_args[0]); // possible leak
		if (access(result, F_OK) == 0)
			break ;
		free(result);
		free(tmp2);
		i++;
	}
	if (execve(result, cmd_args, env) == -1)
		perror("error is");
	exit(0);
}

void	child_process(char **env, int fde, int fd, char *av, int bool, int bool2)
{
	dup2(fde, bool);
	close(fde);
	dup2(fd, bool2);
	close(fd);
	cmd_exec(env, av);
}

void	warp_pipe(char **av, char **env, int fd1, int fd2)
{
	int	fd[2];
	int	pid;
	int	fde;

	if (pipe(fd) == -1)
		perror("pipe error");
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
	close(fd[0]); // fd utiliser chez le parent donc inutile pour lenfant
	fde = open(av[fd1], O_RDONLY, 0644);
	if (!fde)
		return ;
	child_process(env, fde, fd[1], av[2], 0, 1);
	}
	else
	{
	close(fd[1]); // fd utiliser chez lenfant donc inutile pour le parent
	fde = open(av[fd2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fde)
		return ;
	child_process(env, fde, fd[0], av[3], 1 ,0);
	}
}

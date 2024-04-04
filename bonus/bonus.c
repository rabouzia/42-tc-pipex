/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:49:08 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/04 18:00:48 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd_get(char *cmd)
{
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' '); // av[3] pour le 2
	if (!split_cmd || !split_cmd[0])
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		free(split_cmd);
		exit(127);
	}
	return (split_cmd);
}

int	flag_out(t_pipe *pipex)
{
	if (pipex->flag == 1)
		return (O_WRONLY | O_CREAT | O_APPEND);
	else
		return (O_WRONLY | O_CREAT | O_TRUNC);
}

int	ac_loop(t_pipe *pipex)
{
	pid_t	pid;

	pipex->i = 3;
	while (pipex->ac - 2 > pipex->i)
	{
		pipex->oldfd = pipex->pipe[0];
		if (pipe(pipex->pipe) == -1)
			return (close(pipex->oldfd), -1);
		pid = fork();
		if (pid == -1)
			return (close(pipex->pipe[0]), close(pipex->oldfd), close(pipex->pipe[1]), -1);
		if (pid == 0)
			child_loop(pipex);
		close(pipex->pipe[1]);
		close(pipex->oldfd);
		pipex->i++;
	}
	return (0);
}
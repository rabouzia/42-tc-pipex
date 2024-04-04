/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:49:08 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/04 15:37:07 by ramzerk          ###   ########.fr       */
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

int	flag_out(int flag)
{
	if (flag == 1)
		return (O_WRONLY | O_CREAT | O_APPEND);
	else
		return (O_WRONLY | O_CREAT | O_TRUNC);
}

int	ac_loop(char **av, char **env, int ac, int pipe_fd[2])
{
	int		i;
	int		c_fd;
	pid_t	pid;

	i = 3;
	while (ac - 2 > i)
	{
		c_fd = pipe_fd[0];
		if (pipe(pipe_fd) == -1)
			return (close(c_fd), -1);
		pid = fork();
		if (pid == -1)
			return (close(pipe_fd[0]), close(c_fd), close(pipe_fd[1]), -1);
		if (pid == 0)
			child_loop(c_fd, pipe_fd, av[i], env);
		close(pipe_fd[1]);
		close(c_fd);
		i++;
	}
	return (0);
}
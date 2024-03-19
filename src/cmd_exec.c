/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:17:30 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/18 14:33:13 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exec_1(char **av, char **env)
{
	char	**res;
	int		i;
	char	**cmd_args;
	int		acc;
	char	*tmp2;
	char	*result;

	result = NULL;
	
	res = ft_split(env[12], ':');
	res[0] = ft_substr(res[0], 5, 22);
	cmd_args = ft_split(av[2], ' ');
	acc = 0;
	i = 0;
	while (res[i])
	{
		tmp2 = ft_strjoin(res[i], "/");
		result = ft_strjoin(tmp2, cmd_args[0]); // possible leak
		free(tmp2);
		acc = access(result, F_OK);
		if (acc == 0)
			// perror("arguement not found");
			break ;
		i++;
	}
	if (execve(result, cmd_args, env) == -1)
		perror("error is");
}

void	cmd_exec_2(char **av, char **env)
{
	char	**res;
	int		i;
	char	**cmd_args;
	int		acc;
	char	*tmp2;
	char	*result;

	
	result = NULL;
	res = ft_split(env[12], ':');
	res[0] = ft_substr(res[0], 5, 22);
	cmd_args = ft_split(av[3], ' ');
	acc = 0;
	i = 0;
	while (res[i])
	{
		tmp2 = ft_strjoin(res[i], "/");
		result = ft_strjoin(tmp2, cmd_args[0]); // possible leak
		free(tmp2);
		acc = access(result, F_OK);
		if (acc == 0)
			break ;
		i++;
	}
	if (execve(result, cmd_args, env) == -1)
		perror("error is");
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
		fde = 0;
		close(fd[0]); // fd utiliser chez le parent donc inutile pour lenfant
		fde = open(av[fd1], O_RDONLY, 0644);
		if (!fde)
			return ;
		dup2(fde, 0);
		close(fde);
		dup2(fd[1], 1);
		close(fd[1]);
		cmd_exec_1(av, env);
	}
	else
	{
		fde = 0;
		close(fd[1]); // fd utiliser chez lenfant donc inutile pour le parent
		fde = open(av[fd2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (!fde)
			return ;
		dup2(fde, 1);
		close(fde);
		dup2(fd[0], 0);
		close(fd[0]);
		cmd_exec_2(av, env);
	}
}

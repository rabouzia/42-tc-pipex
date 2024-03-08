/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:17:30 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/08 19:21:45 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exec(char **av, char **env)
{
	char	**res;
	int		i;
	char	**cmd_args;
	int		acc;
	char	*tmp2;
	char	*result;

	res = ft_split(env[12], ':');
	res[0] = ft_substr(res[0], 5, 22);
	cmd_args = ft_split(av[1], ' ');
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

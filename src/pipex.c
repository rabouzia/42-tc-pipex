/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:45:21 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/18 14:11:19 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	// t_cmd *exec;
	(void)ac;
	if (ac != 5 || !env || !*env)
		return (0);
	if (ac == 1)
		perror("arg");
	warp_pipe(av, env, 1, 4);
}

// gnl(0) pour les bonus
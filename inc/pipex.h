/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:45:25 by ramzerk           #+#    #+#             */
/*   Updated: 2024/03/19 22:52:26 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	int	fd_in;
	int	fd_out;
	int	pid;

}		t_cmd;

// ---------------- mini_libft ----------------
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);

//---------------- pipexu --------------------
void	cmd_exec_1(char **av, char **env);
void	cmd_exec_2(char **av, char **env);

//---------------- mini_libft_dump -------------
char	*empty(void);
char	*get_next_word(char *str, int *ptr, char c);
int		count_words(char *str, char c);
int		ft_strlcpy(char *dst, char *src, int size);
void	warp_pipe(char **av, char **env, int fd1, int);

#endif

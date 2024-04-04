/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:45:25 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/04 17:52:21 by ramzerk          ###   ########.fr       */
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
	int	id;
	char *cmd;
}		t_cmd;

// in->cmd->pipe_w->oldfd->cmd->pipe_w->pipe_r->cmd->out

// in->cmd->pipe_w->oldfd->cmd->pipe_w->oldfd->cmd->pipe_w->oldfd->cmd->pipe_w->pipe_r->cmd->out

typedef struct s_pipe
{
	int	fd_in;
	int	fd_out;
	int pipe[2];
	int	oldfd;
	char **env;
	char **av;
	int flag;
	int ac;
	int	i;
}	t_pipe;

//---------------- pipexu --------------------
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	excute(char **cmd, char **env);
void	error_msg(char *path, char **cmd);

//---------------- pipex_bonus -------------
void 	child_loop(t_pipe *pipex);
int		ac_loop(t_pipe *pipex);
int		flag_out(t_pipe *pipex);
char	**cmd_get(char *cmd);


// ---------------- mini_libft ----------------
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *src);
char	*empty(void);
char	*get_next_word(char *str, int *ptr, char c);
int		count_words(char *str, char c);
int		ft_strlcpy(char *dst, char *src, int size);
void	warp_pipe(char **av, char **env);
#endif

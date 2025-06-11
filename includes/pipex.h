/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:19:24 by mwilline          #+#    #+#             */
/*   Updated: 2025/05/21 17:12:10 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	execute(char *cmd, char **envp);
char	*get_path_env(char **envp);
void	free_and_exit(char **arg, char **paths, char *msg, int code);
void	ft_free_array(char **arg);
void	error(char *msg, int exit_code);
int		find_valid_path(char **paths, char **arg, char **envp);

#endif

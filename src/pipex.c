/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:19:14 by mwilline          #+#    #+#             */
/*   Updated: 2025/05/21 15:48:19 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	find_valid_path(char **paths, char **arg, char **envp)
{
	int		i;
	char	*temp;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp, arg[0]);
		free(temp);
		if (!full_path)
			return (0);
		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, arg, envp);
			free(full_path);
			return (1);
		}
		free(full_path);
		i++;
	}
	return (0);
}

void	execute(char *cmd, char **envp)
{
	char	**arg;
	char	*path_env;
	char	**paths;

	arg = ft_split(cmd, ' ');
	if (!arg)
		error("malloc error", 1);
	path_env = get_path_env(envp);
	if (!path_env)
		free_and_exit(arg, NULL, "PATH not found", 1);
	paths = ft_split(path_env, ':');
	if (!paths)
		free_and_exit(arg, NULL, "malloc error", 1);
	if (!find_valid_path(paths, arg, envp))
		free_and_exit(arg, paths, "command not found", 127);
	free_and_exit(arg, paths, "execve failed", 126);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:18:57 by mwilline          #+#    #+#             */
/*   Updated: 2025/05/21 15:46:42 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child1(int *fdp, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("no such file or directory", 1);
	if (dup2(fd, STDIN_FILENO) == -1)
		error("Dup failed", 1);
	if (dup2(fdp[1], STDOUT_FILENO) == -1)
		error("Dup failed", 1);
	close(fd);
	close(fdp[1]);
	close(fdp[0]);
	execute(argv[2], envp);
}

void	child2(int *fdp, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error("no such file or directory", 1);
	if (dup2(fdp[0], STDIN_FILENO) == -1)
		error("Dup failed", 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		error("Dup failed", 1);
	close(fd);
	close(fdp[1]);
	close(fdp[0]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error("Invalid number of arguments", 1);
	if (pipe(fd) == -1)
		error("Pipe failed", 1);
	pid1 = fork();
	if (pid1 == -1)
		error("Fork failed", 1);
	if (pid1 == 0)
		child1(fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		error("Fork failed", 1);
	if (pid2 == 0)
		child2(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

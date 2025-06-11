/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:14:33 by mwilline          #+#    #+#             */
/*   Updated: 2025/05/21 17:15:19 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(char *msg, int exit_code)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(exit_code);
}

void	ft_free_array(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	if (arg)
		free(arg);
}

void	free_and_exit(char **arg, char **paths, char *msg, int code)
{
	ft_free_array(arg);
	ft_free_array(paths);
	error(msg, code);
}

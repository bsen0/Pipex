/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:00:41 by bsen              #+#    #+#             */
/*   Updated: 2024/03/08 13:06:00 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	child1(char **env, int *pipefd, char **av, char *path)
{
	int		pid;
	int		fd;
	char	**split;

	split = ft_split(av[2], ' ');
	pid = fork();
	if (pid == -1)
	{
		perror("Fault message: ");
		exit(1);
	}
	if (pid == 0)
	{
		close(pipefd[0]);
		fd = open(av[1], O_RDWR);
		if (fd == -1)
		{
			perror("Fault message: ");
			exit(1);
		}
		dup2(fd, 0);
		dup2(pipefd[1], 1);
		execve(path, split, env);
	}
	ft_free(split);
}

void	child2(char **env, int *pipefd, char **av, char *path)
{
	int	pid;
	int	fd;

	pid = fork();
	if (pid == -1)
	{
		perror("Fault message: ");
		exit(1);
	}
	if (pid == 0)
	{
		close(pipefd[1]);
		fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd == -1)
		{
			perror("Fault message: ");
			exit(1);
		}
		dup2(pipefd[0], 0);
		dup2(fd, 1);
		execve(path, ft_split(av[3], ' '), env);
	}
	close(pipefd[0]);
	close(pipefd[1]);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:48:32 by bsen              #+#    #+#             */
/*   Updated: 2024/03/15 12:46:26 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	exit_message(char *s, char **s2, int i)
{
	if (i == 1)
		free(s);
	ft_free(s2);
	ft_putstr_fd("Fault message: There is no way.", 2);
	exit(1);
}

static char	*check_cmd(char *way)
{
	if (access(way, F_OK) == 0)
		return (way);
	free(way);
	return (0);
}

static char	**find_way(char **env)
{
	char	**cmd_way;
	char	*sub;

	while (*env && !ft_strnstr(*env, "PATH=", 5))
		(*env)++;
	sub = ft_substr(*env, 5, ft_strlen(*env) - 5);
	cmd_way = ft_split(sub, ':');
	if (!cmd_way)
	{
		ft_free(cmd_way);
		free(sub);
		return (0);
	}
	free(sub);
	return (cmd_way);
}

static char	*find_path(char **env, char *cmd)
{
	char	*path;
	char	**cmd_path;
	char	**cmd_cpy;
	char	*way;
	int		i;

	path = NULL;
	cmd_cpy = ft_split(cmd, ' ');
	if (!*cmd_cpy)
		exit_message(path, cmd_cpy, 0);
	cmd_path = find_way(env);
	path = ft_strjoin("/", cmd_cpy[0]);
	ft_free(cmd_cpy);
	i = -1;
	while (cmd_path[++i])
	{
		way = check_cmd(ft_strjoin(cmd_path[i], path));
		if (way)
		{
			free(path);
			ft_free(cmd_path);
			return (way);
		}
	}
	return (exit_message(path, cmd_path, 1), NULL);
}

int	main(int ac, char **av, char **env)
{
	int		pipeid[2];
	int		pipectl;
	char	*path;
	char	*path1;

	if (!env)
		exit(1);
	if (ac != 5)
		exit(1);
	if (!av[2] || !av[3])
		exit(1);
	pipectl = pipe(pipeid);
	if (pipectl == -1)
		exit(1);
	path = find_path(env, av[2]);
	child1(env, pipeid, av, path);
	waitpid(-1, NULL, 0);
	free(path);
	path1 = find_path(env, av[3]);
	child2(env, pipeid, av, path1);
	waitpid(-1, NULL, 0);
	free(path1);
	return (0);
}

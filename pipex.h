/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:08:49 by bsen              #+#    #+#             */
/*   Updated: 2024/03/06 15:23:06 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

void	ft_free(char **s);
void	child1(char **env, int *pipefd, char **av, char *path);
void	child2(char **env, int *pipefd, char **av, char *path);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:55:25 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:28:23 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_mlx_setup(t_scene *rt)
{
	errno = 85;
	perror("Type: Cannot setup mlx\nerrno 85");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_scene(rt);
	exit(INVALID);
}

void	e_mlx_screen_connection(t_scene *rt)
{
	errno = 49;
	perror("Type: Creation of screen connection\nerrno 49");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_scene(rt);
	exit(INVALID);
}

void	e_mlx_window(t_scene *rt)
{
	errno = 49;
	perror("Type: Creation of window\nerrno 49");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_scene(rt);
	exit(INVALID);
}

void	e_mlx_image(t_scene *rt)
{
	errno = 49;
	perror("Type: Creation of image\nerrno 49");
	write(STDERR_FILENO, "ERROR\n", 6);
	free_scene(rt);
	exit(INVALID);
}

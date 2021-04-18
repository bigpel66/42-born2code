/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:24:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 20:44:19 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	get_info(t_mlx *m, char **line, t_bool id)
{
	t_bool	ret;

	ret = FALSE;
	if (id == RESOLUTION)
		ret = get_resolution(m, line);
	else if (id == AMBIENT)
		ret = get_ambient(m, line);
	else if (id == CAMERA)
		ret = get_camera(m, line);
	else if (id == LIGHT)
		ret = get_light(m, line);
	else if (id == SPHERE)
		ret = get_sphere(m, line);
	else if (id == PLANE)
		ret = get_plane(m, line);
	else if (id == SQUARE)
		ret = get_square(m, line);
	else if (id == CYLINDER)
		ret = get_cylinder(m, line);
	else if (id == TRIANGLE)
		ret = get_triangle(m, line);
	return (ret);
}

static t_bool	scene_parse(t_mlx *m, char *line)
{
	t_bool	id;

	id = FALSE;
	if (!ft_strncmp(line, "", ft_strlen(line)))
		return (TRUE);
	while (is_blank(*line))
		++line;
	id = is_identifier(&line);
	if (!id || !get_info(m, &line, id))
		return (FALSE);
	return (TRUE);
}

static void		scene_open(t_mlx *m, const char *filename)
{
	char	*line;
	char	*extname;
	int		fd;
	int		ret;

	extname = ft_strchr(filename, '.');
	if (!extname || ft_strncmp(extname, ".rt", 3))
		e_file_extname();
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		e_file_open();
	while (1)
	{
		ret = ft_gnl(fd, &line);
		if (ret < 0)
			e_file_read();
		if (!scene_parse(m, line))
			e_file_parsing((void **)(&line));
		free_ptr((void **)(&line));
		if (ret == 0)
			break ;
	}
}

int				main(int argc, char **argv)
{
	t_mlx	m;

	// print_error_list();
	if (argc != 2)
		e_argument();
	scene_open(&m, argv[1]);
	mlx_ready(&m);
	mlx_loop(m.sid);
	return (VALID);
}

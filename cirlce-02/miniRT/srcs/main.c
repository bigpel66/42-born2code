/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:24:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 13:13:49 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			mlx_ready(t_mlx *m)
{
	m->sid = mlx_init();
	if (!(m->sid))
		e_screen_connection();
	m->wid = mlx_new_window(m->sid, 400, 300, "miniRT");
	if (!(m->wid))
		e_window();
}

static t_bool	scene_parse()
{
	ssize_t	r;

	r = 10;
}

static void		scene_open(t_mlx *m, const char *filename)
{
	char	*buf;
	char	*extname;
	int		fd;

	if (!dalloc((void **)(&buf), BUFFER_SIZE + 1, sizeof(char)))
		e_memory();
	extname = ft_strchr(filename, '.');
	if (!extname || ft_strncmp(extname, ".rt", 3))
		e_file_extname();
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		e_file_descriptor();
	if (!scene_parse())
		e_file_parsing();
}

int				main(int argc, char **argv)
{
	t_mlx	m;

	print_error_list();
	if (argc != 2)
		e_argument();
	scene_open(&m, argv[1]);
	mlx_ready(&m);
	mlx_loop(m.sid);
	return (VALID);
}

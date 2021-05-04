/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 00:27:49 by jseo              #+#    #+#             */
/*   Updated: 2021/05/04 00:27:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_hit_point(t_ray r, t_color c, double t, t_hit *rec)
{
	rec->t = t;
	rec->p = add(r.p, scale(r.o, t));
	rec->c = c;
}

void	set_normal(t_obj obj, t_ray r, t_vec3 n, t_hit *rec)
{
	rec->n = n;
	rec->f = FRONT;
	if (dot(r.o, n) >= 0)
	{
		rec->n = flip(n);
		rec->f = BACK;
	}
	rec->mat = obj.mat;
	rec->fuzz = obj.fuzz;
	rec->ir = obj.ir;
}

t_bool	obj_hit(t_p *p, t_ray r, t_hit *rec, t_bool hit)
{
	int		i;
	t_bool	ret;
	double	dist_so_far;

	i = -1;
	dist_so_far = INFINITY;
	while (++i < p->m->rt.cnt.obj)
	{
		if (p->m->obj[i].type == SPHERE)
			ret = hit_sp(p->m->obj[i], r, dist_so_far, rec);
		else if (p->m->obj[i].type == PLANE)
			ret = hit_pl(p->m->obj[i], r, dist_so_far, rec);
		else if (p->m->obj[i].type == SQUARE)
			ret = hit_sq(p->m->obj[i], r, dist_so_far, rec);
		else if (p->m->obj[i].type == CYLINDER)
			ret = hit_cy(p->m->obj[i], r, dist_so_far, rec);
		else if (p->m->obj[i].type == TRIANGLE)
			ret = hit_tr(p->m->obj[i], r, dist_so_far, rec);
		if (ret)
		{
			hit = TRUE;
			dist_so_far = rec->t;
		}
	}
	return (hit);
}

t_bool	obj_visible(t_obj *obj, int cnt, t_ray r, double lim)
{
	int	i;

	i = -1;
	while (++i < cnt)
	{
		if (obj[i].type == SPHERE && interfere_sp(obj[i], r, lim))
			return (0);
		else if (obj[i].type == PLANE && interfere_pl(obj[i], r, lim))
			return (0);
		else if (obj[i].type == SQUARE && interfere_sq(obj[i], r, lim))
			return (0);
		else if (obj[i].type == CYLINDER && interfere_cy(obj[i], r, lim))
			return (0);
		else if (obj[i].type == TRIANGLE && interfere_tr(obj[i], r, lim))
			return (0);
	}
	return (1);
}
/// @todo header

#include "minirt.h"

static double	intersect_pl(const t_plane *pl, double os_dot_odir,
	const t_vec3 *ray_dir)
{
	double	t;
	double	raydir_dot_odir;

	raydir_dot_odir = ft_dot_vec3(&pl->n, ray_dir);
	t = solve_eq_pl(os_dot_odir, raydir_dot_odir);
	return (t);
}

void	intersect_ray_pl(const t_obj *obj, t_intersec *inter)
{
	t_plane_obj	*pl_obj;
	double		t;

	pl_obj = (t_plane_obj *)obj->data;
	t = intersect_pl(&pl_obj->pl, pl_obj->math_os_dot_odir, &inter->ray.dir);
	if (t >= inter->soluce.t)
		return ;
	inter->soluce.t = t;
	inter->soluce.p = ft_translation(&inter->ray.s, &inter->ray.dir, t);
	if (0.0 < ft_dot_vec3(&pl_obj->pl.n, &inter->ray.dir))
		inter->soluce.n = ft_scalmult_vec3(&pl_obj->pl.n, -1);
	else
		inter->soluce.n = pl_obj->pl.n;
	inter->obj = obj;
}

double	intersect_light_pl(const t_obj *obj, const t_ray *ray)
{
	t_plane_obj	*pl_obj;
	double		t;
	double		os_dot_odir;

	pl_obj = (t_plane_obj *)obj->data;
	init_math_pl(&ray->s, &pl_obj->pl, &os_dot_odir);
	t = intersect_pl(&pl_obj->pl, os_dot_odir, &ray->dir);
	return (t);
}

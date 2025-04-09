/// @todo header

#include "minirt.h"

static double	intersect_pl(const t_plane *pl, double os_dot_odir, const t_vec3 *ray_dir)
{
	double	result;
	double	raydir_dot_odir;

	raydir_dot_odir = ft_dot_vec3(&pl->n, ray_dir);
	result = solve_eq_pl(os_dot_odir, raydir_dot_odir);
	return (result);
}

double	intersect_ray_pl(const t_obj *obj, const t_vec3 *ray_dir)
{
	double		result;
	t_plane_obj	*pl_obj;

	pl_obj = (t_plane_obj *)obj->data;
	result = intersect_pl(&pl_obj->pl, pl_obj->math_os_dot_odir, ray_dir);
	return (result);
}

double	intersect_light_pl(const t_obj *obj, const t_ray *ray)
{
	double		result;
	t_plane_obj	*pl_obj;
	double		os_dot_odir;

	pl_obj = (t_plane_obj *)obj->data;
	init_math_pl(&ray->s, &pl_obj->pl, &os_dot_odir);
	result = intersect_pl(&pl_obj->pl, os_dot_odir, &ray->dir);
	return (result);
}

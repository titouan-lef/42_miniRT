/// @todo header

#include "minirt.h"

double	intersect_ray_plane_value(double os_dot_odir, double raydir_dot_odir)
{
	double	t;

	if (raydir_dot_odir == 0)
		return (INFINITY);
	t = -os_dot_odir / raydir_dot_odir;
	if (t < 1)
		return (INFINITY);
	return (t);
}

double	intersect_ray_plane(const t_plane_obj *plane, const t_ray *ray)
{
	double	raydir_dot_odir;
	double	t;

	raydir_dot_odir = ft_dot_vec3(&plane->pl.n, &ray->dir);
	t = intersect_ray_plane_value(plane->math_os_dot_odir, raydir_dot_odir);
	return (t);
}

double	intersect_light_plane(const t_plane_obj *plane, const t_ray *ray)
{
	double	raydir_dot_odir;
	double	math_os_dot_odir;
	double	t;

	math_os_dot_odir = plane->pl.d + ft_dot_vec3(&plane->pl.n, &ray->s);
	raydir_dot_odir = ft_dot_vec3(&plane->pl.n, &ray->dir);
	t = intersect_ray_plane_value(math_os_dot_odir, raydir_dot_odir);
	return (t);
}

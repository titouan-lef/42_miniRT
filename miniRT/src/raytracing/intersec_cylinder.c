/// @todo header

#include "minirt.h"

static int	is_in_height(double t, const t_ray *ray, const t_cylinder_obj *cyl)
{
	t_vec3	p;
	double	height;

	p = ft_translation(&ray->s, &ray->dir, t);
	p = ft_diff_vec3(&p, &cyl->cy.pos);
	height = ft_dot_vec3(&p, &cyl->cy.dir);
	if (height < 0)
		height = -height;
	return (height <= cyl->cy.hh);
}

static double	a_calculation(double raydir_dot_odir)
{
	return (1 - raydir_dot_odir * raydir_dot_odir);
}

static double	b_calculation(const t_vec3 *os, const t_vec3 *raydir,
	double os_dot_odir, double raydir_dot_odir)
{
	double	dot;

	dot = ft_dot_vec3(os, raydir);
	return (2.0 * (dot - os_dot_odir * raydir_dot_odir));
}

static double	intersect_caps(const t_cylinder_obj *cy_obj, const t_ray *ray,
	double dist, double raydir_dot_odir)
{
	t_vec3	p;
	double	t;

	t = intersect_ray_plane_value(cy_obj->mathcy.bs_dot_odir, raydir_dot_odir);
	if (t != INFINITY && t < dist)
	{
		p = ft_translation(&ray->s, &ray->dir, t);
		if (ft_distance_vec3(&p, &cy_obj->mathcy.b) <= cy_obj->cy.r)
			dist = t;
	}
	t = intersect_ray_plane_value(cy_obj->mathcy.ts_dot_odir, raydir_dot_odir);
	if (t != INFINITY && t < dist)
	{
		p = ft_translation(&ray->s, &ray->dir, t);
		if (ft_distance_vec3(&p, &cy_obj->mathcy.t) <= cy_obj->cy.r)
			dist = t;
	}
	return (dist);
}

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details
 */
double	intersect_ray_cylinder(const t_cylinder_obj *cyl, const t_ray *ray)
{
	double	a;
	double	b;
	double	raydir_dot_odir;
	double	result;

	raydir_dot_odir = ft_dot_vec3(&ray->dir, &cyl->cy.dir);
	a = a_calculation(raydir_dot_odir);
	b = b_calculation(&cyl->mathcy.os, &ray->dir, cyl->mathcy.os_dot_odir,
			raydir_dot_odir);
	result = quadratic_equation(a, b, cyl->mathcy.c_factor);
	if (result != INFINITY && !is_in_height(result, ray, cyl))
		result = INFINITY;
	result = intersect_caps(cyl, ray, result, raydir_dot_odir);
	return (result);
}

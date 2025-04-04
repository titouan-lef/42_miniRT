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
	return (height <= cyl->cy.h / 2.0);
}

static double	a_calculation(double raydir_dot_odir)
{
	return (1 - raydir_dot_odir * raydir_dot_odir);
}

static double	b_calculation(const t_vec3 *os, const t_vec3 *raydir, double os_dot_odir, double raydir_dot_odir)
{
	double	dot;

	dot = ft_dot_vec3(os, raydir);
	return (2.0 * (dot - os_dot_odir * raydir_dot_odir));
}

static double	intersect_ray_plan_test(const t_vec3 *plan_pos, const t_vec3 *normal, const t_ray *ray)
{
	t_plane	plane;
	double	scal_product;
	double	t;

	plane = ft_create_plane(normal, plan_pos);
	scal_product = ft_dot_vec3(normal, &ray->dir);
	if (scal_product == 0)
		return (INFINITY);
	t = (plane.d + ft_dot_vec3(normal, &ray->s)) / -scal_product;
	if (t < 1)
		return (INFINITY);
	return (t);
}

static double	intersect_cap(const t_cylinder *cy, const t_ray *ray, const t_vec3 *cap_center, double dist)
{
	t_vec3	p;
	double	tmp;

	tmp = intersect_ray_plan_test(cap_center, &cy->dir, ray);
	if (tmp != INFINITY && tmp < dist)
	{
		p = ft_translation(&ray->s, &ray->dir, tmp);
		if (ft_distance_vec3(&p, cap_center) <= cy->r)
			dist = tmp;
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
	b = b_calculation(&cyl->mathcy.os, &ray->dir, cyl->mathcy.os_dot_odir, raydir_dot_odir);
	result = quadratic_equation(a, b, cyl->mathcy.c_factor);
	if (result != INFINITY && !is_in_height(result, ray, cyl))
		result = INFINITY;
	result = intersect_cap(&cyl->cy, ray, &cyl->mathcy.bottom, result);
	result = intersect_cap(&cyl->cy, ray, &cyl->mathcy.top, result);
	return (result);
}

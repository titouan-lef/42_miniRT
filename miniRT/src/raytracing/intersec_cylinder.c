/// @todo header

#include "minirt.h"

static int	is_in_height(double t, const t_ray *ray, const t_cylinder_obj *cyl)
{
	t_vec3	p;
	double		height;

	p = ft_scalarmult_vec3(&ray->dir, t);
	p = ft_sum_vec3(&ray->s, &p);
	p = ft_diff_vec3(&p, &cyl->cy.pos);
	height = ft_dotproduct_vec3(&p, &cyl->cy.dir);
	if (height < 0)
		height = -height;
	return (height <= cyl->cy.h / 2.0);
}

static double	a_calculation(double ray_dir_dot_dir)
{
	return (1 - ray_dir_dot_dir * ray_dir_dot_dir);
}

static double	b_calculation(const t_vec3 *bc_o, const t_vec3 *ray_dir, double bc_o_dot_dir, double ray_dir_dot_dir)
{
	return (2.0 * (ft_dotproduct_vec3(bc_o, ray_dir) - bc_o_dot_dir * ray_dir_dot_dir));
}

static double	c_calculation(const t_vec3 *bc_o, double bc_o_dot_dir, double r)
{
	double	result;

	result = ft_dotproduct_vec3(bc_o, bc_o);
	result -= bc_o_dot_dir * bc_o_dot_dir;
	result -= r * r;
	return (result);
}

static double	intersect_ray_plan_test(const t_vec3 *plan_pos, const t_vec3 *normal, const t_ray *ray)
{
	t_plane		plane;
	double		scal_product;
	double		t;

	plane = ft_create_plane(normal, plan_pos);
	scal_product = ft_dotproduct_vec3(normal, &ray->dir);
	if (scal_product == 0)
		return (INFINITY);
	t = (plane.d + ft_dotproduct_vec3(normal, &ray->s)) / -scal_product;
	if (t < 1)
		return (INFINITY);
	return (t);
}

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details
 */
double	intersect_ray_cylinder(const t_cylinder_obj *cyl, const t_ray *ray)
{
	double	a;
	double	b;
	double	c;
	double	ray_dir_dot_dir;
	double	result;
	t_vec3	p;
	t_vec3	center;
	double	tmp;

	ray_dir_dot_dir = ft_dotproduct_vec3(&ray->dir, &cyl->cy.dir);
	a = a_calculation(ray_dir_dot_dir);
	b = b_calculation(&cyl->mathcy.bc_o, &ray->dir, cyl->mathcy.bc_o_dot_dir, ray_dir_dot_dir);
	c = c_calculation(&cyl->mathcy.bc_o, cyl->mathcy.bc_o_dot_dir, cyl->cy.r);
	result = quadratic_equation(a, b, c);
	if (result != INFINITY && !is_in_height(result, ray, cyl))
		result = INFINITY;
	center = calculation_born(&cyl->cy.pos, &cyl->cy.dir, -cyl->cy.h / 2.0);
	tmp = intersect_ray_plan_test(&center, &cyl->cy.dir, ray);
	if (tmp != INFINITY && tmp < result)
	{
		p = ft_scalarmult_vec3(&ray->dir, tmp);
		p = ft_sum_vec3(&ray->s, &p);
		if (ft_distance_vec3(&p, &center) <= cyl->cy.r)
			result = tmp;
	}
	center = calculation_born(&cyl->cy.pos, &cyl->cy.dir, cyl->cy.h / 2.0);
	tmp = intersect_ray_plan_test(&center, &cyl->cy.dir, ray);
	if (tmp != INFINITY && tmp < result)
	{
		p = ft_scalarmult_vec3(&ray->dir, tmp);
		p = ft_sum_vec3(&ray->s, &p);
		if (ft_distance_vec3(&p, &center) <= cyl->cy.r)
			result = tmp;
	}
	return (result);
}

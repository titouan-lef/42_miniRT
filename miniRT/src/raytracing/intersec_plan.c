/// @todo header

#include "minirt.h"

double	intersect_ray_plan(const t_plane_obj *plane, const t_ray *ray)
{
	double		scal_product;
	double		t;

	scal_product = ft_dot_vec3(&plane->pl.n, &ray->dir);
	if (scal_product == 0)
		return (INFINITY);
	t = (plane->pl.d + ft_dot_vec3(&plane->pl.n, &ray->s)) / -scal_product;
	if (t < 1)
		return (INFINITY);
	return (t);
}

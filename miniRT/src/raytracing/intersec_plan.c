/// @todo header

#include "minirt.h"

double	intersect_ray_plan(t_plane_obj *plane, t_vector3 ray_dir, t_vector3 orig)
{
	double		scal_product;
	double		t;

	scal_product = ft_dotproduct_vector3(plane->pl.n, ray_dir);
	if (scal_product == 0)
		return (INFINITY);
	t = (plane->pl.d + ft_dotproduct_vector3(plane->pl.n, orig)) / -scal_product;
	if (t < 1)
		return (INFINITY);
	return (t);
}

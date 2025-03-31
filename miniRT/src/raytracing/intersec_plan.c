/// @todo header

#include "minirt.h"

t_plane	ft_create_plane(t_vector3 n, t_vector3 p)
{
	t_plane plane;

	plane.a = n.x;
	plane.b = n.y;
	plane.c = n.z;
	plane.d = -n.x * p.x - n.y * p.y - n.z * p.z;

	return (plane);
}

double	intersect_ray_plan(t_plan *plan, t_vector3 ray_dir, t_vector3 orig)
{
	t_vector3	normal;
	t_plane 	plane;
	double		scal_product;
	double		t;

	normal = plan->orientation;
	plane = ft_create_plane(normal, plan->position);
	scal_product = ft_dotproduct_vector3(normal, ray_dir);
	if (scal_product == 0)
		return (INFINITY);
	t = (plane.d + ft_dotproduct_vector3(normal, orig)) / -scal_product;
	if (t < 1)
		return (INFINITY);
	return (t);
}

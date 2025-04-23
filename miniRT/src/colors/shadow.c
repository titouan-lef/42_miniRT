/// @todo header

#include "minirt.h"

static double	intersect_light(t_obj *obj, t_ray *ray)
{
	double	dist;

	if (obj->type == PLANE)
		dist = intersect_light_pl(obj, ray);
	else if (obj->type == SPHERE)
		dist = intersect_light_sp(obj, ray);
	else if (obj->type == CYLINDER)
		dist = intersect_light_cy(obj, ray);
	else if (obj->type == CONE)
		dist = intersect_light_co(obj, ray);
	else
		dist = INFINITY;
	return (dist);
}

int	shadow(t_obj **tab_obj, const t_light *light, const t_vec3 *p)
{
	t_ray	ray;
	double	dist;
	double	dist_min;

	ray.s = light->pos;
	ray.dir = ft_diff_vec3(p, &light->pos);
	dist_min = ft_norm_vec3(&ray.dir);
	ray.dir = ft_normalize_vec3(&ray.dir);
	while (*tab_obj != NULL)
	{
		dist = intersect_light(*tab_obj, &ray);
		if (dist < dist_min - EPSILON)
			return (1);
		++tab_obj;
	}
	return (0);
}

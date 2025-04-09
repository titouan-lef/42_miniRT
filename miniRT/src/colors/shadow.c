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
	else
		dist = INFINITY;
	return (dist);
}
int	shadow(t_list *lst_obj, t_light *light, t_vec3 *p)
{
	t_ray	ray;
	t_obj	*obj;
	double	dist;
	double	dist_min;

	ray.s = light->pos;
	ray.dir = ft_diff_vec3(p, &light->pos);
	dist_min = ft_norm_vec3(&ray.dir);
	ray.dir = ft_normalize_vec3(&ray.dir);
	while (lst_obj)
	{
		obj = (t_obj *)lst_obj->content;
		dist = intersect_light(obj, &ray);
		if (dist < dist_min - 0.01)//@todo check precision
			return (1);
		lst_obj = lst_obj->next;
	}
	return (0);
}

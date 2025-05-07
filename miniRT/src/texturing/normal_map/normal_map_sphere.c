/// @todo header

#include "minirt.h"

static void	fill_tangent_space(const t_vec3 *op, t_base *base)
{
	base->e2.x = -op->y * 2 * M_PI;
	base->e2.y = op->x * 2 * M_PI;
	base->e2.z = 0;
	if (!ft_is_zero_vec3(&base->e2))
	{
		base->e2 = ft_normalize_vec3(&base->e2);
		base->e1 = ft_cross_vec3(op, &base->e2);
	}
	else if (op->z > 0)
	{
		base->e1 = ft_create_vec3(1, 0, 0);
		base->e2 = ft_create_vec3(0, 1, 0);
	}
	else
	{
		base->e1 = ft_create_vec3(-1, 0, 0);
		base->e2 = ft_create_vec3(0, -1, 0);
	}
}

void	fill_tangent_space_sp(const t_intersec *inter, t_normal_map *map)
{
	t_sphere_obj	*sp_obj;
	t_vec3			op;

	sp_obj = (t_sphere_obj *)inter->obj->data;
	op = ft_create_normalized_vec3(&sp_obj->sp.pos, &inter->soluce.p);
	fill_tangent_space(&op, &map->base);
}

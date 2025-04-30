/// @todo header

#include "minirt.h"

static void	fill_bitangent(const t_vec3 *n, const t_cone *co, t_vec3 *bitangent)
{
	double	dot;

	dot = ft_dot_vec3(n, &co->dir);
	if (-0.9 < dot && dot < 0.9)
		*bitangent = co->dir;
	else
		*bitangent = co->right;
}

static void	fill_tangent(const t_vec3 *p, const t_vec3 *o, t_base *base)
{
	t_vec3	op;
	t_vec3	inv_n;
	double	dot;

	op = ft_diff_vec3(p, o);
	dot = ft_dot_vec3(&op, &base->e3);
	if (dot >= 0)
		base->e1 = ft_cross_vec3(&base->e3, &base->e2);
	else
	{
		inv_n = ft_scalmult_vec3(&base->e3, -1);
		base->e1 = ft_cross_vec3(&inv_n, &base->e2);
	}
}

void	fill_tangent_space_co(const t_intersec *inter, t_normal_map *map)
{
	t_cone_obj	*co_obj;

	co_obj = (t_cone_obj *)inter->obj->data;
	fill_bitangent(&inter->soluce.n, &co_obj->co, &map->base.e2);
	fill_tangent(&inter->soluce.p, &co_obj->co.pos, &map->base);
}

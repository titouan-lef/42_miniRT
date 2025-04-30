/// @todo header

#include "minirt.h"

static void	fill_bitangent(const t_vec3 *n, const t_cylinder *cy,
	t_vec3 *bitangent)
{
	double	dot;

	dot = ft_dot_vec3(n, &cy->dir);
	if (-0.9 < dot && dot < 0.9)
		*bitangent = cy->dir;
	else
		*bitangent = cy->right;
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

void	fill_tangent_space_cy(const t_intersec *inter, t_normal_map *map)
{
	t_cylinder_obj	*cy_obj;

	cy_obj = (t_cylinder_obj *)inter->obj->data;
	fill_bitangent(&inter->soluce.n, &cy_obj->cy, &map->base.e2);
	fill_tangent(&inter->soluce.p, &cy_obj->cy.pos, &map->base);
}

/// @todo header

#include "minirt.h"

static void	fill_bitangent(const t_intersec *inter, t_vec3 *bitangent)
{
	t_cylinder_obj	*cy_obj;
	double			dot;

	cy_obj = (t_cylinder_obj *)inter->obj->data;
	dot = ft_dot_vec3(&inter->soluce.n, &cy_obj->cy.dir);
	dot = fabs(dot);
	if (dot < 0.9)
		*bitangent = cy_obj->cy.dir;
	else
		*bitangent = cy_obj->cy.right;
}

static void	fill_tangent(t_base *base)
{
	base->e1 = ft_cross_vec3(&base->e3, &base->e2);
}

void	fill_normal_map_cy(const t_intersec *inter, t_normal_map *map)
{
	fill_bitangent(inter, &map->base.e2);
	fill_tangent(&map->base);
}

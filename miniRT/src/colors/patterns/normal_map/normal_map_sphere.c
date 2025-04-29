/// @todo header

#include "minirt.h"

static void	fill_bitangent(const t_intersec *inter, t_vec3 *bitangent)
{
	t_sphere_obj	*sp_obj;

	sp_obj = (t_sphere_obj *)inter->obj->data;
	bitangent->x = inter->soluce.n.y * 2 * M_PI;//(sp_obj->sp.pos.y - inter->soluce.p.y) * 2 * M_PI; ?
	bitangent->y = inter->soluce.n.x * 2 * M_PI;//(inter->soluce.p.x - sp_obj->sp.pos.x) * 2 * M_PI; ?
	bitangent->z = 0;
}

static void	fill_tangent(t_base *base)
{
	base->e1 = ft_cross_vec3(&base->e3, &base->e2);
}

void	fill_normal_map_sp(const t_intersec *inter, t_normal_map *map)
{
	fill_bitangent(inter, &map->base.e2);
	fill_tangent(&map->base);
}

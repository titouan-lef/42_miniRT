/// @todo header

#include "minirt.h"

static void	fill_bitangent(const t_plane_obj *pl_obj, t_vec3 *bitangent)
{
	*bitangent = pl_obj->right;
}

static void	fill_tangent(const t_plane_obj *pl_obj, t_vec3 *tangent)
{
	*tangent = pl_obj->up;
}

void	fill_normal_map_pl(const t_intersec *inter, t_normal_map *map)
{
	t_plane_obj	*pl_obj;

	pl_obj = (t_plane_obj *)inter->obj->data;
	fill_bitangent(pl_obj, &map->base.e2);
	fill_tangent(pl_obj, &map->base.e1);
}

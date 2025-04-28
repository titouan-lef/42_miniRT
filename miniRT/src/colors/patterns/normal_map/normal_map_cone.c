/// @todo header

#include "minirt.h"

static void	fill_bitangent(const t_intersec *inter, t_vec3 *bitangent)
{
	t_cone_obj	*co_obj;
	double			dot;

	co_obj = (t_cone_obj *)inter->obj->data;
	dot = ft_dot_vec3(&inter->soluce.n, &co_obj->co.dir);
	dot = fabs(dot);
	if (dot < 0.9)
		*bitangent = co_obj->co.dir;
	else
		*bitangent = co_obj->co.right;
}

static void	fill_tangent(t_base *base)
{
	base->e1 = ft_cross_vec3(&base->e3, &base->e2);
}

void	fill_normal_map_co(const mlx_context *mlx, const t_img *img, const t_intersec *inter, t_normal_map *map)
{
	fill_bitangent(inter, &map->base.e2);
	fill_tangent(&map->base);
	map->n = get_normal_from_img(mlx, img, inter, uv_co);
}

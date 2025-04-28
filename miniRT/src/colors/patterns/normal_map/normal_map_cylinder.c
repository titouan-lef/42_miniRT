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

void	fill_normal_map_cy(const mlx_context *mlx, const t_img *img, t_intersec *inter, t_normal_map *map)
{
	fill_bitangent(inter, &map->base.e2);
	fill_tangent(&map->base);
	//map->n = get_normal_from_img(mlx, img, inter, uv_cy);

	t_vec2 uv = uv_cy(inter->soluce.p, inter);
	if (uv.x >= 1)
		uv.x = 0;
	if (uv.y >= 1)
		uv.y = 0;
	mlx_color	c = mlx_get_image_pixel(*mlx, img->img, uv.x * img->width, uv.y * img->heigth);
	map->n.x = c.r / 255.0 * 2 - 1;
	map->n.y = c.g / 255.0 * 2 - 1;
	map->n.z = c.b / 255.0 * 2 - 1;
}

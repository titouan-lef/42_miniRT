/// @todo header

#include "minirt.h"

/**
 * @brief Takes the vector normal to the contact store in color in the file.
 * @return Vector normal to the contact.
 */
static t_vec3	get_normal_from_img(const mlx_context *mlx, const t_img *img,
	const t_vec2 *uv_bm)
{
	mlx_color	c;
	t_vec3		normal;

	c = mlx_get_image_pixel(*mlx, img->img, uv_bm->x * img->width,
			uv_bm->y * img->heigth);
	normal.x = c.r / 255.0 * 2 - 1;
	normal.y = c.g / 255.0 * 2 - 1;
	normal.z = c.b / 255.0 * 2 - 1;
	return (normal);
}

/**
 * @brief Modifies the normal vector found intersecting with the normal vector
 * to the contact contained in the bump map.
 */
void	bump_map(t_graph_sys *g_sys, t_intersec *inter)
{
	const t_img		*bump;
	t_normal_map	map;

	if (inter->obj->pattern.bump.name == NULL)
		return ;
	map.base.e3 = inter->soluce.n;
	bump = &inter->obj->pattern.bump;
	if (inter->obj->type == SPHERE)
		fill_tangent_space_sp(inter, &map);
	else if (inter->obj->type == PLANE)
		fill_tangent_space_pl(inter, &map);
	else if (inter->obj->type == CYLINDER)
		fill_tangent_space_cy(inter, &map);
	else
		fill_tangent_space_co(inter, &map);
	map.n = get_normal_from_img(&g_sys->mlx, bump, &inter->uv_bm);
	if (!ft_is_zero_vec3(&map.n))
		inter->soluce.n = change_base(&map.base, &map.n);
}

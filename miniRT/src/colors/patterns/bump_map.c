/// @todo header

#include "minirt.h"

t_vec3	change_base(const t_base *base, const t_vec3 *v)
{
	t_vec3	new;

	new.x = base->e1.x * v->x + base->e2.x * v->y + base->e3.x * v->z;
	new.y = base->e1.y * v->x + base->e2.y * v->y + base->e3.y * v->z;
	new.z = base->e1.z * v->x + base->e2.z * v->y + base->e3.z * v->z;
	return (new);
}

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
	inter->soluce.n = change_base(&map.base, &map.n);
}

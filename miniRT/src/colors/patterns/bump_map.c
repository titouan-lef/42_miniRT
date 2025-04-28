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

t_vec3	get_normal_from_img(const mlx_context *mlx, const t_img *img, const t_intersec *inter, t_vec2 (*f)(t_vec3, void *))
{
	t_vec2		uv;
	mlx_color	c;
	t_vec3		normal;

	uv = f(inter->soluce.p, inter->obj->data);
	if (uv.x >= 1)
		uv.x = 0;
	if (uv.y >= 1)
		uv.y = 0;
	c = mlx_get_image_pixel(*mlx, img->img, uv.x * img->width, uv.y * img->heigth);
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
		fill_normal_map_sp(&g_sys->mlx, bump, inter, &map);
	else if (inter->obj->type == PLANE)
		fill_normal_map_pl(&g_sys->mlx, bump, inter, &map);
	else if (inter->obj->type == CYLINDER)
		fill_normal_map_cy(&g_sys->mlx, bump, inter, &map);
	else
		fill_normal_map_co(&g_sys->mlx, bump, inter, &map);
	inter->soluce.n = change_base(&map.base, &map.n);
}

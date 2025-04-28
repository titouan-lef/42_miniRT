/// @todo header

#include "minirt.h"

static t_vec3	get_color_from_img(const mlx_context *mlx, const t_img *img, const t_intersec *inter, t_vec2 (*f)(t_vec3, void *))
{
	t_vec2		uv;
	mlx_color	c;
	t_vec3		color;
	t_color		extract;

	uv = f(inter->soluce.p, inter->obj->data);
	if (uv.x >= 1)
		uv.x = 0;
	if (uv.y >= 1)
		uv.y = 0;
	c = mlx_get_image_pixel(*mlx, img->img, uv.x * img->width, uv.y * img->heigth);
	extract = ft_color_create(c.r, c.g, c.b, c.a);
	color = ft_color_to_vec3(&extract);
	return (color);
}

t_vec3	color_from_img(const t_graph_sys *g_sys, const t_intersec *inter)
{
	const t_img	*texture;
	t_vec3	color;

	texture = &inter->obj->pattern.texture;
	if (inter->obj->type == SPHERE)
		color = get_color_from_img(&g_sys->mlx, texture, inter, uv_sp);
	else if (inter->obj->type == PLANE)
		color = get_color_from_img(&g_sys->mlx, texture, inter, uv_pl);
	else if (inter->obj->type == CYLINDER)
		color = get_color_from_img(&g_sys->mlx, texture, inter, uv_cy);
	else
		color = get_color_from_img(&g_sys->mlx, texture, inter, uv_co);
	return (color);
}
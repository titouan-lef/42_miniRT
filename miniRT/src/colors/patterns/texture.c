/// @todo header

#include "minirt.h"

static t_vec3	get_color_from_img(const mlx_context *mlx, const t_img *img,
	const t_vec2 *uv_bm)
{
	t_vec2		uv;
	mlx_color	c;
	t_vec3		color;
	t_color		extract;

	uv.x = uv_bm->x;
	uv.y = uv_bm->y;
	if (uv.x >= 1)
		uv.x = 0;
	if (uv.y >= 1)
		uv.y = 0;
	c = mlx_get_image_pixel(*mlx, img->img,
			uv.x * img->width, uv.y * img->heigth);
	extract = ft_color_create(c.r, c.g, c.b, c.a);
	color = ft_color_to_vec3(&extract);
	return (color);
}

t_vec3	color_from_img(const t_graph_sys *g_sys, const t_intersec *inter)
{
	const t_img	*texture;
	t_vec3		color;

	texture = &inter->obj->pattern.texture;
	color = get_color_from_img(&g_sys->mlx, texture, &inter->uv_bm);
	return (color);
}

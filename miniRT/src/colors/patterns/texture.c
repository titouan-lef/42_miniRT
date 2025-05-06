/// @todo header

#include "minirt.h"

/**
 * @brief Takes the color of a pixel in the image passed as a parameter.
 * Completes vec3 color with data.
 */
static void	get_color_from_img(const mlx_context *mlx, const t_img *img,
	const t_vec2 *uv_bm, t_vec3 *color)
{
	mlx_color	c;

	c = mlx_get_image_pixel(*mlx, img->img, uv_bm->x * img->width,
			uv_bm->y * img->heigth);
	color->x = c.r / 255.0;
	color->y = c.g / 255.0;
	color->z = c.b / 255.0;
	return (color);
}

/**
 * @brief Takes the color form an image and a point.
 * @return The color as a vector3.
 */
t_vec3	color_from_img(const t_graph_sys *g_sys, const t_intersec *inter)
{
	const t_img	*texture;
	t_vec3		color;

	texture = &inter->obj->pattern.texture;
	get_color_from_img(&g_sys->mlx, texture, &inter->uv_bm, &color);
	return (color);
}

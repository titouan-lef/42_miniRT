/// @todo header

#include "minirt.h"

t_vec3 color_to_normal(mlx_color *c)
{
	t_vec3		new_normal;

	new_normal.x = c->r / 255;
	new_normal.y = c->g / 255;
	new_normal.z = c->b / 255;
	return (new_normal);
}

static t_vec3	uv_bump(mlx_context *mlx, t_vec3 p, mlx_image *img, t_vec2 (*f)(t_vec3, void *), void *arg)
{
	t_vec3		new_normal;
	t_vec2		uv;
	mlx_color	c;

	uv = f(p, arg);
	c = mlx_get_image_pixel(*mlx, *img, uv.x * 2048, uv.y * 2048);
	new_normal = color_to_normal(&c);
	return (new_normal);
}

t_vec3	bump_map(t_graph_sys *g_sys, const t_intersec *inter, mlx_image *img)
{
	t_vec3	new_normal;

	if (inter->obj->type == SPHERE)
		new_normal = uv_bump(&g_sys->mlx, inter->soluce.p, img, &uv_sp, (void *)inter->obj->data);
	else if (inter->obj->type == PLANE)
		new_normal = uv_bump(&g_sys->mlx, inter->soluce.p, img, &uv_pl, (void *)inter->obj->data);
	else if (inter->obj->type == CYLINDER)
		new_normal = uv_bump(&g_sys->mlx, inter->soluce.p, img, &uv_cy, (void *)inter);
	else
		new_normal = uv_bump(&g_sys->mlx, inter->soluce.p,  img, &uv_co, (void *)inter);
	new_normal = ft_sum_vec3(&inter->soluce.n, &new_normal);
	new_normal = ft_normalize_vec3(&new_normal);
	return (new_normal);
}
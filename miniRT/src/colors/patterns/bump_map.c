/// @todo header

#include "minirt.h"

static t_vec3	change_vector_space(t_vec3 *n, t_vec3 *nl)
{
	t_vec3	t;
	t_vec3	b;
	t_vec3	new;

	t.x = n->y;
	t.y = -n->x;
	t.z = 0;
	if (!ft_is_zero_vec3(&t))
		t = ft_normalize_vec3(&t);
	b = ft_cross_vec3(n, &t);
	new.x = t.x * nl->x + b.x * nl->y + n->x * nl->z;
	new.y = t.y * nl->x + b.y * nl->y + n->y * nl->z;
	new.z = t.z * nl->x + b.z * nl->y + n->z * nl->z;
	return (new);
}

static t_vec3	color_to_normal(mlx_color *c_x1, mlx_color *c_y1, mlx_color *c_xy)
{
	t_vec3	new_normal;
	double	x1;
	double	y1;
	double	xy;

	x1 = ((double)c_x1->r / 255);
	y1 = ((double)c_y1->r / 255);
	xy = ((double)c_xy->r / 255);
	new_normal.x = xy - x1;
	new_normal.y = xy - y1;
	new_normal.z = 1;
	return (new_normal);
}

static t_vec3	get_local_normal(mlx_context *mlx, mlx_image *img, t_vec2 *uv)
{
	mlx_color	c_x1;
	mlx_color	c_y1;
	mlx_color	c_xy;
	t_vec3		local_normal;

	c_x1 = mlx_get_image_pixel(*mlx, *img, uv->x * 350 + 1, uv->y * 350);
	c_y1 = mlx_get_image_pixel(*mlx, *img, uv->x * 350, uv->y * 350 + 1);
	c_xy = mlx_get_image_pixel(*mlx, *img, uv->x * 350, uv->y * 350);
	local_normal = color_to_normal(&c_x1, &c_y1, &c_xy);
	return (local_normal);
}

static t_vec3	uv_bump(mlx_context *mlx, t_intersec *inter,
	mlx_image *img, t_vec2 (*f)(t_vec3, void *), void *arg)
{
	t_vec3	local_normal;
	t_vec3	final_normal;
	t_vec2	uv;

	uv = f(inter->soluce.p, arg);
	local_normal = get_local_normal(mlx, img, &uv);
	final_normal = change_vector_space(&inter->soluce.n, &local_normal);
	return (final_normal);
}

t_vec3	bump_map(t_graph_sys *g_sys, t_intersec *inter, mlx_image *img)
{
	t_vec3	new_normal;

	if (inter->obj->type == SPHERE)
		new_normal = uv_bump(&g_sys->mlx, inter, img,
				&uv_sp, (void *)inter->obj->data);
	else if (inter->obj->type == PLANE)
		new_normal = uv_bump(&g_sys->mlx, inter, img,
				&uv_pl, (void *)inter->obj->data);
	else if (inter->obj->type == CYLINDER)
		new_normal = uv_bump(&g_sys->mlx, inter, img,
				&uv_cy, (void *)inter);
	else
		new_normal = uv_bump(&g_sys->mlx, inter, img,
				&uv_co, (void *)inter);
	return (new_normal);
}

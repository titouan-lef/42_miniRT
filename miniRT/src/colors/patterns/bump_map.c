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

static void	color_to_normal(mlx_color *c, t_vec3 *normal)
{
	normal->x = c->r / 255.0 * 2 - 1;
	normal->y = c->g / 255.0 * 2 - 1;
	normal->z = c->b / 255.0 * 2 - 1;
}

static t_vec3	get_local_normal(mlx_context *mlx, const t_img *img, t_vec2 *uv)
{
	mlx_color	c;
	t_vec3		local_normal;

	c = mlx_get_image_pixel(*mlx, img->img,
			uv->x * img->heigth, uv->y * img->width);
	color_to_normal(&c, &local_normal);
	return (local_normal);
}

static t_vec3	uv_bump(mlx_context *mlx, t_intersec *inter,
	const t_img *img, t_vec2 (*f)(t_vec3, void *))
{
	t_vec3	local_normal;
	t_vec3	final_normal;
	t_vec2	uv;

	uv = f(inter->soluce.p, (void *)inter->obj->data);
	if (uv.x >= 1)
		uv.x = 0;
	if (uv.y >= 1)
		uv.y = 0;
	local_normal = get_local_normal(mlx, img, &uv);
	final_normal = change_vector_space(&inter->soluce.n, &local_normal);
	return (final_normal);
}

void	bump_map(t_graph_sys *g_sys, t_intersec *inter)
{
	t_vec3		new_normal;
	const t_img	*bump;

	if (inter->obj == NULL)
		return ;
	if (inter->obj->pattern.bump.name == NULL)
		return ;
	bump = &inter->obj->pattern.bump;
	if (inter->obj->type == SPHERE)
		//new_normal = uv_bump(&g_sys->mlx, inter, bump, &uv_sp);
		new_normal = update_normal_sp(&g_sys->mlx, inter, bump);
	else if (inter->obj->type == PLANE)
		//new_normal = uv_bump(&g_sys->mlx, inter, bump, &uv_pl);
		new_normal = update_normal_pl(&g_sys->mlx, inter, bump);
	else if (inter->obj->type == CYLINDER)
		//new_normal = uv_bump(&g_sys->mlx, inter, bump, &uv_cy);
		new_normal = update_normal_cy(&g_sys->mlx, inter, bump);
	else
		new_normal = uv_bump(&g_sys->mlx, inter, bump, &uv_co);
	inter->soluce.n = new_normal;
}

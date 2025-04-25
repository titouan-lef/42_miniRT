/// @todo header

#include "minirt.h"

static t_vec3	get_normal(mlx_context *mlx, const t_img *img, t_intersec *inter, t_vec2 (*f)(t_vec3, void *))
{
	t_vec2		uv;
	mlx_color	c;
	t_vec3		normal;

	uv = f(inter->soluce.p, (void *)inter->obj->data);
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

static t_vec3	get_bitangent_sp(const t_intersec *inter)
{
	t_vec3			bitangent;
	t_sphere_obj	*sp_obj;

	sp_obj = (t_sphere_obj *)inter->obj->data;
	bitangent.x = inter->soluce.n.y * 2 * M_PI;//(sp_obj->sp.pos.y - inter->soluce.p.y) * 2 * M_PI; ?
	bitangent.y = inter->soluce.n.x * 2 * M_PI;//(inter->soluce.p.x - sp_obj->sp.pos.x) * 2 * M_PI; ?
	bitangent.z = 0;
	return (bitangent);
}

t_normal_map	normal_map_sp(mlx_context *mlx, t_intersec *inter, const t_img *img)
{
	t_normal_map	map;

	(void) mlx;
	(void) img;
	map.n = inter->soluce.n;//get_normal(mlx, img, inter, uv_sp);
	map.b = get_bitangent_sp(inter);
	if (ft_is_zero_vec3(&map.b))
		return (map);
	else
		map.b = ft_normalize_vec3(&map.b);
	map.t = ft_cross_vec3(&map.n, &map.b);
	return (map);
}

static t_vec3	get_bitangent_cy(const t_intersec *inter)
{
	t_cylinder_obj	*cy_obj;
	double			dot;

	cy_obj = (t_cylinder_obj *)inter->obj->data;
	dot = ft_dot_vec3(&inter->soluce.n, &cy_obj->cy.dir);
	dot = fabs(dot);
	if (dot < 0.9)
		return (cy_obj->cy.dir);
	else
		return (cy_obj->cy.right);
}

t_normal_map	normal_map_cy(mlx_context *mlx, t_intersec *inter, const t_img *img)
{
	t_normal_map	map;

	(void) mlx;
	(void) img;
	map.n = inter->soluce.n;//map.n = get_normal(mlx, img, inter, uv_cy);
	map.b = get_bitangent_cy(inter);
	if (ft_is_zero_vec3(&map.b))
		return (map);
	else
		map.b = ft_normalize_vec3(&map.b);
	map.t = ft_cross_vec3(&map.n, &map.b);
	return (map);
}

static t_vec3	get_bitangent_pl(const t_intersec *inter)
{
	t_plane_obj	*pl_obj;

	pl_obj = (t_plane_obj *)inter->obj->data;
	return (pl_obj->right);
}

t_normal_map	normal_map_pl(mlx_context *mlx, t_intersec *inter, const t_img *img)
{
	t_normal_map	map;

	(void) mlx;
	(void) img;
	map.n = inter->soluce.n;
	//map.n = get_normal(mlx, img, inter, uv_pl);
	map.b = get_bitangent_pl(inter);
	if (ft_is_zero_vec3(&map.b))
		return (map);
	else
		map.b = ft_normalize_vec3(&map.b);
	map.t = ft_cross_vec3(&map.n, &map.b);
	return (map);
}

t_vec3	new_vec_normal(const t_normal_map *map, const t_vec3 *n)
{
	t_vec3	new;

	if (ft_is_zero_vec3(&map->b))
		return (map->n);
	new.x = map->t.x * n->x + map->b.x * n->y + map->n.x * n->z;
	new.y = map->t.y * n->x + map->b.y * n->y + map->n.y * n->z;
	new.z = map->t.z * n->x + map->b.z * n->y + map->n.z * n->z;
	return (new);
}

t_vec3	update_normal_sp(mlx_context *mlx, t_intersec *inter, const t_img *img)
{
	t_normal_map	map;
	t_vec3			new;

	map = normal_map_sp(mlx, inter, img);
	t_vec3 n = get_normal(mlx, img, inter, uv_sp);
	new = new_vec_normal(&map, &n);
	return (new);
}

t_vec3	update_normal_pl(mlx_context *mlx, t_intersec *inter, const t_img *img)
{
	t_normal_map	map;
	t_vec3			new;

	map = normal_map_pl(mlx, inter, img);
	t_vec3 n = get_normal(mlx, img, inter, uv_pl);
	new = new_vec_normal(&map, &n);
	return (new);
}

t_vec3	update_normal_cy(mlx_context *mlx, t_intersec *inter, const t_img *img)
{
	t_normal_map	map;
	t_vec3			new;

	map = normal_map_cy(mlx, inter, img);
	t_vec3 n = get_normal(mlx, img, inter, uv_cy);
	new = new_vec_normal(&map, &n);
	return (new);
}

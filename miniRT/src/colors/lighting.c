/// @todo header

#include "minirt.h"

/**
 * @brief Calculates uv as a function of shape.
 */
static void	fill_uv_obj(t_intersec *inter)
{
	if (inter->obj->type == SPHERE)
		fill_uv_sp(inter);
	else if (inter->obj->type == PLANE)
		fill_uv_pl(inter);
	else if (inter->obj->type == CYLINDER)
		fill_uv_cy(inter);
	else
		fill_uv_co(inter);
	if (inter->uv_bm.x >= 1)
		inter->uv_bm.x = 0;
	if (inter->uv_bm.y >= 1)
		inter->uv_bm.y = 0;
}

/**
 * @brief Allows you to have the color of object depending on the
 * option (color, texture or checkerboard).
 * @return Color of object.
 */
static t_vec3	get_obj_color(t_graph_sys *g_sys, const t_intersec *inter)
{
	const t_pattern	*pattern;
	t_vec3			color;

	pattern = &inter->obj->pattern;
	if (pattern->texture.name == NULL)
		color = pattern->colors;
	else
		color = color_from_img(g_sys, inter);
	if (pattern->checkerboard != 0)
		color = uv_manager(inter, color);
	return (color);
}

/**
 * @brief Assemble the 3 colors present in the t_phong to obtain the final
 * pixel color.
 */
static t_color	mix_color_and_lights(const t_phong *phong, t_vec3 *c_obj)
{
	t_vec3	total_light;
	t_color	color;

	total_light = ft_sum_vec3(&phong->ambient, &phong->diffuse);
	c_obj->x = c_obj->x * total_light.x;
	c_obj->y = c_obj->y * total_light.y;
	c_obj->z = c_obj->z * total_light.z;
	*c_obj = ft_sum_vec3(c_obj, &phong->specular);
	if (c_obj->x > 1)
		c_obj->x = 1;
	if (c_obj->y > 1)
		c_obj->y = 1;
	if (c_obj->z > 1)
		c_obj->z = 1;
	color = ft_vec3_to_color(c_obj, 255);
	return (color);
}

/**
 * @brief Applies diffused and speculative light to the point.
 */
static void	apply_light_point(t_scene *scene, t_intersec *inter, t_phong *phong)
{
	double	cos_angle[2];
	t_light	**tab_l;
	t_vec3	old_n;

	tab_l = scene->tab_l;
	phong->diffuse = ft_create_vec3(0, 0, 0);
	phong->specular = ft_create_vec3(0, 0, 0);
	old_n = inter->soluce.n;
	if (PATTERN_ACTIVE == 1)
		bump_map(&scene->g_sys, inter);
	while (*tab_l != NULL)
	{
		cos_angle_light(*tab_l, &inter->soluce, &old_n, cos_angle);
		if (cos_angle[0] > EPSILON && cos_angle[1] > EPSILON
			&& !shadow(scene->tab_obj, *tab_l, &inter->soluce.p))
		{
			apply_diffuse(*tab_l, &phong->diffuse, cos_angle[1]);
			if (SPECULAR_ACTIVE == 1)
				apply_specular(*tab_l, &phong->specular, inter, cos_angle[1]);
		}
		++tab_l;
	}
}

/**
 * @brief Manages all the object's colors and lighting.
 * @details If there is no intersecting object,
 * the color returned will be black.
 * else calculate object UV to apply texture and bump map
 * followed by the application of ambient, difused and specular lighting
 * and shwadow.
 * @return The final pixel color.
 */
t_color	lighting(t_scene *scene, t_intersec *inter)
{
	t_color	c;
	t_vec3	c_obj;
	t_phong	phong;

	if (inter->obj == NULL)
	{
		c = ft_color_create(0, 0, 0, 255);
		return (c);
	}
	fill_uv_obj(inter);
	c_obj = get_obj_color(&scene->g_sys, inter);
	apply_ambient(&scene->amb, &phong.ambient);
	apply_light_point(scene, inter, &phong);
	c = mix_color_and_lights(&phong, &c_obj);
	return (c);
}

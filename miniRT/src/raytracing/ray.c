/// @todo header

#include "minirt.h"

/**
 * @brief Get the ray direction as a function of camera direction.
 * @details Angle is define by dot product because the 2 vector are normalized.
 * Camera is considerate at the position (0,0,0).
 * @param pixel Pixel position.
 * @param cam_dir Camera direction.
 * @warning Pixel and camera direction must be nonzero vector and camera
 * direction must be normalized.
 */
static t_vector3	get_ray_dir(t_vector3 pixel, t_vector3 cam_dir)
{
	t_vector3	ray_dir;
	t_vector3	axis;
	t_vector3	default_cam_dir;
	double		angle;

	default_cam_dir = ft_create_vector3(0,0,1);
	ray_dir = ft_normalize_vector3(pixel);
	axis = ft_crossproduct_vector3(cam_dir, default_cam_dir);
	if (ft_is_zero_vector3(axis))
		return (ray_dir);
	angle = ft_dotproduct_vector3(default_cam_dir, cam_dir);
	angle = acos(angle);
	ray_dir = ft_rotation_quaternion(ray_dir, angle, axis);
	return (ray_dir);
}

t_color	get_color(t_obj *obj)
{
	int		type;
	t_color	color;

	type = obj->type;
	if (type == SPHERE)
		color = ((t_sphere_obj *)(obj->data))->color;
	else if (type == PLAN)
		color = ((t_plane_obj *)(obj->data))->color;
	else if (type == CYLINDER)
		color = ((t_cylinder_obj *)(obj->data))->color;
	else
		color = ((t_cone_obj *)(obj->data))->color;
	return (color);
}

/**
 * @brief Get the object color of the first object intersect by the ray.
 */
t_color	raytracers(t_list *lst_obj, t_pixel *pixel, t_vector3 cam_pos)
{
	t_obj	*obj;
	t_color	color;
	double	length;
	double	length_min;

	color = ft_color_create(0, 0, 0, 255);
	length_min = INFINITY;
	while (lst_obj)
	{
		obj = (t_obj *)lst_obj->content;
		if (obj->type == SPHERE)
			length = intersect_ray_sphere((t_sphere_obj *)(obj->data), pixel->ray_dir);
		else if (obj->type == PLAN)
			length = intersect_ray_plan((t_plane_obj *)(obj->data), pixel->ray_dir,
					cam_pos);
		else if (obj->type == CYLINDER)
			length = intersect_ray_cylinder((t_cylinder_obj *)(obj->data),
					pixel->ray_dir, cam_pos);
		if (length < length_min)
		{
			length_min = length;
			pixel->obj = obj;
			color = get_color(obj);
		}
		lst_obj = lst_obj->next;
	}
	return (color);
}

/**
 * @details To optimize calculations, camera has a position (0,0,0) and a
 * direction (0,0,1), pixel has a position(
 * 	[-width screen / 2, width screen / 2],
 * 	[-height screen / 2, height screen / 2],
 * 	screen distance
 * ). The real position and direction are manage with get_ray_dir() and
 * raytracers().
 */
int	ray_lauch_test(t_scene *scene)
{
	t_pixel		pixel;

	pixel.pos.z = length_screen(scene->cam.fov);
	pixel.pos.y = -WIN_HH;
	while (pixel.pos.y < WIN_HH)
	{
		pixel.pos.x = -WIN_HW;
		while (pixel.pos.x < WIN_HW)
		{
			pixel.obj = NULL;
			pixel.ray_dir = get_ray_dir(pixel.pos, scene->cam.dir);
			pixel.color = raytracers(scene->lst_obj, &pixel, scene->cam.pos);
			//pixel.color = ambient(pixel.color, &scene->ambient);
			//lighting(&pixel, scene->lst_light, &scene->ambient);
			set_image_pixel(&scene->g_sys, WIN_HW + pixel.pos.x,
				WIN_HH + pixel.pos.y, pixel.color);
			pixel.pos.x += scene->g_sys.def_w;
		}
		pixel.pos.y += scene->g_sys.def_h;
	}
	return (0);
}

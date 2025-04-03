/// @todo header

#include "minirt.h"

t_color	get_color(const t_obj *obj)
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
void	raytracers(const t_list *lst_obj, t_intersec *intersect)
{
	t_obj	*obj;
	double	dist;
	double	dist_min;

	dist_min = INFINITY;
	while (lst_obj)
	{
		obj = (t_obj *)lst_obj->content;
		if (obj->type == SPHERE)
			dist = intersect_ray_sphere((t_sphere_obj *)(obj->data), &intersect->ray.dir);
		else if (obj->type == PLAN)
			dist = intersect_ray_plan((t_plane_obj *)(obj->data), &intersect->ray);
		else if (obj->type == CYLINDER)
			dist = intersect_ray_cylinder((t_cylinder_obj *)(obj->data), &intersect->ray);
		if (dist < dist_min)
		{
			dist_min = dist;
			intersect->obj = obj;
			intersect->color = get_color(obj);
		}
		lst_obj = lst_obj->next;
	}
	if (intersect->obj != NULL)
	{
		intersect->p = ft_scalarmult_vec3(&intersect->ray.dir, dist_min);
		intersect->p = ft_sum_vec3(&intersect->p, &intersect->ray.s);
	}
}

/**
 * @brief Get the ray direction as a function of camera direction.
 * @details Angle is define by dot product because the 2 vector are normalized.
 * Camera is considerate at the position (0,0,0).
 * @param default_dir Ray direction if camera has (0,0,1) direction.
 * @param cam_dir Camera direction.
 * @warning Pixel and camera direction must be nonzero vector and camera
 * direction must be normalized.
 */
static t_ray	get_ray(const t_vec3 *default_dir, const t_cam *cam)
{
	t_ray	ray;
	t_vec3	axis;
	t_vec3	default_cam_dir;
	double	angle;

	ray.s = cam->pos;
	default_cam_dir = ft_create_vec3(0, 0, 1);
	ray.dir = ft_normalize_vec3(default_dir);
	axis = ft_crossproduct_vec3(&cam->dir, &default_cam_dir);
	if (ft_is_zero_vec3(&axis))
		return (ray);
	angle = ft_dotproduct_vec3(&default_cam_dir, &cam->dir);
	angle = acos(angle);
	ray.dir = ft_rotation_quat(&ray.dir, angle, &axis);
	return (ray);
}

static t_intersec	get_near_intersec(const t_vec3 *default_dir, const t_cam *cam, const t_list *lst_obj)
{
	t_intersec	intersec;

	intersec.obj = NULL;
	intersec.ray = get_ray(default_dir, cam);
	intersec.color = ft_color_create(0, 0, 0, 255);
	raytracers(lst_obj, &intersec);
	return (intersec);
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
	t_intersec	intersec;
	t_vec3		default_dir;
	int			x;
	int			y;

	default_dir.z = length_screen(scene->cam.fov);
	y = 0;
	while (y < WIN_H)
	{
		default_dir.y = y - WIN_HH;
		x = 0;
		while (x < WIN_W)
		{
			default_dir.x = x - WIN_HW;
			intersec = get_near_intersec(&default_dir, &scene->cam, scene->lst_obj);
			//pixel.color = ambient(pixel.color, &scene->amb, 1.0);
			lighting(&intersec, scene->lst_light, &scene->amb);
			set_image_pixel(&scene->g_sys, x, y, intersec.color);
			x += scene->g_sys.def_w;
		}
		y += scene->g_sys.def_h;
	}
	return (0);
}

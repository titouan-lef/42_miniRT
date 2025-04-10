/// @todo header

#include "minirt.h"

static double	intersect_ray_obj(const t_obj *obj, t_intersec *inter)
{
	double	dist;

	if (obj->type == SPHERE)
		dist = intersect_ray_sp(obj, &inter->ray.dir);
	else if (obj->type == PLANE)
		dist = intersect_ray_pl(obj, &inter->ray.dir);
	else if (obj->type == CYLINDER)
		dist = intersect_ray_cy(obj, &inter->ray);
	else if (obj->type == CONE)
		dist = intersect_ray_co(obj, &inter->ray);
	else
		dist = INFINITY;
	return (dist);
}

/**
 * @brief Get the object color of the first object intersect by the ray.
 */
static void	raytracers(const t_list *lst_obj, t_intersec *inter)
{
	t_obj	*obj;
	double	dist;
	double	dist_min;

	dist_min = INFINITY;
	while (lst_obj)
	{
		obj = (t_obj *)lst_obj->content;
		dist = intersect_ray_obj(obj, inter);
		if (dist < dist_min)
		{
			dist_min = dist;
			inter->obj = obj;
		}
		lst_obj = lst_obj->next;
	}
	if (inter->obj != NULL)
		inter->p = ft_translation(&inter->ray.s, &inter->ray.dir, dist_min);
}

/**
 * @brief Get the ray direction as a function of camera direction.
 * @details Angle is define by dot product because the 2 vector are normalized.
 * Camera is considerate at the position (0,0,0).
 * @param basic_dir Ray direction if camera has (0,0,1) direction.
 * @param cam_dir Camera direction.
 * @warning Pixel and camera direction must be nonzero vector and camera
 * direction must be normalized.
 */
static t_ray	get_ray(const t_vec3 *basic_dir, const t_cam *cam)
{
	t_ray	ray;
	t_vec3	axis;
	t_vec3	basic_cam_dir;
	double	angle;

	ray.s = cam->pos;
	basic_cam_dir = ft_create_vec3(0, 0, 1);
	ray.dir = ft_normalize_vec3(basic_dir);
	axis = ft_cross_vec3(&cam->dir, &basic_cam_dir);
	if (ft_is_zero_vec3(&axis))
		return (ray);
	angle = ft_dot_vec3(&basic_cam_dir, &cam->dir);
	angle = acos(angle);
	ray.dir = ft_rotation_quat(&ray.dir, angle, &axis);
	return (ray);
}

static t_intersec	get_near_intersec(const t_vec3 *basic_dir,
	const t_cam *cam, const t_list *lst_obj)
{
	t_intersec	inter;

	inter.obj = NULL;
	inter.ray = get_ray(basic_dir, cam);
	raytracers(lst_obj, &inter);
	return (inter);
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
	t_intersec	inter;
	t_vec3		basic_dir;
	t_color		c;
	int			x;
	int			y;

	basic_dir.z = length_screen(scene->cam.fov);
	y = 0;
	while (y < WIN_H)
	{
		basic_dir.y = y - WIN_HH;
		x = 0;
		while (x < WIN_W)
		{
			basic_dir.x = x - WIN_HW;
			inter = get_near_intersec(&basic_dir, &scene->cam, scene->lst_obj);
			c = lighting(&inter, scene->lst_obj, scene->lst_light, &scene->amb);
			set_image_pixel(&scene->g_sys, x, y, c);
			x += scene->g_sys.def_w;
		}
		y += scene->g_sys.def_h;
	}
	return (0);
}

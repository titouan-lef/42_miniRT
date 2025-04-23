/// @todo header

#include "minirt.h"

/**
 * @brief Get the object color of the first object intersect by the ray.
 */
static void	raytracers(t_obj **tab_obj, t_intersec *inter)
{
	size_t	i;

	i = 0;
	while (tab_obj[i] != NULL)
	{
		if (tab_obj[i]->type == SPHERE)
			intersect_ray_sp(tab_obj[i], inter);
		else if (tab_obj[i]->type == PLANE)
			intersect_ray_pl(tab_obj[i], inter);
		else if (tab_obj[i]->type == CYLINDER)
			intersect_ray_cy(tab_obj[i], inter);
		else if (tab_obj[i]->type == CONE)
			intersect_ray_co(tab_obj[i], inter);
		++i;
	}
	if (inter->obj != NULL)
	{
		if (inter->obj->type == SPHERE)
			update_soluce_sp(inter->obj, &inter->ray, &inter->soluce);
		else if (inter->obj->type == PLANE)
			update_soluce_pl(inter->obj, &inter->ray, &inter->soluce);
	}
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
static t_ray	get_ray(const t_vec3 *local_dir, const t_cam *cam)
{
	t_ray	ray;

	ray.s = cam->pos;
	ray.dir.x = cam->right.x * local_dir->x + cam->up.x * local_dir->y
		+ cam->dir.x * local_dir->z;
	ray.dir.y = cam->right.y * local_dir->x + cam->up.y * local_dir->y
		+ cam->dir.y * local_dir->z;
	ray.dir.z = cam->right.z * local_dir->x + cam->up.z * local_dir->y
		+ cam->dir.z * local_dir->z;
	ray.dir = ft_normalize_vec3(&ray.dir);
	return (ray);
}

static t_intersec	get_near_intersec(const t_vec3 *local_dir,
	const t_cam *cam, t_obj **tab_obj)
{
	t_intersec	inter;

	inter.obj = NULL;
	inter.ray = get_ray(local_dir, cam);
	inter.soluce.t = INFINITY;
	raytracers(tab_obj, &inter);
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
	t_vec3		local_dir;
	t_color		c;
	int			x;
	int			y;

	local_dir.z = length_screen(scene->cam.fov);
	y = 0;
	inter.b_map = &scene->g_sys.pat.img;
	while (y < WIN_H)
	{
		local_dir.y = y - WIN_HH;
		x = 0;
		while (x < WIN_W)
		{
			local_dir.x = x - WIN_HW;
			inter = get_near_intersec(&local_dir, &scene->cam, scene->tab_obj);
			//bump_map(&scene->g_sys, &inter, &scene->g_sys.pat.img);
			c = lighting(&inter, scene->tab_obj, scene->tab_l, &scene->amb);
			set_image_pixel(&scene->g_sys, x, y, c);
			x += scene->g_sys.def_w;
		}
		y += scene->g_sys.def_h;
	}
	return (0);
}

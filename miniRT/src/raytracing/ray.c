/// @todo header

#include "minirt.h"

/**
 * @brief Update the intersect structure with the closest intersection.
 * If there is no intersection, inter->obj will be NULL.
 * @param tab_obj The array of objects.
 * @param inter The intersection structure.
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
 * @brief Create the ray.
 * @details The ray direction is the local direction after base change defined
 * by camera coordinate system. local_dir->z > 0, so normalize function can't
 * fail.
 * @param local_dir The ray direction if camera has (0,0,1) direction.
 * @param cam The camera.
 */
static t_ray	create_ray(const t_vec3 *local_dir, const t_cam *cam)
{
	t_ray	ray;
	t_base	base;

	ray.s = cam->pos;
	base.e1 = cam->right;
	base.e2 = cam->up;
	base.e3 = cam->dir;
	ray.dir = change_base(&base, &local_dir);
	ray.dir = ft_normalize_vec3(&ray.dir);
	return (ray);
}

/**
 * @brief Get the intersection structure define by the nearest intersection
 * between a ray and all objects.
 * @param local_dir The ray direction if camera has (0,0,1) direction.
 * @param cam The camera.
 * @param tab_obj The array of objects.
 */
static t_intersec	get_near_intersec(const t_vec3 *local_dir,
	const t_cam *cam, t_obj **tab_obj)
{
	t_intersec	inter;

	inter.obj = NULL;
	inter.ray = create_ray(local_dir, cam);
	inter.soluce.t = INFINITY;
	raytracers(tab_obj, &inter);
	return (inter);
}

/**
 * @brief Put all pixels  on an image. The color of a pixel is defined by the
 * object's color intersected and the light algorithm.
 * @details To define rays, a camera has a position (0,0,0) and a
 * direction (0,0,1). The real position and direction are managed with
 * create_ray().
 * @param scene The scene structure.
 */
void	ray_lauch(t_scene *scene)
{
	t_intersec	inter;
	t_vec3		local_dir;
	t_color		c;
	int			x;
	int			y;

	local_dir.z = length_screen(scene->cam.fov);
	y = 0;
	while (y < WIN_H)
	{
		local_dir.y = y - WIN_HH;
		x = 0;
		while (x < WIN_W)
		{
			local_dir.x = x - WIN_HW;
			inter = get_near_intersec(&local_dir, &scene->cam, scene->tab_obj);
			c = lighting(scene, &inter);
			set_image_pixel(&scene->g_sys, x, y, c);
			x += scene->g_sys.def_w;
		}
		y += scene->g_sys.def_h;
	}
}

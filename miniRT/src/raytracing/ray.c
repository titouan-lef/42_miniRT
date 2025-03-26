/// @todo header

#include "minirt.h"

/**
 * Vecteur directeur du rayon partant de la camera vers le pixel.
 */
static t_vector3	get_dir_ray(t_vector3 pixel, t_vector3 dir_camera)
{
	t_vector3	dir_ray;

	dir_ray = ft_normalize_vector3(pixel);/** @todo nonzero vector */
	(void) dir_camera;
	//rotation
	return (dir_ray);
}

/**
 * couleur de l'objet le plus proche intesectant la camera en fonction du dir_ray.
 * 
 */
t_color	raytracers(t_list *lst_obj, t_vector3 dir, t_vector3 pos_cam)
{
	t_obj	*obj;
	t_color	color;
	double	length;
	double	length_min;

	color = ft_color_create(0, 0, 0, 0);
	length_min = INFINITY;
	while (lst_obj)
	{
		obj = (t_obj *)lst_obj->content;
		if (obj->type == SPHERE)
			length = intersect_ray_sphere((t_sphere *)(obj->data), dir, pos_cam);
		else if (obj->type != SPHERE)
			length = 0;
		if (length < length_min && length > 1)
		{
			length_min = length;
			color = ((t_sphere *)(obj->data))->color;
		}
		lst_obj = lst_obj->next;
	}
	return (color);
}

/**
 * camera regarde (0, 0, 1) et est en position (0, 0, 0).
 */
int	ray_lauch_test(t_scene *scene)
{
	t_vector3	pixel;
	t_vector3	dir_ray;
	t_color		pixelcolors;

	pixel.z = length_screen(scene->camera.fov);
	pixel.x = -WIN_WIDTH / 2.0;
	while (pixel.x < WIN_WIDTH / 2.0)
	{
		pixel.y = -WIN_HEIGHT / 2.0;
		while (pixel.y < WIN_HEIGHT / 2.0)
		{
			dir_ray = get_dir_ray(pixel, scene->camera.orientation);
			pixelcolors = raytracers(scene->lst_obj, dir_ray, scene->camera.position);
			set_image_pixel(&scene->graph_sys, (pixel.x + WIN_WIDTH / 2.0), (pixel.y + WIN_HEIGHT / 2.0), pixelcolors);
			pixel.y += 1.0;
		}
		pixel.x += 1.0;
	}
	return (0);
}
//closest plus proche
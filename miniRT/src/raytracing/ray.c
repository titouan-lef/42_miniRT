/// @todo header

#include "minirt.h"

t_color	raytracers(t_scene *scene, t_vector3 pixel)
{
	t_obj	*obj;
	t_color	color;
	double	length;
	double	length_min;
	t_list	*head;

	color = ft_color_create(0, 0, 0, 0);
	length_min = INFINITY;
	length = 0;
	head = scene->lst_obj;
	while (head)
	{
		obj = (t_obj *)head->content;
		if (obj->type == SPHERE)
			length = intersect_ray_sphere((t_sphere *)(obj->data),
					pixel, scene->camera.position);
		if (length < length_min && length > 1)
		{
			length_min = length;
			color = ((t_cylinder *)(obj->data))->color;
		}
		head = head->next;
	}
	return (color);
}

int	ray_lauch_test(t_scene *scene)
{
	t_vector3	pixel;
	t_vector3	dir;
	t_color		pixelcolors;

	pixel.z = length_screen(scene->camera.fov);
	pixel.x = (-1.0 * WIN_WIDTH / 2.0);
	while (pixel.x < WIN_WIDTH / 2.0)
	{
		pixel.y = (-1.0 * WIN_HEIGHT / 2.0);
		while (pixel.y < WIN_HEIGHT / 2.0)
		{
			dir = ft_normalize_vector3(pixel);/** @todo nonzero vector */
			pixelcolors = raytracers(scene, pixel);
			//colors_traitement;
			set_image_pixel(&scene->graph_sys, (pixel.y + WIN_WIDTH / 2.0), (pixel.x + WIN_HEIGHT / 2.0), pixelcolors);
			pixel.y += 1.0;
		}
		pixel.x += 1.0;
	}
	return (0);
}
//closest plus proche
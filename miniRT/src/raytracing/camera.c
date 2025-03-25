/// @todo header

#include "minirt.h"

t_color	raytracers(t_scene *scene, t_vector3 *pixel, double min, double max)
{
	t_obj	*obj;
	t_color	color;
	double	length;
	double	length_min;
	t_list	*head;

	color = ft_color_create(0, 0, 0, 0);
	length_min = INFINITY;
	head = scene->lst_obj;
	while(head)
	{
		obj = (t_obj *)scene->lst_obj->content;
		if (obj->type = SPHERE)
		{
			length = intersect_ray_sphere((t_sphere *)(obj->data), pixel, scene->camera.position);
			if (length < length_min )
			{
				length_min = length;
				color = ((t_sphere *)(obj->data))->color;
			}
		}
		else if (obj->type = PLAN)
			intersect_ray_plan();  
		else if (obj->type = CYLINDER)
			intersect_ray_cylinder();
		else if (obj->type = CONE)
			intersect_ray_cone();
		head =head->next;
	}
	return (color);
}

int	ray_lauch_test(t_scene *scene)
{
	t_vector3	pixel;
	t_vector3	dir_ray;
	int			nbpixel;
	t_color		pixelcolors;

	nbpixel = 0;
	pixel.z = length_screen(scene->camera.fov);
	pixel.x = (-1.0 * WIN_WIDTH / 2.0);
	while (pixel.x < WIN_WIDTH / 2.0)
	{
		pixel.y = (-1.0 * WIN_HEIGHT / 2.0);
		while (pixel.y < WIN_HEIGHT / 2.0)
		{
			norm_vecteur(&pixel);
			pixelcolors = raytracers(scene, &pixel, 1.0, INFINITY);
			//colors_traitement;
			//put_pixel;
			pixel.y += 1.0;
		}
		pixel.x += 1.0;
	}
	return (nbpixel);
}

//closest plus proche
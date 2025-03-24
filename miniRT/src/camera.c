/// @todo header

#include "minirt.h"
/*
int	handle_col_sphere(t_sphere *sphere, t_vector3 *pixel)
{
	double	norm_v;
	double	x2;
	double	y2;
	double	z2;
	
	x2 = (pixel->x - sphere->position.x) * (pixel->x - sphere->position.x);
	y2 = (pixel->y - sphere->position.y) * (pixel->y - sphere->position.y);
	z2 = (pixel->z - sphere->position.z) * (pixel->z - sphere->position.z);
	norm_v = sqrt(x2 + y2 + z2);
	if (norm_v <= (sphere->diam / 2.0))
	return (1);
	return (0);
}
*/
/*
int	check_colision(t_list *obj, t_vector3 *pixel)
{
	int		status;
	
	status = 0;
	status = handle_col_sphere(((t_obj *)(obj->content))->data, pixel);
	return (status);
}
*/

t_color	*intersect_ray_sphere(t_sphere *sphere, t_vector3 *pixel, t_vector3 origin)
{
	;
}

t_color	*raytracers(t_scene *scene, t_vector3 *pixel, double start, double inf)
{
	t_obj	*obj;
	t_list	*head;
	t_color	*colors;

	head = scene->lst_obj;
	while(head)
	{
		obj = (t_obj *)scene->lst_obj->content;
		if (obj->type = SPHERE)
			colors = intersect_ray_sphere((t_sphere *)(obj->data), pixel, scene->camera.position);
		else
			colors = NULL;
		head =head->next;
	}
	return (colors);
}

int	ray_lauch_test(t_scene *scene)
{
	t_vector3	pixel;
	int			nbpixel;
	t_color		*pixelcolors;

	nbpixel = 0;
	pixel.z = length_screen(scene->camera.fov);
	pixel.x = (-1.0 * WIN_WIDTH / 2.0);
	while (pixel.x < WIN_WIDTH / 2.0)
	{
		pixel.y = (-1.0 * WIN_HEIGHT / 2.0);
		while (pixel.y < WIN_HEIGHT / 2.0)
		{
			
			pixelcolors = raytracers(scene, &pixel, 1.0, INFINITY);
			//put_pixel
			pixel.y += 1.0;
		}
		pixel.x += 1.0;
	}
	return (nbpixel);
}

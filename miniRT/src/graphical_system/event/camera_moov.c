/// @todo header

#include "minirt.h"

void	camera_translation(t_scene *scene, int key)
{
	if (key == SDL_SCANCODE_W)
		scene->camera.position.z += 10;
	if (key == SDL_SCANCODE_S)
		scene->camera.position.z -= 10;
	if (key == SDL_SCANCODE_A)
		scene->camera.position.x -= 10;
	if (key == SDL_SCANCODE_D)
		scene->camera.position.x += 10;
	if (key == SDL_SCANCODE_SPACE)
		scene->camera.position.y -= 10;
	if (key == SDL_SCANCODE_F)
		scene->camera.position.y += 10;
}

void	camera_rotation(t_scene *scene, int key)
{
	t_vector3	camera;
	t_vector3	axis;

	camera = scene->camera.orientation;
	if (key == SDL_SCANCODE_Q)
	{
		axis = ft_create_vector3(0, 1, 0);
		scene->camera.orientation = ft_rotation_quaternion(camera,
				M_PI / 180.0, axis);
	}
	if (key == SDL_SCANCODE_E)
	{
		axis = ft_create_vector3(0, 1, 0);
		scene->camera.orientation = ft_rotation_quaternion(camera,
				-M_PI / 180.0, axis);
	}
}

/// @todo header

#include "minirt.h"

/**
 * @brief translation of light on x when select data = 1,
 * y when select data = 2
 * z when select data = 3. 
 */
static void	key_hook_light_translation(int key, void *param)
{
	t_menu	*menu;
	double	moov;

	menu = (t_menu *)param;
	moov = 0;
	if (key == SDL_SCANCODE_RIGHT)
		moov = 50;
	else if (key == SDL_SCANCODE_LEFT)
		moov = -50;
	if (menu->select_data == 1)
		menu->light->pos.x += moov;
	else if (menu->select_data == 2)
		menu->light->pos.y += moov;
	else if (menu->select_data == 3)
		menu->light->pos.z += moov;
}

/**
 * @brief translation of obj on x when select data = 1,
 * y when select data = 2
 * z when select data = 3. 
 */
static void	key_hook_obj_translation(int key, void *param)
{
	t_menu	*menu;
	t_vec3	*data;
	double	moov;

	menu = (t_menu *)param;
	moov = 0;
	data = get_vec_pos(menu->obj);
	if (key == SDL_SCANCODE_RIGHT)
		moov = 50;
	else if (key == SDL_SCANCODE_LEFT)
		moov = -50;
	if (menu->select_data == 1)
		data->x += moov;
	else if (menu->select_data == 2)
		data->y += moov;
	else if (menu->select_data == 3)
		data->z += moov;
}

/**
 * @brief rottation of obj on x when select data = 1,
 * y when select data = 2
 * z when select data = 3. 
 */
static void	key_hook_obj_rotation(int key, void *param)
{
	t_menu	*menu;
	t_vec3	*data;
	double	moov;
	t_vec3	axis;

	menu = (t_menu *)param;
	axis = ft_create_vec3(0, 0, 0);
	if (menu->select_data == 1)
		axis = ft_create_vec3(1, 0, 0);
	else if (menu->select_data == 2)
		axis = ft_create_vec3(0, 1, 0);
	else if (menu->select_data == 3)
		axis = ft_create_vec3(0, 0, 1);
	data = get_vec_dir(menu->obj);
	moov = 0;
	if (data == NULL || (axis.x == 0 && axis.y == 0 && axis.z == 0))
		return ;
	if (key == SDL_SCANCODE_RIGHT)
		moov = M_PI / 90;
	else if (key == SDL_SCANCODE_LEFT)
		moov = -M_PI / 90;
	*data = ft_rotation_quat(data, moov, &axis);
}

/**
 * @brief resize of obj
 * diam when select data = 1
 * height when select data = 2. 
 */
static void	key_hook_obj_resize(int key, void *param)
{
	t_menu	*menu;
	double	*data;

	menu = (t_menu *)param;
	data = NULL;
	if (menu->select_data == 1)
		data = get_obj_diam(menu->obj);
	else if (menu->select_data == 2)
		data = get_obj_height(menu->obj);
	if (data ==NULL)
		return ; 
	if (key == SDL_SCANCODE_RIGHT)
		*data += 10;
	else if (key == SDL_SCANCODE_LEFT)
	{
		if (*data > 0)
			*data -= 10;
	}
}

/**
 * @brief Manageme key for modification data obj select
 */
void	data_change(int key, void *param)
{
	t_menu	*menu;

	menu = (t_menu *)param;
	if (menu->select_l != 0)
	{
		key_hook_light_translation(key, param);
	}
	if (menu->select_obj != 0)
	{
		key_hook_select_change(key, param);
		if (menu->select_rotation != 0)
			key_hook_obj_rotation(key, param);
		else if (menu->select_resize != 0)
			key_hook_obj_resize(key, param);
		else
			key_hook_obj_translation(key, param);
	}
}

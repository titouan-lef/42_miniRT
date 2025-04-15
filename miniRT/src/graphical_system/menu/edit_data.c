/// @todo header

#include "minirt.h"

/**
 * @brief translation of light on x when select data = 1,
 * y when select data = 2
 * z when select data = 3.
 */
static void	light_translation(t_menu *menu, int sign)
{
	if (menu->select_data == 1)
		menu->light->pos.x += DIST * sign;
	else if (menu->select_data == 2)
		menu->light->pos.y += DIST * sign;
	else if (menu->select_data == 3)
		menu->light->pos.z += DIST * sign;
}

static void	key_hook_select_change(int key, void *param)
{
	t_menu	*menu;
	int		range;

	menu = (t_menu *)param;
	if (menu->enable == 0)
		return ;
	if (menu->select_type == 2 && menu->enable != 0)
		range = 3;
	else
		range = get_range(menu->obj);
	if (key == SDL_SCANCODE_UP)
		defile(&menu->select_data, 1, range, -1);
	if (key == SDL_SCANCODE_DOWN)
		defile(&menu->select_data, 1, range, 1);
}

/**
 * @brief Manageme key for modification data obj select
 */
void	data_change(int key, void *param)
{
	t_menu	*menu;
	int		sign;

	menu = (t_menu *)param;
	sign = 0;
	key_hook_select_change(key, param);
	if (key == SDL_SCANCODE_RIGHT)
		sign = 1;
	else if (key == SDL_SCANCODE_LEFT)
		sign = -1;
	if (sign == 0 || menu->enable == 0 || menu->select_type == 0)
		return ;
	if (menu->select_type == 2)
		light_translation(menu, sign);
	else if (menu->select_type == 1)
	{
		if (menu->obj->type == SPHERE)
			edit_sphere(sign, menu, (t_sphere_obj *)(menu->obj->data));
		else if (menu->obj->type == PLANE)
			edit_plane(sign, menu, (t_plane_obj *)(menu->obj->data));
		else if (menu->obj->type == CYLINDER)
			edit_cylinder(sign, menu, (t_cylinder_obj *)(menu->obj->data));
		else
			edit_cone(sign, menu, (t_cone_obj *)(menu->obj->data));
	}
}

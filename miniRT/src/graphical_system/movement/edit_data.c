/// @todo header

#include "minirt.h"

static void	obj_data_change(t_obj *obj, t_menu *menu, int sign)
{
	if (obj->type == SPHERE)
		edit_sphere(sign, menu, (t_sphere_obj *)(obj->data));
	else if (obj->type == PLANE)
		edit_plane(sign, menu, (t_plane_obj *)(obj->data));
	else if (obj->type == CYLINDER)
		edit_cylinder(sign, menu, (t_cylinder_obj *)(obj->data));
	else
		edit_cone(sign, menu, (t_cone_obj *)(obj->data));
}

void	data_change_translation(t_vec3 *pos, int coord, int sign)
{
	if (coord == 0)
		pos->x += DIST * sign;
	else if (coord == 1)
		pos->y += DIST * sign;
	else if (coord == 2)
		pos->z += DIST * sign;
}

void	key_hook_select_change(int key, void *param)
{
	t_scene	*scene;
	t_menu	*menu;
	int		range;

	scene = (t_scene *)param;
	menu = &scene->g_sys.menu;
	if (menu->option == MENU_LIGHT)
		range = 2;
	else if (menu->option == MENU_OBJ)
		range = get_range(scene->tab_obj[menu->i_submenu]);
	else
		return ;
	if (key == SDL_SCANCODE_UP)
		defile(&menu->i_subsubmenu, range, -1);
	else if (key == SDL_SCANCODE_DOWN)
		defile(&menu->i_subsubmenu, range, 1);
}

/**
 * @brief Management key for modification data obj select.
 */
void	data_change(int key, void *param)
{
	t_scene	*scene;
	t_menu	*menu;
	int		sign;

	sign = 0;
	if (key == SDL_SCANCODE_RIGHT)
		sign = 1;
	else if (key == SDL_SCANCODE_LEFT)
		sign = -1;
	scene = (t_scene *)param;
	menu = &scene->g_sys.menu;
	if (sign == 0 || menu->option <= MENU_HANDLE)
		return ;
	if (menu->option == MENU_LIGHT)
		data_change_translation(&scene->tab_l[menu->i_submenu]->pos,
			menu->i_subsubmenu, sign);
	else
		obj_data_change(scene->tab_obj[menu->i_submenu], menu, sign);
}

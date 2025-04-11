/// @todo header

#include "minirt.h"

/**
 * @brief defile the value with a start , end and increment
 */
void	defile(int *position, int start, int end, int moov)
{
	*position += moov;
	if (*position > end)
		*position = start;
	if (*position < start)
		*position = end;
}

/**
 * @brief Init all value of sttruct menu 
 */
void	init_menu(t_menu *menu)
{
	menu->enable = 0;
	menu->select_obj = 0;
	menu->select_l = 0;
	menu->select_rotation = 0;
	menu->select_resize = 0;
	menu->select_data = 1;
}

/// @todo header

#include "minirt.h"

/**
 * @brief Defile the value with a start, end and increment.
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
 * @brief Init all value of struct menu.
 */
void	init_menu(t_menu *menu)
{
	menu->enable = 0;
	menu->select_type = 0;
	menu->select_data = 1;
}

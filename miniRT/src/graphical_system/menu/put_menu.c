/// @todo header

#include "minirt.h"

void	put_menu_title(t_graph_sys *g_sys, const int *tab_y, char **tab_txt,
	size_t nb_elem)
{
	const mlx_color	c = {.rgba = WHITE};
	char			num[3];
	size_t			i;

	num[0] = ft_tochar(g_sys->menu.i_submenu % 10);
	num[1] = ')';
	num[2] = '\0';
	mlx_string_put(g_sys->mlx, g_sys->win, 10, tab_y[0], c, num);
	mlx_string_put(g_sys->mlx, g_sys->win, 30, tab_y[0], c, tab_txt[0]);
	i = 1;
	while (i < nb_elem)
	{
		mlx_string_put(g_sys->mlx, g_sys->win, 10, tab_y[i], c, tab_txt[i]);
		++i;
	}
}

void	put_menu_selection(t_graph_sys *g_sys, const int *tab_y,
	char **tab_txt, size_t nb_elem)
{
	const mlx_color	c1 = {.rgba = WHITE};
	const mlx_color	c2 = {.rgba = TEXT_COLOR};
	size_t			i;

	i = 0;
	while (i < nb_elem)
	{
		if (i == g_sys->menu.i_subsubmenu)
			mlx_string_put(g_sys->mlx, g_sys->win, 20, tab_y[i], c2,
				tab_txt[i]);
		else
			mlx_string_put(g_sys->mlx, g_sys->win, 20, tab_y[i], c1,
				tab_txt[i]);
		++i;
	}
}

/**
 * @brief Manage display of menu light.
 */
static void	menu_light_display(t_graph_sys *g_sys)
{
	const int	title_y = 15;
	const int	selection_y[3] = {30, 45, 60};
	char		*title;
	char		*selection[3];

	title = LGT;
	selection[0] = X;
	selection[1] = Y;
	selection[2] = Z;
	put_menu_title(g_sys, &title_y, &title, 1);
	put_menu_selection(g_sys, selection_y, selection, 3);
}

/**
 * @brief Manage display of menu general.
 */
static void	menu_selec_display(t_graph_sys *g_sys)
{
	const mlx_color	c = {.rgba = WHITE};
	char			*title[3];
	size_t			i;

	title[0] = M;
	title[1] = M_O;
	title[2] = M_L;
	i = 0;
	while (i < 3)
	{
		mlx_string_put(g_sys->mlx, g_sys->win, 10, (i + 1) * 15, c, title[i]);
		i++;
	}
}

/**
 * @brief Manage select display menu.
 */
void	menu_management(t_scene *scene)
{
	t_menu	*menu;

	menu = &scene->g_sys.menu;
	mlx_put_image_to_window(scene->g_sys.mlx, scene->g_sys.win,
		menu->background, 0, 0);
	if (menu->option == MENU_HANDLE)
		menu_selec_display(&scene->g_sys);
	else if (menu->option == MENU_OBJ)
		menu_obj_display(scene);
	else
		menu_light_display(&scene->g_sys);
}

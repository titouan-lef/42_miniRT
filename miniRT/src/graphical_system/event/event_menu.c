/// @todo header

#include "minirt.h"

static void	key_hook_menu_enable(int key, void *param)
{
	static int	menu_enable = 0;
	t_graph_sys	*mlx;

	mlx = (t_graph_sys *)param;
	if (key == SDL_SCANCODE_M)
	{
		menu_enable = 1 - menu_enable;
		if (menu_enable == 1)
			mlx->menu_enable = 1;
		else
			mlx->menu_enable = 0;
	}
}

void	menu_event(t_scene *scene)
{

	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP, key_hook_menu_enable,
		&scene->g_sys);
}
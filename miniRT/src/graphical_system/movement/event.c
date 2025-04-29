/// @todo header

#include "minirt.h"

static void	key_hook(int key, void *param)
{
	mlx_context	mlx;

	mlx = (mlx_context)param;
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(mlx);
}

static void	window_hook(int event, void *param)
{
	if (event == WIN_CLOSE)
		mlx_loop_end((mlx_context)param);
}

static void	change_resol(t_graph_sys	*mlx, int *resol)
{
	*resol = 1 - *resol;
	if (*resol == 1)
	{
		mlx->def_h = 9;
		mlx->def_w = 16;
	}
	else
	{
		mlx->def_h = 1;
		mlx->def_w = 1;
	}
}

/**
 * @brief Manage full screen with F11
 * @details When you press F11 the window pass in full mode 
 * if you repress window repasse in normal mode
 */
static void	key_hook_fwin(int key, void *param)
{
	static int	fullscreen = 0;
	static int	resol = 0;
	t_graph_sys	*mlx;

	mlx = (t_graph_sys *)param;
	if (key == SDL_SCANCODE_F11)
	{
		fullscreen = 1 - fullscreen;
		mlx_set_window_fullscreen(mlx->mlx, mlx->win, fullscreen);
	}
	if (key == SDL_SCANCODE_F10)
		change_resol(mlx, &resol);
	if (key == SDL_SCANCODE_F9)
	{
		mlx->menu.mouse_is_hide = 1 - mlx->menu.mouse_is_hide;
		if (mlx->menu.mouse_is_hide == 1)
			mlx_mouse_hide(mlx->mlx);
		else
			mlx_mouse_show(mlx->mlx);
	}
}

void	on_event(t_scene *scene)
{
	t_graph_sys	*g_sys;

	g_sys = &scene->g_sys;
	mlx_on_event(g_sys->mlx, g_sys->win, MLX_WINDOW_EVENT, window_hook,
		g_sys->mlx);
	mlx_on_event(g_sys->mlx, g_sys->win, MLX_KEYUP, key_hook_fwin,
		&scene->g_sys);
	mlx_on_event(g_sys->mlx, g_sys->win, MLX_KEYDOWN, key_hook,
		g_sys->mlx);
	mlx_on_event(g_sys->mlx, g_sys->win, MLX_KEYDOWN, key_hook_cam,
		scene);
	menu_event(scene);
}

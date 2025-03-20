/// @todo header

#include "minirt.h"

static mlx_window_create_info	get_win_info(void)
{
	mlx_window_create_info	win_info;

	win_info.render_target = NULL;
	win_info.title = WIN_NAME;
	win_info.width = WIN_WIDTH;
	win_info.height = WIN_HEIGHT;
	win_info.is_fullscreen = 0;
	win_info.is_resizable = 0;
	return (win_info);
}

int	init_window(t_graph_sys *graph_sys)
{
	mlx_window_create_info	win_info;

	win_info = get_win_info();
	graph_sys->win = mlx_new_window(graph_sys->mlx, &win_info);
	if (graph_sys->win == MLX_NULL_HANDLE)
	{
		ft_putendl_error(ERR_WIN_INIT);
		return (1);
	}
	return (0);
}
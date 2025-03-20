/// @todo header

#ifndef GRAPHICAL_SYSTEM_H
# define GRAPHICAL_SYSTEM_H

# include "../MacroLibX/includes/mlx.h"

/***********************************************
 * @brief Error Code
 ***********************************************/

# ifndef ERR_MLX_INIT
#  define ERR_MLX_INIT "Error initialization mlx"
# endif

# ifndef ERR_WIN_INIT
#  define ERR_WIN_INIT "Error initialization window"
# endif

/***********************************************
 * @brief Window Info
 ***********************************************/

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1920
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1080
# endif

# ifndef WIN_NAME
#  define WIN_NAME "miniRT"
# endif

/***********************************************
 * @struct Graphical System
 ***********************************************/

typedef struct s_graph_sys
{
	mlx_context	mlx;
	mlx_window	win;
	mlx_image	back_buffer;
	mlx_image	front_buffer;
}	t_graph_sys;

/***********************************************
 * @file graphical_system.c
 ***********************************************/
void	clean_graph_sys(t_graph_sys *graph_sys);
int		init_graphical_data(t_graph_sys *graph_sys);

/***********************************************
 * @file window.c
 ***********************************************/
int		init_window(t_graph_sys *graph_sys);

#endif
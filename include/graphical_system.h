/// @todo header

#ifndef GRAPHICAL_SYSTEM_H
# define GRAPHICAL_SYSTEM_H

# include <SDL2/SDL_scancode.h>
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
 * @enum Window Event
 ***********************************************/
typedef enum e_win_event
{
	WIN_CLOSE,
	WIN_MOVED,
	WIN_MINIMIZED,
	WIN_MAXIMIZED,
	WIN_ENTER,
	WIN_FOCUS_GAINED,
	WIN_LEAVE,
	WIN_FOCUS_LOST,
	WIN_SIZE_CHANGED,
}	t_win_event;

/***********************************************
 * @file graphical_system.c
 ***********************************************/
int		manage_graphical_system(void);

/***********************************************
 * @file window.c
 ***********************************************/
int		init_window(t_graph_sys *graph_sys);

/***********************************************
 * @file event.c
 ***********************************************/
void	on_event(t_graph_sys *graph_sys);

#endif
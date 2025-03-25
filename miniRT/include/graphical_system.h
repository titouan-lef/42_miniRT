/// @todo header

#ifndef GRAPHICAL_SYSTEM_H
# define GRAPHICAL_SYSTEM_H

# include "minirt.h"
# include <SDL2/SDL_scancode.h>
# include "../MacroLibX/includes/mlx.h"


/***********************************************
 * @brief Error Code
 ***********************************************/
# ifndef ERR_MLX_INIT
#  define ERR_MLX_INIT "Error initialization mlx"
# endif

# ifndef ERR_BACK_BUFFER_INIT
#  define ERR_BACK_BUFFER_INIT "Error initialization back buffer"
# endif

# ifndef ERR_FRONT_BUFFER_INIT
#  define ERR_FRONT_BUFFER_INIT "Error initialization front buffer"
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
 * @struct Double Buffering
 ***********************************************/
typedef struct s_double_buffer
{
	mlx_image	buffers[2];
	mlx_image	*back;
	mlx_image	*front;
}	t_double_buffer;

/***********************************************
 * @struct Graphical System
 ***********************************************/
typedef struct s_graph_sys
{
	mlx_context		mlx;
	mlx_window		win;
	t_double_buffer	buff;
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
 * @file double_buffer.c
 ***********************************************/
void	swap_buffer(t_double_buffer *buff);
void	clean_double_buffer(t_graph_sys *graph_sys);
int		init_double_buffer(t_graph_sys *graph_sys);

/***********************************************
 * @file image.c
 ***********************************************/
void	put_image_to_win(t_graph_sys *graph_sys);
void	set_image_pixel(t_graph_sys *graph_sys, int x, int y, t_color c);

/***********************************************
 * @file window.c
 ***********************************************/
int		init_window(t_graph_sys *graph_sys);

/***********************************************
 * @file event.c
 ***********************************************/
void	on_event(t_graph_sys *graph_sys);

#endif
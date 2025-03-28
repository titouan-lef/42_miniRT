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
# ifndef WIN_W
#  define WIN_W 1920.0
# endif

# ifndef WIN_H
#  define WIN_H 1080.0
# endif

# ifndef WIN_HW
#  define WIN_HW 960.0
# endif

# ifndef WIN_HH
#  define WIN_HH 540.0
# endif

# ifndef WIN_NAME
#  define WIN_NAME "miniRT"
# endif

# ifndef FPS
#  define FPS 24
# endif

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
 * @file graphical_system.c
 ***********************************************/
int		manage_graphical_system(t_scene	*scene);

/***********************************************
 * @file event.c
 ***********************************************/
void	on_event(t_scene *scene);

/***********************************************
 * @file camera_moov.c
 ***********************************************/
void	mouse_event(t_scene *scene, t_graph_sys *graph_sys);
void	key_hook_cam(int key, void *param);

#endif
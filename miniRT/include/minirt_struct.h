#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "minirt.h"
# include <SDL2/SDL_scancode.h>
# include "../MacroLibX/includes/mlx.h"

/***********************************************
 * @enum Type of Object
 ***********************************************/
typedef enum e_obj_type
{
	OBJ_ERR,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLAN,
	CYLINDER,
	CONE,
}	t_obj_type;

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
 * @struct OBJ
 ***********************************************/
typedef struct s_obj
{
	int			type;
	void		*data;
}	t_obj;

/***********************************************
 * @struct CAMBIENT
 ***********************************************/
typedef struct s_ambient
{
	t_color	color;
	double	lr;
}	t_ambient;

/***********************************************
 * @struct CAMERA
 ***********************************************/
typedef struct s_camera
{
	t_vector3	position;
	t_vector3	orientation;
	int			fov;
}	t_camera;

/***********************************************
 * @struct LIGHT
 ***********************************************/
typedef struct s_light
{
	t_color		color;
	double		lbr;
	t_vector3	position;
}	t_light;

/***********************************************
 * @struct SPHERE
 ***********************************************/
typedef struct s_sphere
{
	t_color		color;
	t_vector3	position;
	double		diam;
	double		r;
	t_vector3	rs0;

}	t_sphere;

/***********************************************
 * @struct PLAN
 ***********************************************/
typedef struct s_plan
{
	t_color		color;
	t_vector3	position;
	t_vector3	orientation;
	t_vector3	rp0;
}	t_plan;

/***********************************************
 * @struct CYLINDER
 ***********************************************/
typedef struct s_cylinder
{
	t_color		color;
	t_vector3	position;
	t_vector3	orientation;
	double		diam;
	double		height;
	double		r;
	t_vector3	bc_o;
	double		bc_o_dot_dir;
}	t_cylinder;

/***********************************************
 * @struct CONE
 ***********************************************/
typedef struct s_cone
{
	t_color		color;
	t_vector3	position;
	t_vector3	orientation;
	double		diam;
	double		height;
}	t_cone;

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
 * @struct SCENE
 ***********************************************/
typedef struct s_scene
{
	t_list		*lst_obj;
	t_list		*lst_light;
	t_ambient	ambient;
	t_camera	camera;
	t_graph_sys	graph_sys;
}	t_scene;

/***********************************************
 * @struct PIXEL
 ***********************************************/
typedef struct	s_pixel
{
	t_color		color;
	t_vector3	ray_dir;
	t_vector3	pos;
	t_obj		*obj;
	double		d;
}	t_pixel;

#endif
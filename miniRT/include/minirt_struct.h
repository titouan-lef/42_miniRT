/// @todo header

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
	PLANE,
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
	int		type;
	void	*data;
}	t_obj;

/***********************************************
 * @struct AMBIENT
 * @param color Light color.
 * @param lr Light ratio.
 ***********************************************/
typedef struct s_amb
{
	t_color	color;
	double	lr;
}	t_amb;

/***********************************************
 * @struct LIGHT
 * @param color Light color.
 * @param lbr Light brightness.
 * @param pos Light position.
 ***********************************************/
typedef struct s_light
{
	t_color	color;
	double	lbr;
	t_vec3	pos;
}	t_light;

/***********************************************
 * @struct CAMERA
 ***********************************************/
typedef struct s_cam
{
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	right;
	t_vec3	up;
	int		fov;
}	t_cam;

/***********************************************
 * @struct SPHERE
 * @param
 ***********************************************/
typedef struct s_sphere
{
	t_vec3	pos;
	double	r;
}	t_sphere;

typedef struct s_math_sp
{
	t_vec3	os;
	double	c_factor;
}	t_math_sp;

typedef struct s_sphere_obj
{
	t_color		color;
	t_sphere	sp;
	t_math_sp	mathsp;
}	t_sphere_obj;

/***********************************************
 * @struct PLANE
 ***********************************************/
typedef struct s_plane_obj
{
	t_color	color;
	t_plane	pl;
	double	math_os_dot_odir;
}	t_plane_obj;

/***********************************************
 * @struct CYLINDER
 ***********************************************/
typedef struct s_cylinder
{
	t_vec3	pos;
	t_vec3	dir;
	double	hh;
	double	r;
}	t_cylinder;

typedef struct s_math_cy
{
	t_vec3	os;
	double	os_dot_odir;
	double	c_factor;
	t_vec3	b;
	t_vec3	t;
	double	bs_dot_odir;
	double	ts_dot_odir;
}	t_math_cy;

typedef struct s_cylinder_obj
{
	t_color		color;
	t_cylinder	cy;
	t_math_cy	mathcy;
}	t_cylinder_obj;

/***********************************************
 * @struct CONE
 ***********************************************/
typedef struct s_cone
{
	t_vec3	pos;
	t_vec3	dir;
	double	h;
	double	r;
}	t_cone;

typedef struct s_math_co
{
	t_vec3	b;
	t_vec3	bs;
	double	angle_factor;
	double	bs_dot_odir;
	double	c_factor;
	t_vec3	t;
	double	ts_dot_odir;
}	t_math_co;

typedef struct s_cone_obj
{
	t_color		color;
	t_cone		co;
	t_math_co	mathco;
}	t_cone_obj;

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
 * @struct Menu
 ***********************************************/
typedef struct s_menu
{
	int		enable;
	int		select_obj;
	int		select_l;
	int		select_data;
	int		select_rotation;
	int		select_resize;
	t_obj	*obj;
	t_light	*light;
	t_vec3	*cam_dir;//debug
}	t_menu;

/***********************************************
 * @struct Graphical System
 ***********************************************/
typedef struct s_graph_sys
{
	mlx_context		mlx;
	mlx_window		win;
	t_double_buffer	buff;
	t_menu			menu;
	int				def_w;
	int				def_h;
}	t_graph_sys;

/***********************************************
 * @struct SCENE
 ***********************************************/
typedef struct s_scene
{
	t_obj		**tab_obj;
	t_light		**tab_l;
	t_amb		amb;
	t_cam		cam;
	t_graph_sys	g_sys;
}	t_scene;

/***********************************************
 * @struct Parsing List
 ***********************************************/
typedef struct s_lst_parse
{
	t_list	*lst_obj;
	t_list	*lst_l;
}	t_lst_parse;

/***********************************************
 * @struct RAY
 * @param s Ray start.
 * @param dir Ray direction.
 ***********************************************/
typedef struct s_ray
{
	t_vec3	s;
	t_vec3	dir;
}	t_ray;

/***********************************************
 * @struct INTERSECTION
 ***********************************************/
typedef struct s_intersec
{
	t_ray		ray;
	const t_obj	*obj;
	t_vec3		p;
}	t_intersec;

#endif
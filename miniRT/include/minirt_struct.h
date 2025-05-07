/// @todo header

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "minirt.h"

/***********************************************
 * @details ENUM
 ***********************************************/
/** @enum Type of Object */
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

/** @enum Window Event */
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

/** @enum Menu Option */
typedef enum e_menu_option
{
	MENU_DISABLE,
	MENU_HANDLE,
	MENU_OBJ,
	MENU_LIGHT,
}	t_menu_option;

/***********************************************
 * @struct Menu
 ***********************************************/
typedef struct s_menu
{
	t_menu_option	option;
	size_t			i_submenu;
	size_t			i_subsubmenu;
	int				mouse_is_hide;
	mlx_image		background;
}	t_menu;

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
	t_menu			menu;
	int				def_w;
	int				def_h;
}	t_graph_sys;

/***********************************************
 * @struct Base
 ***********************************************/
typedef struct s_base
{
	t_vec3	e1;
	t_vec3	e2;
	t_vec3	e3;
}	t_base;

/***********************************************
 * @struct Image
 ***********************************************/
typedef struct s_img
{
	char		*name;
	mlx_image	img;
	int			width;
	int			heigth;
}	t_img;

/***********************************************
 * @struct Pattern
 ***********************************************/
typedef struct s_pattern
{
	t_img		bump;
	t_img		texture;
	t_vec3		colors;
	int			checkerboard;
}	t_pattern;

/***********************************************
 * @struct Normal Map
 * @param base Base (tangent, bitangent, normal).
 * @param n Normal get with an image.
 ***********************************************/
typedef struct s_normal_map
{
	t_base	base;
	t_vec3	n;
}	t_normal_map;

/***********************************************
 * @struct Ambient Light
 * @param color Light color.
 * @param lr Light ratio.
 ***********************************************/
typedef struct s_amb
{
	t_vec3	color;
	double	lr;
}	t_amb;

/***********************************************
 * @struct Point Light
 * @param color Light color.
 * @param lbr Light brightness.
 * @param pos Light position.
 ***********************************************/
typedef struct s_light
{
	t_vec3	color;
	t_vec3	pos;
	double	lbr;
}	t_light;

/***********************************************
 * @struct Phong Shading
 ***********************************************/
typedef struct s_phong
{
	t_vec3	ambient;
	t_vec3	diffuse;
	t_vec3	specular;
}	t_phong;

/***********************************************
 * @struct Object
 ***********************************************/
typedef struct s_obj
{
	t_pattern	pattern;
	int			type;
	void		*data;
}	t_obj;

/***********************************************
 * @struct Camera
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
 * @struct Sphere
 * @param
 ***********************************************/
typedef struct s_sphere
{
	t_vec3	pos;
	double	r;
}	t_sphere;

/***********************************************
 * @struct Mathematics Sphere
 ***********************************************/
typedef struct s_math_sp
{
	t_vec3	os;
	double	c_factor;
}	t_math_sp;

/***********************************************
 * @struct Sphere Object
 ***********************************************/
typedef struct s_sphere_obj
{
	t_sphere	sp;
	t_math_sp	mathsp;
}	t_sphere_obj;

/***********************************************
 * @struct Plane
 ***********************************************/
typedef struct s_plane_obj
{
	t_plane		pl;
	t_vec3		right;
	t_vec3		up;
	double		math_os_dot_odir;
}	t_plane_obj;

/***********************************************
 * @struct Cylinder
 ***********************************************/
typedef struct s_cylinder
{
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	right;
	t_vec3	up;
	double	hh;
	double	r;
}	t_cylinder;

/***********************************************
 * @struct Mathematics Cylinder
 ***********************************************/
typedef struct s_math_cy
{
	t_vec3	os;
	double	os_dot_odir;
	double	c_factor;
	t_vec3	b;
	t_vec3	t;
	double	bs_dot_odir;
	double	ts_dot_odir;
	double	raydir_dot_odir;
}	t_math_cy;

/***********************************************
 * @struct Cylinder Object
 ***********************************************/
typedef struct s_cylinder_obj
{
	t_cylinder	cy;
	t_math_cy	mathcy;
}	t_cylinder_obj;

/***********************************************
 * @struct Cone
 ***********************************************/
typedef struct s_cone
{
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	right;
	t_vec3	up;
	double	h;
	double	r;
}	t_cone;

/***********************************************
 * @struct Mathematics Cone
 ***********************************************/
typedef struct s_math_co
{
	t_vec3	b;
	t_vec3	bs;
	double	angle_factor;
	double	bs_dot_odir;
	double	c_factor;
	t_vec3	t;
	double	ts_dot_odir;
	double	raydir_dot_odir;
}	t_math_co;

/***********************************************
 * @struct Cone Object
 ***********************************************/
typedef struct s_cone_obj
{
	t_cone		co;
	t_math_co	mathco;
}	t_cone_obj;

/***********************************************
 * @struct Scene
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
 * @struct Ray
 * @param s Ray start.
 * @param dir Ray direction.
 ***********************************************/
typedef struct s_ray
{
	t_vec3	s;
	t_vec3	dir;
}	t_ray;

/***********************************************
 * @struct Solution Equation
 ***********************************************/
typedef struct s_soluce
{
	double	t;
	t_vec3	p;
	t_vec3	n;
}	t_soluce;

/***********************************************
 * @struct Intersection
 ***********************************************/
typedef struct s_intersec
{
	t_ray		ray;
	const t_obj	*obj;
	t_soluce	soluce;
	t_vec2		uv_cb;
	t_vec2		uv_bm;
}	t_intersec;

/***********************************************
 * @struct Parsing List
 ***********************************************/
typedef struct s_lst_parse
{
	t_list	*lst_obj;
	t_list	*lst_l;
}	t_lst_parse;

#endif
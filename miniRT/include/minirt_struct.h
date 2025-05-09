/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:41:51 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:41:55 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
 * @param mlx Mlx context
 * @param win Mlx window
 * @param buff Double buffer
 * @param menu Menu
 * @param def_w Width definition
 * @param def_h Height definition
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
 * @param name Image name
 * @param img Mlx image
 * @param width Width
 * @param heigth Heigth
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
 * @param bump Bump map image
 * @param texture Texture image
 * @param color Object color
 * @param checkerboard Number of split for checkerboard
 ***********************************************/
typedef struct s_pattern
{
	t_img		bump;
	t_img		texture;
	t_vec3		color;
	int			checkerboard;
}	t_pattern;

/***********************************************
 * @struct Normal Map
 * @param base Base (tangent, bitangent, normal)
 * @param n Normal get with an image
 ***********************************************/
typedef struct s_normal_map
{
	t_base	base;
	t_vec3	n;
}	t_normal_map;

/***********************************************
 * @struct Ambient Light
 * @param color Light color
 * @param lr Light ratio
 ***********************************************/
typedef struct s_amb
{
	t_vec3	color;
	double	lr;
}	t_amb;

/***********************************************
 * @struct Point Light
 * @param color Light color
 * @param lbr Light brightness
 * @param pos Light position
 ***********************************************/
typedef struct s_light
{
	t_vec3	color;
	t_vec3	pos;
	double	lbr;
}	t_light;

/***********************************************
 * @struct Phong Shading
 * @param ambient Ambient light color
 * @param diffuse Diffuse light color
 * @param specular Specular light color
 ***********************************************/
typedef struct s_phong
{
	t_vec3	ambient;
	t_vec3	diffuse;
	t_vec3	specular;
}	t_phong;

/***********************************************
 * @struct Object
 * @param pattern Object pattern
 * @param type Object type
 * @param data Object data
 ***********************************************/
typedef struct s_obj
{
	t_pattern	pattern;
	t_obj_type	type;
	void		*data;
}	t_obj;

/***********************************************
 * @struct Camera
 * @param pos Position
 * @param dir Orientation vector
 * @param right Right vector
 * @param up Up vector
 * @param fov Field of view
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
 * @param pos Position
 * @param r Radius
 ***********************************************/
typedef struct s_sphere
{
	t_vec3	pos;
	double	r;
}	t_sphere;

/***********************************************
 * @struct Mathematics Sphere
 * @param os Vector(object, start ray)
 * @param c_factor C factor of quadratic equation
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
 * @struct Plane Object
 * @param pl Plane
 * @param right Right vector
 * @param up Up vector
 * @param math_os_dot_odir Vector(object, start ray) . Vector(object direction)
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
 * @param pos Position
 * @param dir Orientation vector
 * @param right Right vector
 * @param up Up vector
 * @param hh Half height
 * @param r Radius
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
 * @param os Vector(object, start ray)
 * @param os_dot_odir Vector(object, start ray) . Vector(object direction)
 * @param c_factor C factor of quadratic equation
 * @param b Center of bottom cap
 * @param t Center of top cap
 * @param bs_dot_odir Vector(b, start ray) . Vector(object direction)
 * @param ts_dot_odir Vector(t, start ray) . Vector(object direction)
 * @param raydir_dot_odir Vector(ray direction) . Vector(object direction)
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
 * @param pos Position
 * @param dir Orientation vector
 * @param right Right vector
 * @param up Up vector
 * @param h Height
 * @param r Radius
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
 * @param b Center of bottom cap
 * @param bs Vector(b, start ray)
 * @param angle_factor Factor angle
 * @param bs_dot_odir Vector(b, start ray) . Vector(object direction)
 * @param c_factor C factor of quadratic equation
 * @param t Center of top cap
 * @param ts_dot_odir Vector(t, start ray) . Vector(object direction)
 * @param raydir_dot_odir Vector(ray direction) . Vector(object direction)
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
 * @param tab_obj Object table
 * @param tab_l Light table
 * @param amb Ambiant light
 * @param cam Camera
 * @param g_sys Graphical system
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
 * @param s Ray start
 * @param dir Ray direction
 ***********************************************/
typedef struct s_ray
{
	t_vec3	s;
	t_vec3	dir;
}	t_ray;

/***********************************************
 * @struct Solution Equation
 * @param t Scalar of equation to determine the point of intersection
 * @param p Intersection point
 * @param n Normal of intersection point
 ***********************************************/
typedef struct s_soluce
{
	double	t;
	t_vec3	p;
	t_vec3	n;
}	t_soluce;

/***********************************************
 * @struct Intersection
 * @param ray Ray
 * @param obj Object
 * @param soluce Solution of intersection
 * @param uv_cb Checkboard uv at the intersection
 * @param uv_bm Bump map uv at the intersection
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
 * @param lst_obj Object list
 * @param lst_l Light list
 ***********************************************/
typedef struct s_lst_parse
{
	t_list	*lst_obj;
	t_list	*lst_l;
}	t_lst_parse;

#endif
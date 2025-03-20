#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "minirt_err.h"
# include "graphical_system.h"

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

typedef struct s_obj
{
	int			type;
	void		*data;
}	t_obj;

/*	RGB range [0-255], lr range [0.0, 1.0]*/
typedef struct s_ambient
{
	t_color	color;
	double	lr;
}	t_ambient;

/*	RGB range [0-255], lr range [0.0, 1.0], FOV [0, 180]*/
typedef struct s_camera
{
	t_vector3	position;
	t_vector3	orientation;
	int			fov;
}	t_camera;

/*	RGB range [0-255], lbr range [0.0, 1.0]*/
typedef struct s_light
{
	t_color		color;
	double		lbr;
	t_vector3	position;
}	t_light;

typedef struct s_sphere
{
	t_color		color;
	t_vector3	position;
	double		diam;

}	t_sphere;

typedef struct s_plan
{
	t_color		color;
	t_vector3	position;
	t_vector3	orientation;
}	t_plan;

typedef struct s_cylinder
{
	t_color		color;
	t_vector3	position;
	t_vector3	orientation;
	double		diam;
	double		height;
}	t_cylinder;

typedef struct s_cone
{
	t_color		color;
	t_vector3	position;
	t_vector3	orientation;
	double		diam;
	double		height;
}	t_cone;

typedef struct s_scene
{
	t_list		*lst_obj;
	t_list		*lst_light;
	t_ambient	ambient;
	t_camera	camera;
	//mlx
}	t_scene;

/***********************************************
 *  @file parsing.c
 ***********************************************/
int		parsing(int argc, char **argv, t_scene *scene);

/***********************************************
 *  @file parsing_utils.c
 ***********************************************/
int		alloc_new_obj(t_list **head, void *new_sphere, t_obj_type type);
int		take_dimension(double *dimension, char *str);
void	init_scene(t_scene *scene);
int		check_files_type(char *str);
int		check_valid_id(char *str);

/***********************************************
 *  @file parsing_ambient.c
 ***********************************************/
int		ambient_interpreter(t_scene *scene, char **tab);

/***********************************************
 *  @file parsing_camera.c
 ***********************************************/
int		camera_interpreter(t_scene *scene, char **tab);

/***********************************************
 *  @file parsing_colors.c
 ***********************************************/
int		take_color(t_color *colors, char *str);

/***********************************************
 *  @file parsing_vecteur.c
 ***********************************************/
int		take_position(t_vector3 *position, char *str);
int		take_orientation(t_vector3 *position, char *str);

/***********************************************
 *  @file parsing_light.c
 ***********************************************/
int		light_interpreter(t_scene *scene, char **tab);

/***********************************************
 *  @file parsing_sphere.c
 ***********************************************/
int		sphere_interpreter(t_scene *scene, char **tab);

/***********************************************
 *  @file parsing_plan.c
 ***********************************************/
int		plan_interpreter(t_scene *scene, char **tab);

/***********************************************
 *  @file parsing_cylinder.c
 ***********************************************/
int		cylinder_interpreter(t_scene *scene, char **tab);

/***********************************************
 *  @file parsing_cone.c
 ***********************************************/
int		cone_interpreter(t_scene *scene, char **tab);

/***********************************************
 *  @file parsing_error.c
 ***********************************************/
void	exit_error_parsing(t_scene *scene);
void	print_error_message(char *str);

#endif
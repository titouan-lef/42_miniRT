#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

/*	RGB range [0-255], lr range [0.0, 1.0]*/
typedef	struct	s_ambiance
{
	double	lr;
	t_color	color;
}	t_ambiance;

/*	RGB range [0-255], lr range [0.0, 1.0], FOV [0, 180]*/
typedef	struct	s_camera
{
	t_vector3 	position;
	t_vector3	orientation;
	int			fov;
}	t_camera;

/*	RGB range [0-255], lbr range [0.0, 1.0]*/
typedef	struct	s_light
{
	t_vector3 	position;
	double		lbr;
	t_color		color;
}	t_light;

typedef	struct	s_sphere
{
	t_vector3 	position;
	double		diam;
	t_color		color;

}	t_sphere;

typedef	struct	s_plan
{
	t_vector3 	position;
	t_vector3	orientation;
	t_color		color;
}	t_plan;

typedef	struct	s_cylinder
{
	t_vector3 	position;
	t_vector3	orientation;
	double		diam;
	double		height;
	t_color		color;
}	t_cylinder;

typedef	struct	s_cone
{
	t_vector3 	position;
	t_vector3	orientation;
	double		diam;
	double		height;
	t_color		color;
}	t_cone;

typedef	struct s_scene
{
	t_ambiance	ambiance;
	t_camera	camera;
	t_light		light;
	t_sphere	sphere;
	t_plan		plan;
	t_cylinder	cylinder;
	t_cone		cone;
}	t_scene;

#endif
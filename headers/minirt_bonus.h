#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef	struct s_scene
{
	int	nb_ambiance;
	int	nb_camera;
	int	nb_light;
	int	nb_sphere;
	int	nb_plan;
	int nb_cylinder;
	t_ambiance	ambiance;
	t_camera	camera;
	t_light		light;
	t_sphere	sphere;
	t_plan		plan;
	t_cylinder	cylinder;
}	t_scene;

/*	RGB range [0-255], lr range [0.0, 1.0]*/
typedef	struct	s_ambiance
{
	float	lr;
	int		red;
	int		green;
	int		blue;
}	t_ambiance;

/*	RGB range [0-255], lr range [0.0, 1.0], FOV [0, 180]*/
typedef	struct	s_camera
{
	float	x_view;
	float	y_view;
	float	z_view;
	float	x_nor;
	float	y_nor;
	float	z_nor;
	int		fov;
}	t_camera;

/*	RGB range [0-255], lbr range [0.0, 1.0]*/
typedef	struct	s_light
{
	float	x_view;
	float	y_view;
	float	z_view;
	float	lbr;
	int		red;
	int		green;
	int		blue;
}	t_light;

typedef	struct	s_sphere
{
	float	x_pos;
	float	y_pos;
	float	z_pos;
	float	diam;
	int		red;
	int		green;
	int		blue;

}	t_sphere;

typedef	struct	s_plan
{
	float	x_view;
	float	y_view;
	float	z_view;
	float	x_nnv;
	float	y_nnv;
	float	z_nnv;
	int		red;
	int		green;
	int		blue;
}	t_plan;

typedef	struct	s_cylinder
{
	float	x_view;
	float	y_view;
	float	z_view;
	float	x_nnv;
	float	y_nnv;
	float	z_nnv;
	float	diam;
	float	height;
	int		red;
	int		green;
	int		blue;
}	t_cylinder;

typedef	struct	s_cone
{
	float	x_view;
	float	y_view;
	float	z_view;
	float	x_nnv;
	float	y_nnv;
	float	z_nnv;
	float	diam;
	float	height;
	int		red;
	int		green;
	int		blue;
}	t_cone;
#endif
#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include "minirt_struct.h"
# include "minirt_parsing.h"
# include "minirt_err.h"
# include "graphical_system.h"

int			ray_lauch_test(t_scene *scene);
void		norm_vecteur(t_vector3 *vector);

double		length_screen(double fov);
double		quadratic_equation(double A, double B, double C);

void		init_calculation(t_scene *scene, t_list *lst_obj);

double		intersect_ray_plan(t_plan *plan, t_vector3 ray_dir,
				t_vector3 orig);
double		intersect_ray_sphere(t_sphere *sphere, t_vector3 ray_dir);

double		intersect_ray_cylinder(t_cylinder *cyl, t_vector3 dir_ray,
				t_vector3 cam_pos);
t_vector3	calculation_born(t_vector3 c, t_vector3 n, double d);
void		calculation_cyl_s(t_vector3 *cyl_s, t_vector3 ra1, t_vector3 ra2);
void		calculation_cyl_ra0(t_vector3 *ra0, t_vector3 s, t_vector3 low,
				t_vector3 r0);

t_color		ambient_colors(t_color obj_color, t_ambient ambient);

#endif
/// @todo header

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
# include "minirt_colors.h"

int		ray_lauch_test(t_scene *scene);

double	length_screen(double fov);
double	quadratic_equation(double a, double b, double c);

void	init_calculation(const t_vec3 *ray_s, t_list *lst_obj);

double	intersect_ray_plane_value(double os_dot_odir, double raydir_dot_odir);
double	intersect_ray_plane(const t_plane_obj *plane, const t_ray *ray);
double	intersect_light_plane(const t_plane_obj *plane, const t_ray *ray);

double	intersect_ray_sphere(const t_sphere_obj *sphere, const t_vec3 *ray_dir);
double	intersect_light_sphere(const t_sphere_obj *sphere, const t_ray *ray);

double	intersect_ray_cylinder(const t_cylinder_obj *cyl, const t_ray *ray);

#endif
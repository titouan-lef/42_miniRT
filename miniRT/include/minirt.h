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

void	init_calculation(t_scene *scene, t_list *lst_obj);

double	intersect_ray_plan(t_plane_obj *plan, const t_vec3 *ray_dir,
			const t_vec3 *orig);
double	intersect_ray_sphere(t_sphere_obj *sphere, const t_vec3 *ray_dir);

double	intersect_ray_cylinder(t_cylinder_obj *cyl, const t_vec3 *ray_dir,
			const t_vec3 *cam_pos);
t_vec3	calculation_born(const t_vec3 *c, const t_vec3 *n, double d);

#endif
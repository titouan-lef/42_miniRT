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

int		ray_lauch_test(t_scene *scene);
void	norm_vecteur(t_vector3 *vector);
double	length_screen(double fov);
double	quadratic_equation(double A, double B, double C);

double	intersect_ray_plan(t_plan *plan, t_vector3 ray_dir,
			t_vector3 orig);
double	intersect_ray_sphere(t_sphere *sphere,
			t_vector3 pixel, t_vector3 origin);
double	intersect_ray_cylinder(t_cylinder *cylinder,
			t_vector3 dir_ray, t_vector3 org);


void	camera_translation(t_scene *scene, int key);
void	camera_rotation(t_scene *scene, double x, double y);
void	mouse_event(t_scene *scene, t_graph_sys *graph_sys);
void	key_hook_cam(int key, void *param);

t_color	colors_traitement(t_color obj_color, t_ambient ambient);

#endif
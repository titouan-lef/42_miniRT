#ifndef MINIRT_H
# define MINIRT_H

# include "minirtstruct.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "minirt_err.h"
# include "graphical_system.h"


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
int		check_valid_id(char *str, int *ambient, int *camera);

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

/***********************************************
 * @file graphical_system.c
 ***********************************************/
int		manage_graphical_system(t_scene	*scene);

/***********************************************
 * @file event.c
 ***********************************************/
void	on_event(t_scene *scene);

void	camera_translation(t_scene *scene, int key);
void	camera_rotation(t_scene *scene, double x, double y);
void	mouse_event(t_scene *scene, t_graph_sys *graph_sys);
void	key_hook_cam(int key, void *param);

t_color	colors_traitement(t_color obj_color, t_ambient ambient);

#endif
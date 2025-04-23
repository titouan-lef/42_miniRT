/// @todo header

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

# include "minirt.h"

/***********************************************
 *  @file parsing.c
 ***********************************************/
int		parsing(int argc, char **argv, t_scene *scene);

/***********************************************
 *  @file parsing_utils.c
 ***********************************************/
int		alloc_new_obj(t_list **head, void *new_sp, t_obj_type type);
int		take_dimension(double *dimension, char *str);
void	init_scene(t_scene *scene, t_lst_parse *lst_parse);
int		check_files_type(char *str);
int		check_valid_id(char *str, int single_entity[2]);

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
int		take_color(t_vec3 *colors, char *str);
/***********************************************
 *  @file parsing_vecteur.c
 ***********************************************/
int		take_pos(t_vec3 *pos, char *str);
int		take_dir(t_vec3 *pos, char *str);

/***********************************************
 *  @file parsing_light.c
 ***********************************************/
int		light_interpreter(t_list **lst_l, char **tab);

/***********************************************
 *  @file parsing_sphere.c
 ***********************************************/
int		sphere_interpreter(t_list **lst_obj, char **tab);

/***********************************************
 *  @file parsing_plane.c
 ***********************************************/
int		plan_interpreter(t_list **lst_obj, char **tab);

/***********************************************
 *  @file parsing_cylinder.c
 ***********************************************/
int		cylinder_interpreter(t_list **lst_obj, char **tab);

/***********************************************
 *  @file parsing_cone.c
 ***********************************************/
int		cone_interpreter(t_list **lst_obj, char **tab);

/***********************************************
 *  @file parsing_error.c
 ***********************************************/
void	exit_error_parsing(t_scene *scene);
void	print_error_message(char *str);

/***********************************************
 *  @file lst_parsing.c
 ***********************************************/
int		lst_parse_to_tab(t_scene *scene, t_lst_parse *lst_parse);

/***********************************************
 *  @file parsing_local__coor.c
 ***********************************************/
void	init_local_coordinates(t_vec3 *dir, t_vec3 *right, t_vec3 *up);
void	rotation_on_forward(t_vec3 *dir, t_vec3 *right, t_vec3 *up, int *sign);
void	rotation_on_up(t_vec3 *dir, t_vec3 *right, t_vec3 *up, int *sign);
void	rotation_on_right(t_vec3 *dir, t_vec3 *right, t_vec3 *up, int *sign);

#endif

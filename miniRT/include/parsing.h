/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:42:02 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:42:05 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

/** @file parsing.c */
int		parsing(int argc, char **argv, t_scene *scene);

/***********************************************
 *  @details DATA
 ***********************************************/
/** @file parsing_utils.c */
int		take_dimension(double *dimension, char *str);
void	init_scene(t_scene *scene, t_lst_parse *lst_parse);
int		check_files_type(char *str, char *type);
int		check_valid_id(char *str, int single_entity[2]);
void	init_local_coordinates(const t_vec3 *dir, t_vec3 *right, t_vec3 *up);

/** @file parsing_pattern.c */
int		take_color(t_vec3 *colors, char *str);

/** @file parsing_vector.c */
int		take_pos(t_vec3 *pos, char *str);
int		take_dir(t_vec3 *pos, char *str);

/** @file parsing_error.c */
void	exit_error_parsing(t_scene *scene);
void	print_error_message(char *str);

/** @file parsing_lst.c */
void	clear_lst_parse(t_lst_parse **lst_parse, void (*del)(void *));
int		lst_parse_to_tab(t_scene *scene, t_lst_parse *lst_parse);

/***********************************************
 *  @details ELEMENT
 ***********************************************/
/** @file parsing_camera.c */
int		camera_interpreter(t_scene *scene, char **tab);

/** @file parsing_light.c */
int		ambient_interpreter(t_scene *scene, char **tab);
int		light_interpreter(t_list **lst_l, char **tab);

/** @file parsing_sphere.c */
int		sphere_interpreter(t_list **lst_obj, char **tab);

/** @file parsing_plane.c */
int		plan_interpreter(t_list **lst_obj, char **tab);

/** @file parsing_cylinder.c */
int		cylinder_interpreter(t_list **lst_obj, char **tab);

/** @file parsing_cone.c */
int		cone_interpreter(t_list **lst_obj, char **tab);

/** @file parsing_obj.c */
int		alloc_new_obj(t_list **head, void *new_obj, char **tab,
			t_obj_type type);
void	clear_obj(void *obj);
int		take_pattern(t_pattern *pattern, char **tab);

#endif

/// @todo header

#ifndef GRAPHICAL_SYSTEM_H
# define GRAPHICAL_SYSTEM_H

# include "minirt.h"

/** @file event.c */
void	on_event(t_scene *scene);

/***********************************************
 *  @details DISPLAY RENDER
 ***********************************************/
/** @file clean_graphical_system.c */
void	clean_graph_sys(t_scene	*scene, t_graph_sys *g_sys);
void	clean_texture(t_obj **tab_obj, mlx_context mlx, size_t tab_size);
void	clean_mlx_sys(t_graph_sys *g_sys);

/** @file double_buffer.c */
void	swap_buffer(t_double_buffer *buff);
void	clean_double_buffer(t_graph_sys *g_sys);
int		init_double_buffer(t_graph_sys *g_sys);

/** @file image.c */
void	put_image_to_win(t_graph_sys *g_sys);
void	set_image_pixel(t_graph_sys *g_sys, int x, int y, t_color c);

/** @file window.c */
int		init_window(t_graph_sys *g_sys);

/** @file graphical_system.c */
int		manage_graphical_system(t_scene	*scene);

/** @file image_to_texture.c */
int		init_all_texture(t_obj **tab_obj, mlx_context mlx);

/***********************************************
 *  @details EDIT PROPERTY
 ***********************************************/
/** @file edit_camera.c */
void	mouse_event(t_scene *scene, t_graph_sys *g_sys);
void	key_hook_cam(int key, void *param);

/** @file edit_element.c */
void	data_change_translation(t_vec3 *pos, int coord, int sign);
void	key_hook_select_change(int key, void *param);
void	data_change(int key, void *param);

/** @file edit_obj.c */
void	edit_cone(int sign, t_menu *menu, t_cone_obj *cone);
void	edit_cylinder(int sign, t_menu *menu, t_cylinder_obj *cylinder);
void	edit_plane(int sign, t_menu *menu, t_plane_obj *plane);
void	edit_sphere(int sign, t_menu *menu, t_sphere_obj *sphere);

/** @file edit_utils.c */
void	rotation_on_forward(t_vec3 *dir, t_vec3 *right, t_vec3 *up, int sign);
void	rotation_on_up(t_vec3 *dir, t_vec3 *right, t_vec3 *up, int sign);
void	rotation_on_right(t_vec3 *dir, t_vec3 *right, t_vec3 *up, int sign);

/***********************************************
 *  @details MENU
 ***********************************************/
/** @file menu_manager.c */
void	menu_event(t_scene *scene);

/** @file menu_utils.c */
void	defile(size_t *position, int end, int move);
void	reset_menu(t_menu *menu);
int		init_menu(t_graph_sys *g_sys);

/** @file put_menu_obj.c */
void	menu_obj_display(t_scene *scene);

/** @file put_menu.c */
void	put_menu_title(t_graph_sys *g_sys, const int *tab_y,
			char **tab_txt, size_t nb_elem);
void	put_menu_selection(t_graph_sys *g_sys, const int *tab_y,
			char **tab_txt, size_t nb_elem);
void	menu_management(t_scene *scene);

#endif
/// @todo header

#ifndef MINIRT_COLORS_H
# define MINIRT_COLORS_H

# include "minirt.h"

# ifndef KA
#  define KA 0.5
# endif

# ifndef KD
#  define KD 1
# endif

# ifndef KS
#  define KS 0.5
# endif

# ifndef WHITE
#  define WHITE 0xFFFFFFFF
# endif

# ifndef BLACK
#  define BLACK 0x000000FF
# endif

# ifndef TEXT_COLOR
#  define TEXT_COLOR 0x00A1FFFF
# endif

# ifndef MENU_COLOR
#  define MENU_COLOR 0x00000099
# endif

/***********************************************
 *  @file lighting.c
 ***********************************************/
t_color	lighting(t_scene *scene, t_intersec *inter);

/***********************************************
 *  @file phong.c
 ***********************************************/
void	apply_ambient(const t_amb *amb, t_vec3 *phong_amb);
void	apply_diffuse(const t_light *light, t_vec3 *diffuse, double fact);
void	apply_specular(const t_light *light, t_vec3 *specular,
			const t_intersec *inter, double fact);
void	cos_angle_light(const t_light *l, const t_soluce *soluce,
			const t_vec3 *old_n, double fact[2]);

/***********************************************
 *  @file shadow.c
 ***********************************************/
int		shadow(t_obj **tab_obj, const t_light *light, const t_vec3 *p);

/***********************************************
 * @details PATTERNS
 ***********************************************/
/** @file checkerboard_pattern.c */
t_vec3	uv_manager(const t_intersec *inter, t_vec3 c_obj);

/** @file bump_map.c */
void	bump_map(t_graph_sys *g_sys, t_intersec *inter);

/**	@file texture.c */
t_vec3	color_from_img(const t_graph_sys *g_sys, const t_intersec *inter);

#endif
/// @todo header

#ifndef MINIRT_COLORS_H
# define MINIRT_COLORS_H

# include "minirt.h"

# ifndef KD
#  define KD 1
# endif

/***********************************************
 *  @file lighting.c
 ***********************************************/
t_color	lighting(const t_intersec *inter, t_obj **tab_obj, t_light **tab_l,
			const t_amb *amb);

/***********************************************
 *  @file phong.c
 ***********************************************/
t_vec3	apply_ambient(const t_amb *amb);
void	apply_diffuse(const t_light *light, t_vec3 *diffuse, double fact);
void	apply_specular(const t_light *light, t_vec3 *specular,
			const t_intersec *inter, double fact);
double	cos_angle_light(const t_light *light, const t_soluce *soluce);

/***********************************************
 *  @file shadow.c
 ***********************************************/
int		shadow(t_obj **tab_obj, const t_light *light, const t_vec3 *p);

/***********************************************
 * @details PATTERNS
 ***********************************************/
/** @file checkerboard_pattern.c */
t_vec3	uv_manager(const t_intersec *inter, t_vec3 c_obj);

/** @file uv.c */
t_vec2	uv_sp(t_vec3 p, void *arg);
t_vec2	uv_pl(t_vec3 p, void *arg);
t_vec2	uv_cy(t_vec3 p, void *arg);
t_vec2	uv_co(t_vec3 p, void *arg);

/** @file bump_map.c */
void	bump_map(t_graph_sys *g_sys, t_intersec *inter, t_pattern *img);

#endif
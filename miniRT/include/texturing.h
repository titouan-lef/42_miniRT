/// @todo header

#ifndef TEXTURING_H
# define TEXTURING_H

# include "minirt.h"

/** @file checkerboard.c */
t_vec3	uv_manager(const t_intersec *inter, t_vec3 c_obj);

/** @file bump_map.c */
void	bump_map(t_graph_sys *g_sys, t_intersec *inter);

/**	@file texture.c */
t_vec3	color_from_img(const t_graph_sys *g_sys, const t_intersec *inter);

/***********************************************
 * @details UV
 ***********************************************/
/** @file uv_sphere.c */
void	fill_uv_sp(t_intersec *inter);

/** @file uv_plane.c */
void	fill_uv_pl(t_intersec *inter);

/** @file uv_cylinder.c */
void	fill_uv_cy(t_intersec *inter);

/** @file uv_cone.c */
void	fill_uv_co(t_intersec *inter);

/***********************************************
 * @details NORMAL MAP
 ***********************************************/
/** @file normal_map_sphere.c */
void	fill_tangent_space_pl(const t_intersec *inter, t_normal_map *map);

/** @file normal_map_plane.c */
void	fill_tangent_space_sp(const t_intersec *inter, t_normal_map *map);

/** @file normal_map_cylinder.c */
void	fill_tangent_space_cy(const t_intersec *inter, t_normal_map *map);

/** @file normal_map_cone.c */
void	fill_tangent_space_co(const t_intersec *inter, t_normal_map *map);

#endif
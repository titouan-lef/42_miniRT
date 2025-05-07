/// @todo header

#ifndef LIGHTING_H
# define LIGHTING_H

# include "minirt.h"

/***********************************************
 *  @file light.c
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

#endif
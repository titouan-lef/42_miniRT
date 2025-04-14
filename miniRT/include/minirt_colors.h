/// @todo header

#ifndef MINIRT_COLORS_H
# define MINIRT_COLORS_H

# include "minirt.h"

t_color	ft_sum_colors(t_color c1, t_color c2);
t_color	ft_dif_colors(t_color c1, t_color c2);
t_color	ft_scal_color(t_color color, double k);
t_color	ft_mult_colors(t_color c1, t_color c2);

t_color	lighting(const t_intersec *inter, t_obj **tab_obj, t_light **tab_l,
			const t_amb *amb);

t_color	diffuse(const t_light *light, double kd, double fact);

t_color	specular(const t_light *light, const t_intersec *inter,
			const t_vec3 *n, double kd, double fact);

double	cos_angle_light(const t_light *light, const t_intersec *inter,
			const t_vec3 *n);

t_vec3	get_normal(const t_intersec *inter);

int		shadow(t_obj **tab_obj, const t_light *light, const t_vec3 *p);

#endif
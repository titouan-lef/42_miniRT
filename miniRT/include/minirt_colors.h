/// @todo header

#ifndef MINIRT_COLORS_H
# define MINIRT_COLORS_H

# include "minirt.h"

t_color	ft_sum_colors(t_color c1, t_color c2);
t_color	ft_dif_colors(t_color c1, t_color c2);
t_color	ft_scal_color(t_color color, double k);
t_color	ft_mult_colors(t_color c1, t_color c2);

t_color	lighting(t_intersec *inter, t_list *lst_obj, t_list *lst_light, t_amb *amb);

t_color	diffuse(t_light *light, double kd, double fact);

t_color	specular(t_light *light, t_intersec *inter, t_vec3 *n, double kd, double fact);

double	cos_angle_light(t_light *light, t_intersec *inter, t_vec3 *n);

t_vec3	get_normal(t_intersec *inter);

int		shadow(t_list *lst_obj, t_light *light, t_vec3 *p);

#endif
#ifndef MINIRT_COLORS_H
# define MINIRT_COLORS_H

# include "minirt.h"

t_color	ft_sum_colors(t_color c1, t_color c2);
t_color	ft_dif_colors(t_color c1, t_color c2);
t_color	ft_scal_color(t_color color, double k);
t_color	ft_mult_colors(t_color c1, t_color c2);

void lighting(t_intersec *intersec, t_list *lst_light, t_amb *amb);
/*
t_color diffuse(t_color obj_color, t_light *light, t_pixel *pixel, double kd);
t_vec3	ft_get_normal(t_vec3 c_sp, t_pixel *pixel);
*/

#endif
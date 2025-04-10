/// @todo header

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include "minirt_struct.h"
# include "minirt_parsing.h"
# include "minirt_err.h"
# include "graphical_system.h"
# include "minirt_colors.h"
# include "menu_text.h"

int		ray_lauch_test(t_scene *scene);

double	length_screen(double fov);
double	quadratic_equation(double a, double b, double c);

void	init_calculation(const t_vec3 *ray_s, t_list *lst_obj);

/***********************************************
 * @details INTERSECTION
 ***********************************************/
/** @file intersect_plane.c */
double	intersect_ray_pl(const t_obj *obj, const t_vec3 *ray_dir);
double	intersect_light_pl(const t_obj *obj, const t_ray *ray);

/** @file intersect_sphere.c */
double	intersect_ray_sp(const t_obj *obj, const t_vec3 *ray_dir);
double	intersect_light_sp(const t_obj *obj, const t_ray *ray);

/** @file intersect_cylinder.c */
double	intersect_ray_cy(const t_obj *obj, const t_ray *ray);
double	intersect_light_cy(const t_obj *obj, const t_ray *ray);

/** @file intersect_cone.c */
double	intersect_ray_co(const t_obj *obj, const t_ray *ray);
double	intersect_light_co(const t_obj *obj, const t_ray *ray);

/***********************************************
 * @details EQUATION
 ***********************************************/
/** @file equation_plane.c */
double	solve_eq_pl(double os_dot_odir, double raydir_dot_odir);
void	init_math_pl(const t_vec3 *ray_s, const t_plane *pl, double *mathpl);

/** @file equation_sphere.c */
double	solve_eq_sp(const t_math_sp *mathsp, const t_vec3 *ray_dir);
void	init_math_sp(const t_vec3 *ray_s, const t_sphere *sp,
			t_math_sp *mathsp);

/** @file equation_cylinder.c */
double	solve_eq_cy(const t_math_cy *mathcy, const t_ray *ray,
			double raydir_dot_odir);
void	init_math_cy(const t_vec3 *ray_s, const t_cylinder *cy,
			t_math_cy *mathcy);

/** @file equation_cone.c */
double	solve_eq_co(const t_math_co *mathco, const t_ray *ray, double raydir_dot_odir);
void	init_math_co(const t_vec3 *ray_s, const t_cone *co, t_math_co *mathco);

#endif
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
# include "minirt_err_bonus.h"
# include "graphical_system.h"
# include "minirt_colors.h"
# include "menu_text.h"
# include "minirt_bonus.h"

# ifndef EPSILON
#  define EPSILON 0.000001
# endif

/***********************************************
 * @file ray.c
 ***********************************************/
int		ray_lauch_test(t_scene *scene);

/***********************************************
 * @details CALCULATION
 ***********************************************/
/** @file calculation.c */
double	length_screen(double fov);
void	quadratic_equation(double result[2], double a, double b, double c);
double	min_quadratic_equation(double a, double b, double c);

/** @file init_calculation.c */
void	init_calculation(const t_vec3 *ray_s, t_obj **tab_obj);

/***********************************************
 * @details INTERSECTION
 ***********************************************/
/** @file intersect.c */
int		intersect_base(const t_vec3 *base_center, double r, double t,
			t_intersec *inter);
void	update_soluce_sp(const t_obj *obj, const t_ray *ray, t_soluce *soluce);
void	update_n_soluce_lite(const t_vec3 *n, double raydir_dot_odir,
			t_soluce *soluce);
void	update_n_soluce(const t_vec3 *n, const t_vec3 *ray_dir,
			t_soluce *soluce);
void	update_soluce_pl(const t_obj *obj, const t_ray *ray, t_soluce *soluce);

/** @file intersect_plane.c */
void	intersect_ray_pl(const t_obj *obj, t_intersec *inter);
double	intersect_light_pl(const t_obj *obj, const t_ray *ray);

/** @file intersect_sphere.c */
void	intersect_ray_sp(const t_obj *obj, t_intersec *inter);
double	intersect_light_sp(const t_obj *obj, const t_ray *ray);

/** @file intersect_cylinder.c */
void	intersect_ray_cy(const t_obj *obj, t_intersec *inter);
double	intersect_light_cy(const t_obj *obj, const t_ray *ray);

/** @file intersect_cone.c */
void	intersect_ray_co(const t_obj *obj, t_intersec *inter);
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
double	solve_eq_cy(const t_math_cy *mathcy, const t_ray *ray);
void	init_math_cy(const t_vec3 *ray_s, const t_cylinder *cy,
			t_math_cy *mathcy);

/** @file equation_cone.c */
void	solve_eq_co(const t_math_co *mathco, const t_ray *ray,
			double result[2]);
void	init_math_co(const t_vec3 *ray_s, const t_cone *co, t_math_co *mathco);

#endif
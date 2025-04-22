/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:02:30 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/22 19:10:59 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include "print.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

/***********************************************
 * @details VECTOR 3
 ***********************************************/
/** @file ft_vector3_primitive.c */
t_vec3	ft_create_vec3(double x, double y, double z);
t_vec3	ft_create_normalized_vec3(const t_vec3 *p1, const t_vec3 *p2);
int		ft_is_zero_vec3(const t_vec3 *v);
t_vec3	ft_normalize_vec3(const t_vec3 *v);
t_vec3	ft_translation_vec3(const t_vec3 *p, const t_vec3 *v, double dist);

/** @file ft_vector3_operation.c */
t_vec3	ft_sum_vec3(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	ft_diff_vec3(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	ft_scalmult_vec3(const t_vec3 *v, double k);
double	ft_dot_vec3(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	ft_cross_vec3(const t_vec3 *v1, const t_vec3 *v2);

/** @file ft_vector3_measure.c */
double	ft_norm_vec3(const t_vec3 *v);
double	ft_distance_vec3(const t_vec3 *p1, const t_vec3 *p2);

/***********************************************
 * @details VECTOR 2
 ***********************************************/
/** @file ft_vector2_primitive.c */
t_vec2	ft_create_vec2(double x, double y);
t_vec2	ft_create_normalized_vec2(const t_vec2 *p1, const t_vec2 *p2);
int		ft_is_zero_vec2(const t_vec2 *v);
t_vec2	ft_normalize_vec2(const t_vec2 *v);
t_vec2	ft_translation_vec2(const t_vec2 *p, const t_vec2 *v, double dist);

/** @file ft_vector2_operation.c */
t_vec2	ft_sum_vec2(const t_vec2 *v1, const t_vec2 *v2);
t_vec2	ft_diff_vec2(const t_vec2 *v1, const t_vec2 *v2);
t_vec2	ft_scalmult_vec2(const t_vec2 *v, double k);
double	ft_dot_vec2(const t_vec2 *v1, const t_vec2 *v2);

/** @file ft_vector2_measure.c */
double	ft_norm_vec2(const t_vec2 *v);
double	ft_distance_vec2(const t_vec2 *p1, const t_vec2 *p2);

#endif
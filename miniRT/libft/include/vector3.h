/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:30:51 by tle-floc          #+#    #+#             */
/*   Updated: 2024/12/11 15:42:51 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H
# include <math.h>
# include "print.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

/* primitive */
t_vec3	ft_create_vec3(double x, double y, double z);
int		ft_is_zero_vec3(const t_vec3 *v);
double	ft_norm_vec3(const t_vec3 *v);
double	ft_distance_vec3(const t_vec3 *p1, const t_vec3 *p2);
t_vec3	ft_normalize_vec3(const t_vec3 *v);

/* operation */
t_vec3	ft_sum_vec3(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	ft_diff_vec3(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	ft_scalmult_vec3(const t_vec3 *v, double k);
double	ft_dot_vec3(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	ft_cross_vec3(const t_vec3 *v1, const t_vec3 *v2);

#endif
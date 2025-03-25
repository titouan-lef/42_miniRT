/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:38:45 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/24 15:35:05 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H
# include "vector3.h"

typedef struct s_quaternion
{
	double		scalar;
	t_vector3	axis;
}	t_quaternion;

/***********************************************
 * @file ft_quaternion_primitive.c
 ***********************************************/
t_quaternion	ft_create_quaternion(double scalar, t_vector3 axis);
double			ft_norm_quaternion(t_quaternion q);
t_quaternion	ft_unit_quaternion(t_quaternion q);
t_quaternion	ft_conjugate_quaternion(t_quaternion q);
t_quaternion	ft_inverse_quaternion(t_quaternion q);

/***********************************************
 * @file ft_quaternion_operation.c
 ***********************************************/
t_quaternion	ft_sum_quaternion(t_quaternion q1, t_quaternion q2);
t_quaternion	ft_diff_quaternion(t_quaternion q1, t_quaternion q2);
t_quaternion	ft_scalarmult_quaternion(t_quaternion q, double k);
t_quaternion	ft_product_quaternion(t_quaternion q1, t_quaternion q2);

#endif

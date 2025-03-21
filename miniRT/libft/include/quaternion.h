/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:38:45 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/21 17:42:18 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef QUATERNION_H
# define QUATERNION_H
#include "vector3.h"

typedef struct s_quaternion
{
	double		scalar;
	t_vector3	axis;
} 	t_quaternion;

t_quaternion	ft_create_quaternion(double scalar, t_vector3 axis);
t_quaternion	ft_sum_quaternion(t_quaternion q1, t_quaternion q2);
t_quaternion	ft_diff_quaternion(t_quaternion q1, t_quaternion q2);
t_quaternion	ft_scalarmult_quaternion(t_quaternion q, double k);
t_quaternion	ft_product_quaternion(t_quaternion q1, t_quaternion q2);
double			ft_norm_quaternion(t_quaternion q);
t_quaternion	ft_conjugation_quaternion(t_quaternion q);
t_quaternion	ft_inverse_quaternion(t_quaternion q);
t_vector3		ft_rotation_quaternion(t_vector3 point, double angle, t_vector3 axis);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:38:45 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/22 17:03:11 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H
# include "vector.h"

typedef struct s_quat
{
	double	scalar;
	t_vec3	vec;
}	t_quat;

/***********************************************
 * @file ft_quaternion_primitive.c
 ***********************************************/
t_quat	ft_create_quat(double scalar, const t_vec3 *vec);
double	ft_norm_quat(const t_quat *q);
t_quat	ft_unit_quat(const t_quat *q);
t_quat	ft_conjugate_quat(const t_quat *q);
t_quat	ft_inverse_quat(const t_quat *q);

/***********************************************
 * @file ft_quaternion_operation.c
 ***********************************************/
t_quat	ft_sum_quat(const t_quat *q1, const t_quat *q2);
t_quat	ft_diff_quat(const t_quat *q1, const t_quat *q2);
t_quat	ft_scalarmult_quat(const t_quat *q, double k);
t_quat	ft_product_quat(const t_quat *q1, const t_quat *q2);

#endif

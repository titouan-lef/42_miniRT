/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:43:13 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/04 11:54:43 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H
# include "quaternion.h"

typedef struct s_rotation
{
	double	roll;
	double	pitch;
	double	yaw;
}	t_rotation;

typedef struct s_plane
{
	t_vec3	n;
	double	d;
}	t_plane;

/***********************************************
 * @file ft_rotation.c
 ***********************************************/
t_vec3		ft_yaw_rotation(const t_vec3 *p, double angle);
t_vec3		ft_pitch_rotation(const t_vec3 *p, double angle);
t_vec3		ft_roll_rotation(const t_vec3 *p, double angle);
t_vec3		ft_rotation(const t_vec3 *p, const t_rotation *rotation);
t_rotation	ft_rotation_create(double roll, double pitch, double yaw);

/***********************************************
 * @file ft_rotation_quaternion.c
 ***********************************************/
t_vec3		ft_rotation_quat(const t_vec3 *v, double angle, const t_vec3 *vec);

/***********************************************
 * @file ft_projection.c
 ***********************************************/
t_plane		ft_create_plane(const t_vec3 *n, const t_vec3 *p);
t_vec3		ft_projection(const t_vec3 *v, const t_plane *pl);

#endif
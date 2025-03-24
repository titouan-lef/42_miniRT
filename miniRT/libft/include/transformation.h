/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:43:13 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/24 15:34:47 by tle-floc         ###   ########.fr       */
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
	double	a;
	double	b;
	double	c;
	double	d;
}	t_plane;

/* rotation */
t_vector3	ft_yaw_rotation(t_vector3 p, double angle);
t_vector3	ft_pitch_rotation(t_vector3 p, double angle);
t_vector3	ft_roll_rotation(t_vector3 p, double angle);
t_vector3	ft_rotation(t_vector3 p, t_rotation rotation);
t_rotation	ft_rotation_create(double roll, double pitch, double yaw);
t_vector3	ft_rotation_quaternion(t_vector3 v, double angle, t_vector3 axis);

/* projection */
t_vector3	ft_projection(t_vector3 v, t_plane p);

#endif
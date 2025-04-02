/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:43:13 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/02 19:12:30 by pchalmin         ###   ########.fr       */
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
	t_vector3	n;
	double		d;
}	t_plane;

/* rotation */
t_vector3	ft_yaw_rotation(t_vector3 p, double angle);
t_vector3	ft_pitch_rotation(t_vector3 p, double angle);
t_vector3	ft_roll_rotation(t_vector3 p, double angle);
t_vector3	ft_rotation(t_vector3 p, t_rotation rotation);
t_rotation	ft_rotation_create(double roll, double pitch, double yaw);
t_vector3	ft_rotation_quaternion(t_vector3 v, double angle, t_vector3 axis);

/* projection */
t_plane		ft_create_plane(t_vector3 n, t_vector3 p);
t_vector3	ft_projection(t_vector3 v, t_plane pl);

#endif
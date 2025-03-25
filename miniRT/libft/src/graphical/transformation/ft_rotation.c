/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:06:18 by tle-floc          #+#    #+#             */
/*   Updated: 2024/12/21 16:38:57 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

t_vector3	ft_roll_rotation(t_vector3 p, double angle)
{
	t_vector3	new;

	new.x = p.x;
	new.y = p.y * cos(angle) + p.z * sin(angle);
	new.z = -p.y * sin(angle) + p.z * cos(angle);
	return (new);
}

t_vector3	ft_yaw_rotation(t_vector3 p, double angle)
{
	t_vector3	new;

	new.x = p.x * cos(angle) + p.y * sin(angle);
	new.y = -p.x * sin(angle) + p.y * cos(angle);
	new.z = p.z;
	return (new);
}

t_vector3	ft_pitch_rotation(t_vector3 p, double angle)
{
	t_vector3	new;

	new.x = p.x * cos(angle) - p.z * sin(angle);
	new.y = p.y;
	new.z = p.x * sin(angle) + p.z * cos(angle);
	return (new);
}

t_vector3	ft_rotation(t_vector3 p, t_rotation rotation)
{
	if (fmod(rotation.roll, 2 * M_PI) != 0)
		p = ft_roll_rotation(p, rotation.roll);
	if (fmod(rotation.pitch, 2 * M_PI) != 0)
		p = ft_pitch_rotation(p, rotation.pitch);
	if (fmod(rotation.yaw, 2 * M_PI) != 0)
		p = ft_yaw_rotation(p, rotation.yaw);
	return (p);
}

t_rotation	ft_rotation_create(double roll, double pitch, double yaw)
{
	t_rotation	rotation;

	rotation.roll = roll;
	rotation.pitch = pitch;
	rotation.yaw = yaw;
	return (rotation);
}

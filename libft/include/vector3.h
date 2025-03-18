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

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

/* primitive */
t_vector3	ft_create_vector3(double x, double y, double z);
double		ft_magnitude_vector3(t_vector3 v1);
double		ft_distance_vector3(t_vector3 v1, t_vector3 v2);

/* operation */
t_vector3	ft_sum_vector3(t_vector3 v1, t_vector3 v2);
t_vector3	ft_diff_vector3(t_vector3 v1, t_vector3 v2);
t_vector3	ft_scalarmult_vector3(t_vector3 v1, double k);
double		ft_dotproduct_vector3(t_vector3 v1, t_vector3 v2);
t_vector3	ft_crossproduct_vector3(t_vector3 v1, t_vector3 v2);

#endif
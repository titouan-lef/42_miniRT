/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:47 by tle-floc          #+#    #+#             */
/*   Updated: 2024/12/11 16:20:25 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	ft_sum_vector3(t_vector3 v1, t_vector3 v2)
{
	t_vector3	sum;

	sum.x = v1.x + v2.x;
	sum.y = v1.y + v2.y;
	sum.z = v1.z + v2.z;
	return (sum);
}

t_vector3	ft_diff_vector3(t_vector3 v1, t_vector3 v2)
{
	t_vector3	diff;

	diff.x = v1.x - v2.x;
	diff.y = v1.y - v2.y;
	diff.z = v1.z - v2.z;
	return (diff);
}

t_vector3	ft_scalarmult_vector3(t_vector3 v1, double k)
{
	t_vector3	scalarmult;

	scalarmult.x = v1.x * k;
	scalarmult.y = v1.y * k;
	scalarmult.z = v1.z * k;
	return (scalarmult);
}

double	ft_dotproduct_vector3(t_vector3 v1, t_vector3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector3	ft_crossproduct_vector3(t_vector3 v1, t_vector3 v2)
{
	t_vector3	crossproduct;

	crossproduct.x = v1.y * v2.z - v1.z * v2.y;
	crossproduct.y = v1.z * v2.x - v1.x * v2.z;
	crossproduct.z = v1.x * v2.y - v1.y * v2.x;
	return (crossproduct);
}

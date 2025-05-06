/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_compare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:13:27 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/06 12:17:08 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
 * @brief Check if vector is a zero vector, that is a vector(0, 0, 0).
 */
int	ft_is_zero_vec3(const t_vec3 *v)
{
	return (v->x == 0 && v->y == 0 && v->z == 0);
}

/**
 * @brief Check if two vectors are equaled.
 */
int	ft_is_equal_vec3(const t_vec3 *v1, const t_vec3 *v2)
{
	return (v1->x == v2->x && v1->y == v2->y && v1->z == v2->z);
}

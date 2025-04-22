/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:09:41 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/22 17:07:20 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	ft_sum_vec2(const t_vec2 *v1, const t_vec2 *v2)
{
	t_vec2	sum;

	sum.x = v1->x + v2->x;
	sum.y = v1->y + v2->y;
	return (sum);
}

t_vec2	ft_diff_vec2(const t_vec2 *v1, const t_vec2 *v2)
{
	t_vec2	diff;

	diff.x = v1->x - v2->x;
	diff.y = v1->y - v2->y;
	return (diff);
}

t_vec2	ft_scalmult_vec2(const t_vec2 *v, double k)
{
	t_vec2	scalarmult;

	scalarmult.x = v->x * k;
	scalarmult.y = v->y * k;
	return (scalarmult);
}

/**
 * @brief Get the dot product of 2 vectors v1 and v2, that is the result of
 * ||v1|| * ||v2|| * cos(v1, v2).
 */
double	ft_dot_vec2(const t_vec2 *v1, const t_vec2 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y);
}

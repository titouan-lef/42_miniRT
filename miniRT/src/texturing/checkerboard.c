/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:49:03 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:49:05 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_exp(int n)
{
	int	result;

	result = 1;
	while (n > 0)
	{
		result *= 2;
		--n;
	}
	return (result);
}

/**
 * @brief Calculate the spliting of the checkerboard.
*/
static t_vec3	get_uv_color(t_vec3 c[2], const t_vec2 *uv, int div)
{
	int			sq;
	t_vec2		uv_scaled;

	sq = ft_exp(div);
	uv_scaled = ft_scalmult_vec2(uv, sq);
	if (uv_scaled.x >= sq)
		uv_scaled.x = sq - 1;
	if (uv_scaled.y >= sq)
		uv_scaled.y = sq - 1;
	if ((int)uv_scaled.x % 2 == (int)uv_scaled.y % 2)
		return (c[0]);
	return (c[1]);
}

/**
 * @brief Reverses the color of origin.
*/
static t_vec3	inv_color(t_vec3 c)
{
	t_vec3	inv_c;

	inv_c = ft_create_vec3(1 - c.x, 1 - c.y, 1 - c.z);
	return (inv_c);
}

/**
 * @brief Manages checker board trimming according to the number of trimmings
 * entered in parameters.
 * @return The colors object.
*/
t_vec3	uv_manager(const t_intersec *inter, t_vec3 c_obj)
{
	t_vec3	c;
	t_vec3	tab_c[2];

	tab_c[0] = c_obj;
	tab_c[1] = inv_color(c_obj);
	c = get_uv_color(tab_c, &inter->uv_cb, inter->obj->pattern.checkerboard);
	return (c);
}

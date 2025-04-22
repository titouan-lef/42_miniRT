/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:44:34 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/22 18:00:25 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Get the rgb value.
 * @return A value with 0xRRGGBB format.
 * @warning The Alpha composant isn't taken into account.
 */
uint32_t	ft_get_rgb(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

/**
 * @brief Get the rgba value.
 * @return A value with 0xRRGGBBAA format.
 * @warning The Alpha composant is taken into account.
 */
uint32_t	ft_get_rgba(t_color c)
{
	uint32_t	rgb;

	rgb = ft_get_rgb(c);
	rgb = rgb << 8;
	return (rgb | c.a);
}

/**
 * @brief Convert a color to a vector3.
 * @return vect3 with values in [0, 1]
 */
t_vec3	ft_color_to_vec3(const t_color *c)
{
	t_vec3	v;

	v = ft_create_vec3(c->r, c->g, c->b);
	v = ft_scalmult_vec3(&v, 1.0 / 255.0);
	return (v);
}

/**
 * @brief Convert a vector3 to a color.
 * @param v rgb value.
 * @param a alpha value.
 * @return color with values in [0, 255]
 * @warning Values in vector must be in [0, 1].
 */
t_color	ft_vec3_to_color(const t_vec3 *v, uint8_t a)
{
	t_color	c;

	c = ft_color_create(v->x * 255, v->y * 255, v->z * 255, a);
	return (c);
}

/**
 * @brief Create a color.
 * @param r Red.
 * @param g Green.
 * @param b Blue.
 * @param a Alpha.
 * @return A t_color structure.
 */
t_color	ft_color_create(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return (c);
}

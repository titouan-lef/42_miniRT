/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:48:16 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:48:18 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	a_calculation(const t_vec3 *ray_dir)
{
	double	result;

	result = ft_dot_vec3(ray_dir, ray_dir);
	return (result);
}

static double	b_calculation(const t_vec3 *os, const t_vec3 *ray_dir)
{
	double	result;

	result = ft_dot_vec3(os, ray_dir);
	result *= 2.0;
	return (result);
}

static double	c_calculation(const t_vec3 *os, double r)
{
	double	dot;

	dot = ft_dot_vec3(os, os);
	return (dot - r * r);
}

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details "greater than 1" is corresponding to the minimum distance at which
 * the object must be in order to be seen.
 * sphere equation : (x - s.x)^2 + (y - s.y)^2 + (z - s.z)^2 = r^2
 * x : p.x + ray_dir.x * t
 * y : p.y + ray_dir.y * t
 * z : p.z + ray_dir.z * t
 * After development equation become : a * t^2 + b * t + c = 0
 * @param mathsp The pre-calculated mathematics.
 * @param ray_dir Ray direction.
 * @return The smallest t factor define on [1, INFINITY[. If INFINITY is
 * returned, no intersections found.
 */
double	solve_eq_sp(const t_math_sp *mathsp, const t_vec3 *ray_dir)
{
	double	a;
	double	b;
	double	result;

	a = a_calculation(ray_dir);
	b = b_calculation(&mathsp->os, ray_dir);
	result = min_quadratic_equation(a, b, mathsp->c_factor);
	return (result);
}

/**
 * @brief Initialize the pre-calculated mathematics.
 * @param ray_s The start of the ray.
 * @param sp The sphere.
 * @param mathsp The pre-calculated mathematics.
 */
void	init_math_sp(const t_vec3 *ray_s, const t_sphere *sp, t_math_sp *mathsp)
{
	t_vec3	os;

	os = ft_diff_vec3(ray_s, &sp->pos);
	mathsp->os = os;
	mathsp->c_factor = c_calculation(&os, sp->r);
}

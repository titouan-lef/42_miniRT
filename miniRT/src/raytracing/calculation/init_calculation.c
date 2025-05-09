/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:47:53 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:47:55 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_calculation_sp(const t_vec3 *ray_s, const t_obj *obj)
{
	t_sphere_obj	*sp_obj;

	sp_obj = (t_sphere_obj *)(obj->data);
	init_math_sp(ray_s, &sp_obj->sp, &sp_obj->mathsp);
}

static void	init_calculation_pl(const t_vec3 *ray_s, const t_obj *obj)
{
	t_plane_obj	*pl_obj;

	pl_obj = (t_plane_obj *)(obj->data);
	init_math_pl(ray_s, &pl_obj->pl, &pl_obj->math_os_dot_odir);
}

static void	init_calculation_cy(const t_vec3 *ray_s, const t_obj *obj)
{
	t_cylinder_obj	*cy_obj;

	cy_obj = (t_cylinder_obj *)(obj->data);
	init_math_cy(ray_s, &cy_obj->cy, &cy_obj->mathcy);
}

static void	init_calculation_co(const t_vec3 *ray_s, const t_obj *obj)
{
	t_cone_obj	*co_obj;

	co_obj = (t_cone_obj *)(obj->data);
	init_math_co(ray_s, &co_obj->co, &co_obj->mathco);
}

/**
 * @brief Initialize the pre-calculated mathematics structure of all objects.
 * @param ray_s The start of the ray.
 * @param tab_obj The array of objects.
 */
void	init_calculation(const t_vec3 *ray_s, t_obj **tab_obj)
{
	size_t	i;

	i = 0;
	while (tab_obj[i] != NULL)
	{
		if (tab_obj[i]->type == SPHERE)
			init_calculation_sp(ray_s, tab_obj[i]);
		else if (tab_obj[i]->type == CYLINDER)
			init_calculation_cy(ray_s, tab_obj[i]);
		else if (tab_obj[i]->type == PLANE)
			init_calculation_pl(ray_s, tab_obj[i]);
		else if (tab_obj[i]->type == CONE)
			init_calculation_co(ray_s, tab_obj[i]);
		++i;
	}
}

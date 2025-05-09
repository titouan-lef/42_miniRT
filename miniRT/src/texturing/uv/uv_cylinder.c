/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:49:42 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:49:43 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Fill uv for checkerboard if intersection is on caps.
 */
static void	fill_uv_cb_caps(const t_vec3 *op, const t_cylinder *cy,	t_vec2 *uv)
{
	double	right_ratio;
	double	up_ratio;

	uv->x = 1;
	right_ratio = ft_dot_vec3(op, &cy->right);
	up_ratio = ft_dot_vec3(op, &cy->up);
	uv->y = 0.5 + 0.5 * atan2(right_ratio, up_ratio) / M_PI;
}

/**
 * @brief Fill uv for bump map if intersection is on caps part.
 */
static void	fill_uv_bm_caps(const t_vec3 *op, const t_cylinder *cy,	t_vec2 *uv,
	double dot)
{
	double	right_ratio;
	double	up_ratio;
	double	radius_ratio;

	right_ratio = ft_dot_vec3(op, &cy->right);
	radius_ratio = 0.5 * right_ratio / cy->r;
	if (dot > 0)
		uv->x = 0.5 - radius_ratio;
	else
		uv->x = 0.5 + radius_ratio;
	up_ratio = ft_dot_vec3(op, &cy->up);
	uv->y = 0.5 + 0.5 * up_ratio / cy->r;
}

/**
 * @brief Fill uv if intersection is on lateral part.
 */
static void	fill_uv_lateral(const t_vec3 *op, const t_cylinder *cy,	t_vec2 *uv)
{
	double	first_ratio;
	double	up_ratio;

	first_ratio = ft_dot_vec3(op, &cy->dir);
	uv->x = 0.5 - 0.5 * first_ratio / cy->hh;
	first_ratio = ft_dot_vec3(op, &cy->right);
	up_ratio = ft_dot_vec3(op, &cy->up);
	uv->y = 0.5 + 0.5 * atan2(first_ratio, up_ratio) / M_PI;
}

/**
 * @brief Manage what uv must be filled.
 */
static void	manage_fill(const t_cylinder *cy, t_intersec *inter, int is_cb,
	int is_bm)
{
	double	dot;
	t_vec3	op;

	dot = ft_dot_vec3(&inter->soluce.n, &cy->dir);
	op = ft_diff_vec3(&inter->soluce.p, &cy->pos);
	if (-0.9 < dot && dot < 0.9)
	{
		if (is_cb)
		{
			fill_uv_lateral(&op, cy, &inter->uv_cb);
			if (is_bm)
				inter->uv_bm = inter->uv_cb;
		}
		else
			fill_uv_lateral(&op, cy, &inter->uv_bm);
	}
	else
	{
		if (is_cb)
			fill_uv_cb_caps(&op, cy, &inter->uv_cb);
		if (is_bm)
			fill_uv_bm_caps(&op, cy, &inter->uv_bm, dot);
	}
}

/**
 * @brief Fill uv for checkerboard and bump map.
 */
void	fill_uv_cy(t_intersec *inter)
{
	t_cylinder_obj	*cy_obj;
	int				is_cb;
	int				is_bm;

	is_cb = inter->obj->pattern.checkerboard;
	is_bm = inter->obj->pattern.bump.name || inter->obj->pattern.texture.name;
	if (is_cb || is_bm)
	{
		cy_obj = (t_cylinder_obj *)inter->obj->data;
		manage_fill(&cy_obj->cy, inter, is_cb, is_bm);
	}
}

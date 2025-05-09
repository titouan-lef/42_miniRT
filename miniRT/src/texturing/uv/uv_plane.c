/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:49:46 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:49:48 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	fill_uv(const t_vec3 *p, void *arg, t_vec2 *uv)
{
	t_plane_obj	*pl_obj;
	t_vec3		p_resized;
	double		right_ratio;
	double		up_ratio;

	pl_obj = (t_plane_obj *)arg;
	p_resized = ft_scalmult_vec3(p, 0.01);
	right_ratio = ft_dot_vec3(&p_resized, &pl_obj->right);
	uv->x = fmod(right_ratio, 1.0);
	if (uv->x < 0)
		uv->x = 1 + uv->x;
	up_ratio = ft_dot_vec3(&p_resized, &pl_obj->up);
	uv->y = fmod(up_ratio, 1.0);
	if (uv->y < 0)
		uv->y = 1 + uv->y;
}

/**
 * @brief Fill uv for checkerboard and bump map.
 */
void	fill_uv_pl(t_intersec *inter)
{
	int	is_cb;
	int	is_bm;

	is_cb = inter->obj->pattern.checkerboard;
	is_bm = inter->obj->pattern.bump.name || inter->obj->pattern.texture.name;
	if (is_cb)
	{
		fill_uv(&inter->soluce.p, inter->obj->data, &inter->uv_cb);
		if (is_bm)
			inter->uv_bm = inter->uv_cb;
	}
	else if (is_bm)
		fill_uv(&inter->soluce.p, inter->obj->data, &inter->uv_bm);
}

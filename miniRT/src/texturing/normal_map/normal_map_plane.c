/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_map_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:49:26 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:49:28 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	fill_bitangent(const t_plane_obj *pl_obj, t_vec3 *bitangent)
{
	*bitangent = pl_obj->right;
}

static void	fill_tangent(const t_plane_obj *pl_obj, t_vec3 *tangent)
{
	*tangent = pl_obj->up;
}

void	fill_tangent_space_pl(const t_intersec *inter, t_normal_map *map)
{
	t_plane_obj	*pl_obj;

	pl_obj = (t_plane_obj *)inter->obj->data;
	fill_bitangent(pl_obj, &map->base.e2);
	fill_tangent(pl_obj, &map->base.e1);
}

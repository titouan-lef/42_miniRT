/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_graphical_system.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:42:57 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:42:59 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/**
 * @brief Destroys the environment of the entire
 * macrolibx display system (wimdow, double buffer and context)
 */
void	clean_mlx_sys(t_graph_sys *g_sys)
{
	mlx_destroy_window(g_sys->mlx, g_sys->win);
	clean_double_buffer(g_sys);
	mlx_destroy_context(g_sys->mlx);
}

/**
 * @brief Destroys all program displays (image, textture, environement)
 */
void	clean_graph_sys(t_scene	*scene, t_graph_sys *g_sys)
{
	size_t	tab_size;

	mlx_destroy_image(g_sys->mlx, g_sys->menu.background);
	tab_size = ft_matrix_get_row((void **)scene->tab_obj);
	clean_texture(scene->tab_obj, g_sys->mlx, tab_size);
	clean_mlx_sys(g_sys);
}

/**
 * @brief Destroys all texture (texture and bump)
 */
void	clean_texture(t_obj **tab_obj, mlx_context mlx, size_t tab_size)
{
	size_t		i;
	t_pattern	*pat;

	i = 0;
	while (i < tab_size)
	{
		pat = &tab_obj[i]->pattern;
		if (pat->bump.name != NULL)
			mlx_destroy_image(mlx, pat->bump.img);
		if (pat->texture.name != NULL)
			mlx_destroy_image(mlx, pat->texture.img);
		i++;
	}
}

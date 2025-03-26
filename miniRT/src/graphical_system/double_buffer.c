/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:36:11 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/26 19:54:52 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	swap_buffer(t_double_buffer *buff)
{
	mlx_image	*ptr_img;

	ptr_img = buff->back;
	buff->back = buff->front;
	buff->front = ptr_img;
}

void	clean_double_buffer(t_graph_sys *graph_sys)
{
	mlx_destroy_image(graph_sys->mlx, *graph_sys->buff.back);
	mlx_destroy_image(graph_sys->mlx, *graph_sys->buff.front);
}

int	init_double_buffer(t_graph_sys *graph_sys)
{
	mlx_image	*buffers;

	buffers = graph_sys->buff.buffers;
	graph_sys->buff.back = buffers;
	graph_sys->buff.front = buffers + 1;
	buffers[0] = mlx_new_image(graph_sys->mlx, WIN_W, WIN_H);
	if (buffers[0] == MLX_NULL_HANDLE)
	{
		ft_putendl_error(ERR_BACK_BUFFER_INIT);
		return (1);
	}
	buffers[1] = mlx_new_image(graph_sys->mlx, WIN_W, WIN_H);
	if (buffers[1] == MLX_NULL_HANDLE)
	{
		mlx_destroy_image(graph_sys->mlx, buffers[0]);
		ft_putendl_error(ERR_FRONT_BUFFER_INIT);
		return (1);
	}
	return (0);
}

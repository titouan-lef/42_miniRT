/// @todo header

#include "minirt.h"

void	swap_buffer(t_double_buffer *buff)
{
	mlx_image	*ptr_img;

	ptr_img = buff->back;
	buff->back = buff->front;
	buff->front = ptr_img;
}

/**
 * @brief Destroys both double buffer images
 */
void	clean_double_buffer(t_graph_sys *g_sys)
{
	mlx_destroy_image(g_sys->mlx, *g_sys->buff.back);
	mlx_destroy_image(g_sys->mlx, *g_sys->buff.front);
}

/**
 * @brief Initialize the 2 images of the double buffer
 * by creating them in an array.
 * @return 1 if image creation fails.
 */
int	init_double_buffer(t_graph_sys *g_sys)
{
	mlx_image	*buffers;

	buffers = g_sys->buff.buffers;
	g_sys->buff.back = buffers;
	g_sys->buff.front = buffers + 1;
	buffers[0] = mlx_new_image(g_sys->mlx, WIN_W, WIN_H);
	if (buffers[0] == MLX_NULL_HANDLE)
	{
		ft_putendl_error(ERR_BACK_BUFFER_INIT);
		return (1);
	}
	buffers[1] = mlx_new_image(g_sys->mlx, WIN_W, WIN_H);
	if (buffers[1] == MLX_NULL_HANDLE)
	{
		mlx_destroy_image(g_sys->mlx, buffers[0]);
		ft_putendl_error(ERR_FRONT_BUFFER_INIT);
		return (1);
	}
	return (0);
}

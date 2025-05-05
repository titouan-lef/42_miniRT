/// @todo header

#include "minirt.h"

void    clean_mlx_sys(t_graph_sys *g_sys)
{
    mlx_destroy_window(g_sys->mlx, g_sys->win);
	clean_double_buffer(g_sys);
	mlx_destroy_context(g_sys->mlx);
}

void	clean_graph_sys(t_scene	*scene, t_graph_sys *g_sys)
{
	mlx_destroy_image(g_sys->mlx, g_sys->menu.background);
	clean_texture(scene->tab_obj, g_sys->mlx);
	clean_mlx_sys(g_sys);
}

void	clean_texture(t_obj **tab_obj, mlx_context mlx)
{
	size_t		tab_size;
	size_t		i;
	t_pattern	*pat;

	tab_size = ft_matrix_get_row((void **)tab_obj);
	i = 0;
	while (i < tab_size)
	{
		pat = &tab_obj[i]->pattern;
		if (pat->bump.name != NULL)
        {
            if (pat->bump.img == NULL)
                break;
			mlx_destroy_image(mlx, pat->bump.img);
        }
		if (pat->texture.name != NULL)
        {
            if (pat->texture.img == NULL)
                break;
			mlx_destroy_image(mlx, pat->texture.img);
        }
		i++;
	}
}

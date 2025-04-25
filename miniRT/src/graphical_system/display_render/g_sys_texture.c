/// @todo header

#include "minirt.h"

void	init_texture(t_obj **tab_obj, mlx_context mlx)
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
			pat->bump.img = mlx_new_image_from_file(mlx, pat->bump.name,
					&pat->bump.width, &pat->bump.heigth);
		if (pat->texture.name != NULL)
			pat->texture.img = mlx_new_image_from_file(mlx, pat->texture.name,
					&pat->texture.width, &pat->texture.heigth);
		i++;
	}
}

void	destroy_texture(t_obj **tab_obj, mlx_context mlx)
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
			mlx_destroy_image(mlx, pat->bump.img);
		if (pat->texture.name != NULL)
			mlx_destroy_image(mlx, pat->texture.img);
		i++;
	}
}

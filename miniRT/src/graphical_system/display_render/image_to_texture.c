/// @todo header

#include "minirt.h"

/**
 * @brief Init texture or/and bump if a file path is present.
 * @param pat Is a pattern of the obj.
 * @return 1 if mlx_new_image_from_file failed.
 */
static int	init_texture(t_pattern *pat, mlx_context *mlx)
{
	if (pat->bump.name != NULL)
	{
		pat->bump.img = mlx_new_image_from_file(*mlx, pat->bump.name,
				&pat->bump.width, &pat->bump.heigth);
		if (pat->bump.img == NULL)
			return (1);
	}
	if (pat->texture.name != NULL)
	{
		pat->texture.img = mlx_new_image_from_file(*mlx, pat->texture.name,
				&pat->texture.width, &pat->texture.heigth);
		if (pat->texture.img == NULL)
		{
			if (pat->bump.name != NULL)
				mlx_destroy_image(*mlx, pat->bump.img);
			return (1);
		}
	}
	return (0);
}

/**
 * @brief Scans entire object array and initializes texture and bump.
 * if passed in param.
 * @return 1 if init_texture failed.
 */
int	init_all_texture(t_obj **tab_obj, mlx_context mlx)
{
	size_t		tab_size;
	size_t		i;
	t_pattern	*pat;

	tab_size = ft_matrix_get_row((void **)tab_obj);
	i = 0;
	while (i < tab_size)
	{
		pat = &tab_obj[i]->pattern;
		if (init_texture(pat, &mlx))
		{
			clean_texture(tab_obj, mlx, i);
			return (1);
		}
		i++;
	}
	return (0);
}

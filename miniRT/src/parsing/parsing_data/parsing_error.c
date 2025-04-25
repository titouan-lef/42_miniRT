#include "minirt.h"

static void	free_content_obj(t_obj **tab_obj)
{
	size_t	i;

	i = 0;
	while (tab_obj[i] != NULL)
	{
		clear_obj(tab_obj[i]);
		tab_obj[i] = NULL;
		++i;
	}
	free(tab_obj);
	tab_obj = NULL;
}

void	exit_error_parsing(t_scene *scene)
{
	if (scene->tab_obj)
	{
		free_content_obj(scene->tab_obj);
		scene->tab_obj = NULL;
	}
	if (scene->tab_l)
		ft_clean_matrix((void ***)&scene->tab_l);
}

/**
 * @brief Print error message on std 2
 */
void	print_error_message(char *str)
{
	write(2, "Error\n", 6);
	ft_printf_fd(2, "%s\n", str);
}

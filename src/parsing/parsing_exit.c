#include "minirt.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
}

void	free_content(void *content)
{
	free(content);
	content = NULL;
}

void	exit_error_before_alloc(char *str)
{
	ft_printf_fd(2, "Error/n%s/n", str);
	exit (1);
}

void	exit_error_parsing(char *str, t_scene *scene)
{
	if (scene->lst_light)
		ft_lstclear(&scene->lst_light, free_content);
	if (scene->lst_obj)
		ft_lstclear(&scene->lst_obj, free_content);
	ft_printf_fd(2, "Error/n%s/n", str);
	exit (1);
}

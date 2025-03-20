#include "minirt.h"

void	free_content_light(void *content)
{
	free(content);
	content = NULL;
}

void	free_content_obj(void *content)
{
	free(((t_obj *)content)->data);
	free(content);
	content = NULL;
}

void	exit_error_before_alloc(char *str)
{
	ft_printf_fd(2, "Error/n%s/n", str);
	exit (1);
}

void	exit_error_parsing(t_scene *scene)
{
	if (scene->lst_light)
		ft_lstclear(&scene->lst_light, free_content_light);
	if (scene->lst_obj)
		ft_lstclear(&scene->lst_obj, free_content_obj);
}

void	print_error_message(char *str)
{
	write(2, "Error\n", 6);
	ft_printf_fd(2, "%s\n", str);
}

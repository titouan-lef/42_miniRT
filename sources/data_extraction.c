#include "minirt.h"
void	ft_free_content(void *content)
{
	free(content);
	content = NULL;
}

int	read_file(char *file, t_list *file_content)
{
	int		fd;
	char	*str;
	t_list	*new_line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit("open at test.c l 44 failed");
	str = get_next_line(fd);
	while (str)
	{
		new_line = ft_lstnew(str);
		if (!new_line)
		{
			free (str);
			close (fd);
			return (1);
		}
		ft_lstadd_back(&file_content, new_line);
		str = get_next_line(fd);
	}
	close (fd);
	ft_remove_if(&file_content, "/n");
	return (0);
}

int extraction_data(char *file, t_scene *scene)
{
	t_list	*files_content;

	if (read_file(file, files_content))
		ft_lstclear(&files_content, ft_free_content);
	
}

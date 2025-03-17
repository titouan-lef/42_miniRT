/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:09:24 by pchalmin          #+#    #+#             */
/*   Updated: 2025/03/17 19:11:43 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_files_type(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size < 4)
		return (1);
	if (str[size - 1] != 't')
		return (1);
	if (str[size - 2] != 'r')
		return (1);
	if (str[size - 3] != '.')
		return (1);
	return (0);
}

void	ft_exit(char *str)
{
	printf("Error/n%s/n", str);
	exit (1);
}

int	main(int argc, char ** argv)
{
	int	fd;
	char *str;

	fd = 0;
	if (argc > 2 || argc < 2 || check_files_type(argv[1]))
		ft_exit("try miniRT with scene files : ./miniRT \"file_names\".rt");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit("open at test.c l 44 failed");
	str = get_next_line(fd);
	while (str)
	{
		
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
	
	
	
	
	

	
	
}
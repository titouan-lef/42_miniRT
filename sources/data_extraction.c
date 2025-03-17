/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_extraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:29:30 by pchalmin          #+#    #+#             */
/*   Updated: 2025/03/17 21:39:48 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int extraction_data(char *file, t_scene *scene)
{
    int		fd;
	char	*str;

    fd = open(file, O_RDONLY);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:39:50 by pchalmin          #+#    #+#             */
/*   Updated: 2025/05/08 11:39:53 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_scene	scene;

	if (parsing(ac, av, &scene))
	{
		exit_error_parsing(&scene);
		return (1);
	}
	if (manage_graphical_system(&scene))
	{
		exit_error_parsing(&scene);
		return (1);
	}
	exit_error_parsing(&scene);
	return (0);
}

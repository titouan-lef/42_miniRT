/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:31:04 by pchalmin          #+#    #+#             */
/*   Updated: 2025/03/17 17:42:59 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

typedef	struct s_scene
{
	int	ambiance;
	int	camera;
	int	light;
	int	sphere;
	int	plan;
	int cylinder;
}	t_scene;

/*	RGB range [0-255], lr range [0.0, 1.0]*/
typedef	struct	s_ambiance
{
	float	lr;
	int		red;
	int		green;
	int		blue;
}	t_ambiance;

/*	RGB range [0-255], lr range [0.0, 1.0], FOV [0, 180]*/
typedef	struct	s_camera
{
	float	x_view;
	float	y_view;
	float	z_view;
	float	x_nor;
	float	y_nor;
	float	z_nor;
	int		fov;
}	t_camera;

/*	RGB range [0-255], lbr range [0.0, 1.0]*/
typedef	struct	s_light
{
	float	x_view;
	float	y_view;
	float	z_view;
	float	lbr;
	int		red;
	int		green;
	int		blue;
}	t_light;

typedef	struct	s_sphere
{
	float	x_pos;
	float	y_pos;
	float	z_pos;
	float	diam;
	int		red;
	int		green;
	int		blue;

}	t_sphere;

typedef	struct	s_plan
{
	float	x_view;
	float	y_view;
	float	z_view;
	float	x_nnv;
	float	y_nnv;
	float	z_nnv;
	int		red;
	int		green;
	int		blue;
}	t_plan;

typedef	struct	s_cylinder
{
	float	x_view;
	float	y_view;
	float	z_view;
	float	x_nnv;
	float	y_nnv;
	float	z_nnv;
	float	diam;
	float	height;
	int		red;
	int		green;
	int		blue;
}	t_cylinder;

#endif
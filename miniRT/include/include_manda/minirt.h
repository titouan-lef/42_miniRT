/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:42:34 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/12 11:55:09 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <SDL2/SDL_scancode.h>
# include "../../MacroLibX/includes/mlx.h"
# include "libft.h"
# include "macro.h"
# include "minirt_struct.h"
# include "parsing.h"
# include "raytracing.h"
# include "graphical_system.h"
# include "lighting.h"
# include "texturing.h"

/***********************************************
 * @brief MANDATORY WINDOW NAME
 ***********************************************/
# ifndef WIN_NAME
#  define WIN_NAME "miniRT"
# endif

/***********************************************
 * @brief MANDATORY PARAMETER
 ***********************************************/
# ifndef COLOR_LIGHT_ENABLE
#  define COLOR_LIGHT_ENABLE 0
# endif

# ifndef MAX_LIGHT
#  define MAX_LIGHT 1
# endif

# ifndef CONE_ENABLE
#  define CONE_ENABLE 0
# endif

# ifndef SPECULAR_ENABLE
#  define SPECULAR_ENABLE 0
# endif

# ifndef PATTERN_ENABLE
#  define PATTERN_ENABLE 0
# endif

# ifndef NB_PARAM_SP
#  define NB_PARAM_SP 4
# endif

# ifndef NB_PARAM_PL
#  define NB_PARAM_PL 4
# endif

# ifndef NB_PARAM_CY
#  define NB_PARAM_CY 6
# endif

# ifndef NB_PARAM_CO
#  define NB_PARAM_CO 9
# endif

/***********************************************
 * @brief MANDATORY ERROR
 ***********************************************/
# ifndef ERR_SPHERE
#  define ERR_SPHERE "A SPHERE are wrong.\n\
Try like this \"sp 0.0,0.0,20.6 12.6 10,0,255\"\n\
Identifier: sp\n\
x, y, z coordinates of the sphere center: 0.0,0.0,20.6\n\
The sphere diameter: 12.6\n\
R,G,B colors in the range [0-255]: 10, 0, 255"
# endif

# ifndef ERR_PLANE
#  define ERR_PLANE "A PLANE are wrong.\n\
Try like this \"pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225\"\n\
identifier: pl\n\
x, y, z coordinates of a point in the plane: 0.0,0.0,-10.0\n\
3D normalized normal vector, in the range [-1,1]\
for each x, y, z axis: 0.0,1.0,0.0\n\
R,G,B colors in the range [0-255]: 0,0,225"
# endif

# ifndef ERR_CYLINDER
#  define ERR_CYLINDER "A CYLINDER are wrong.\n\
Try like this \"cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255\"\n\
Identifier: cy\n\
x, y, z coordinates of the center of the cylinder: 50.0,0.0,20.6\n\
3D normalized vector of axis of the cylinder, in the range [-1,1]\
for each x, y, z axis: 0.0,0.0,1.0\n\
The cylinder diameter: 14.2\n\
The cylinder height: 21.42\n\
R, G, B colors in the range [0,255]: 10, 0, 255"
# endif

# ifndef ERR_CONE
#  define ERR_CONE "Undefined"
# endif

# ifndef ERR_ARG
#  define ERR_ARG "Please try ./miniRT \"files_name.rt\""
# endif

# ifndef ERR_NO_LIGHT
#  define ERR_NO_LIGHT "The SCENE need one LIGHT"
# endif

# ifndef ERR_ID
#  define ERR_ID "The SCENE have an invalid identifier \n\
Valid identifier are A, C, L, SP, PL and CY"
# endif

# ifndef ERR_TYPE_FILE
#  define ERR_TYPE_FILE "Undefined"
# endif

# ifndef ERR_CHECKERBOARD
#  define ERR_CHECKERBOARD "Undefined"
# endif

#endif
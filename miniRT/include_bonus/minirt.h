/// @todo header

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include "minirt_struct.h"
# include "minirt_parsing.h"
# include "minirt_raytrace.h"
# include "graphical_system.h"
# include "minirt_colors.h"
# include "menu_text.h"

# ifndef COLOR_LIGHT_ACTIVE
#  define COLOR_LIGHT_ACTIVE 1
# endif

# ifndef MAX_LIGHT
#  define MAX_LIGHT INFINITY
# endif

# ifndef CONE_ACTIVE
#  define CONE_ACTIVE 1
# endif

# ifndef SPECULAR_ACTIVE
#  define SPECULAR_ACTIVE 1
# endif

# ifndef PATTERN_ACTIVE
#  define PATTERN_ACTIVE 1
# endif

# ifndef NB_PARAM_SP
#  define NB_PARAM_SP 7
# endif

# ifndef NB_PARAM_PL
#  define NB_PARAM_PL 7
# endif

# ifndef NB_PARAM_CY
#  define NB_PARAM_CY 9
# endif

# ifndef NB_PARAM_CO
#  define NB_PARAM_CO 9
# endif

# ifndef ERR_AMBIENT
#  define ERR_AMBIENT "An AMBIENT are wrong.\n\
Try like this \"A 0.2 255,255,255\"\n\
Identifier: A\n\
Ambient lighting ratio in the range [0.0,1.0]\n\
R, G, B colors in the range [0-255]: 255, 255, 255"
# endif

# ifndef ERR_LIGHT
#  define ERR_LIGHT "An LIGHT are wrong.\n\
Try like this \"L -40.0,50.0,0.0 0.6 10,0,255\"\n\
Identifier: L\n\
x, y, z coordinates of the light point: -40.0,50.0,0.0\n\
The light brightness ratio in the range [0.0,1.0]: 0.6\n\
R, G, B colors in the range [0-255]: 10, 0, 255"
# endif

# ifndef ERR_CAMERA
#  define ERR_CAMERA "Your CAMERA is wrong.\n\
Try like this \"C -50.0,0,20 0,0,1 70\"\n\
Identifier: C\n\
x, y, z coordinates of the viewpoint: -50.0,0,20\n\
3D normalized orientation vector, in the range [-1,1]\
for each x, y, z axis: 0.0,0.0,1.0\n\
FOV: Horizontal field of view in degrees in the range [0,180]: 70"
# endif

# ifndef ERR_SPHERE
#  define ERR_SPHERE "A SPHERE are wrong.\n\
Try like this \"sp 0.0,0.0,20.6 12.6 10,0,255\"\n\
Identifier: sp\n\
x, y, z coordinates of the sphere center: 0.0,0.0,20.6\n\
The sphere diameter: 12.6\n\
R,G,B colors in the range [0-255]: 10, 0, 255\n\
ON to activate or OFF to deactivate the checkerboard\n\
Path of pattern file in .png or NULL for deactivated\n\
Path of bump file in .png or NULL for deactivated"

# endif

# ifndef ERR_PLANE
#  define ERR_PLANE "A PLANE are wrong.\n\
Try like this \"pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225\"\n\
identifier: pl\n\
x, y, z coordinates of a point in the plane: 0.0,0.0,-10.0\n\
3D normalized normal vector, in the range [-1,1]\
for each x, y, z axis: 0.0,1.0,0.0\n\
R,G,B colors in the range [0-255]: 0,0,225\n\
ON to activate or OFF to deactivate the checkerboard\n\
Path of pattern file in .png or NULL for deactivated\n\
Path of bump file in .png or NULL for deactivated"
# endif

# ifndef ERR_CYLINDER
#  define ERR_CYLINDER "A CYLINDER are wrong.\n\
Try like this \"cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255\"\n\
Identifier: cy\n\
x, y, z coordinates of the center of the cylinder: 50.0,0.0,20.6\n\
3D normalized vector of axis of cylinder, in the range [-1,1]\
for each x, y, z axis: 0.0,0.0,1.0\n\
The cylinder diameter: 14.2\n\
The cylinder height: 21.42\n\
R, G, B colors in the range [0,255]: 10, 0, 255\n\
ON to activate or OFF to deactivate the checkerboard\n\
Path of pattern file in .png or NULL for deactivated\n\
Path of bump file in .png or NULL for deactivated"
# endif

# ifndef ERR_CONE
#  define ERR_CONE "A CONE are wrong.\n\
Try like this \"co 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255\"\n\
Identifier: co\n\
x, y, z coordinates of the center of the cylinder: 50.0,0.0,20.6\n\
3D normalized vector of axis of cylinder, in the range [-1,1]\
for each x, y, z axis: 0.0,0.0,1.0\n\
The cone diameter: 14.2\n\
The cone height: 21.42\n\
R, G, B colors in the range [0,255]: 10, 0, 255\n\
ON to activate or OFF to deactivate the checkerboard\n\
Path of pattern file in .png or NULL for deactivated\n\
Path of bump file in .png or NULL for deactivated"
# endif

# ifndef ERR_ARG
#  define ERR_ARG "Please try ./miniRT_bonus \"files_name.rt\""
# endif

# ifndef ERR_NB_AMB
#  define ERR_NB_AMB "The SCENE need one ambient AMBIENT"
# endif

# ifndef ERR_NB_CAM
#  define ERR_NB_CAM "The SCENE need one CAM"
# endif

# ifndef ERR_NO_LIGHT
#  define ERR_NO_LIGHT "The SCENE need minimum one LIGHT"
# endif

# ifndef ERR_NO_OBJ
#  define ERR_NO_OBJ "The SCENE need minimum one OBJ"
# endif

# ifndef ERR_ID
#  define ERR_ID "The SCENE have an invalid identifier \n\
Valid identifier are A, C, L, SP, PL, CY and CO"
# endif

# ifndef ERR_OPEN_FAILED
#  define ERR_OPEN_FAILED "Open at xxx.c at line xx failed please\
check the presence, permission and reload"
# endif

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:41:40 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/14 11:32:13 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

/***********************************************
 * @brief WINDOW INFO
 ***********************************************/
# ifndef WIN_W
#  define WIN_W 1920.0
# endif

# ifndef WIN_H
#  define WIN_H 1080.0
# endif

# ifndef WIN_HW
#  define WIN_HW 960.0
# endif

# ifndef WIN_HH
#  define WIN_HH 540.0
# endif

# ifndef FPS
#  define FPS 24
# endif

/***********************************************
 * @brief COLOR
 ***********************************************/
# ifndef WHITE
#  define WHITE 0xFFFFFFFF
# endif

# ifndef BLACK
#  define BLACK 0x000000FF
# endif

/***********************************************
 * @brief MENU
 ***********************************************/
# ifndef MENU_W
#  define MENU_W 220
# endif

# ifndef MENU_H
#  define MENU_H 180
# endif

# ifndef TEXT_COLOR
#  define TEXT_COLOR 0x00A1FFFF
# endif

# ifndef MENU_COLOR
#  define MENU_COLOR 0x00000099
# endif

# ifndef FULL_SCREEN_AVAILABLE
#  define FULL_SCREEN_AVAILABLE 0
# endif

# ifndef X
#  define X "On X axis"
# endif

# ifndef Y
#  define Y "On Y axis"
# endif

# ifndef Z
#  define Z "On Z axis"
# endif

# ifndef V_RIGHT
#  define V_RIGHT "On Right axis"
# endif

# ifndef V_UP
#  define V_UP "On Up axis"
# endif

# ifndef V_FORWARD
#  define V_FORWARD "On Forward axis"
# endif

# ifndef D
#  define D "Change Diameter"
# endif

# ifndef H
#  define H "Change Height"
# endif

# ifndef T
#  define T "Translation :"
# endif

# ifndef T_PL
#  define T_PL "Translation"
# endif

# ifndef R
#  define R "Rotation :"
# endif

# ifndef M
#  define M "Menu :"
# endif

# ifndef M_O
#  define M_O "Press O for select Object"
# endif

# ifndef M_L
#  define M_L "Press L for select Light"
# endif

# ifndef LGT
#  define LGT "Light"
# endif

# ifndef OBJ_SP
#  define OBJ_SP "Sphere"
# endif

# ifndef OBJ_PL
#  define OBJ_PL "Plane"
# endif

# ifndef OBJ_CY
#  define OBJ_CY "Cylinder"
# endif

# ifndef OBJ_CO
#  define OBJ_CO "Cone"
# endif

/***********************************************
 * @brief MATHEMATICS
 ***********************************************/
# ifndef EPSILON
#  define EPSILON 0.000001
# endif

/***********************************************
 * @brief PROPERTY
 ***********************************************/
# ifndef SENSITIVITY
#  define SENSITIVITY 0.1
# endif

# ifndef DIST
#  define DIST 10
# endif

# ifndef ANGLE_ROTATION
#  define ANGLE_ROTATION 0.05
# endif

/***********************************************
 * @brief LIGHTING
 ***********************************************/
# ifndef KA
#  define KA 0.5
# endif

# ifndef KD
#  define KD 0.5
# endif

# ifndef KS
#  define KS 0.5
# endif

/***********************************************
 * @brief COMMON ERROR
 ***********************************************/
# ifndef ERR_MLX_INIT
#  define ERR_MLX_INIT "Error\nInitialization mlx"
# endif

# ifndef ERR_BACK_BUFFER_INIT
#  define ERR_BACK_BUFFER_INIT "Error\nInitialization back buffer"
# endif

# ifndef ERR_FRONT_BUFFER_INIT
#  define ERR_FRONT_BUFFER_INIT "Error\nNitialization front buffer"
# endif

# ifndef ERR_WIN_INIT
#  define ERR_WIN_INIT "Error\nInitialization window"
# endif

# ifndef ERR_MENU_INIT
#  define ERR_MENU_INIT "Error\nInitialization menu"
# endif

# ifndef ERR_TEXTURE_INIT
#  define ERR_TEXTURE_INIT "Error\nInitialization texture"
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
3D normalized orientation vector, in the range [-1,1] \
for each x, y, z axis: 0.0,0.0,1.0\n\
FOV: Horizontal field of view in degrees in the range [0,180]: 70"
# endif

# ifndef ERR_NB_AMB
#  define ERR_NB_AMB "The SCENE need one ambient AMBIENT"
# endif

# ifndef ERR_NB_CAM
#  define ERR_NB_CAM "The SCENE need one CAM"
# endif

# ifndef ERR_NO_OBJ
#  define ERR_NO_OBJ "The SCENE need minimum one OBJ"
# endif

# ifndef ERR_MALLOC
#  define ERR_MALLOC "Malloc have failed please \
check the presence, permission and reload"
# endif

# ifndef ERR_OPEN
#  define ERR_OPEN "Open have failed please \
check the presence, permission and reload"
# endif

# ifndef ERR_COLOR
#  define ERR_COLOR "A Color argument are wrong"
# endif

# ifndef ERR_OBJ_SPHERE
#  define ERR_OBJ_SPHERE "Object error : Sphere"
# endif

# ifndef ERR_OBJ_PLANE
#  define ERR_OBJ_PLANE "Object error : Plane"
# endif

# ifndef ERR_OBJ_CYLINDER
#  define ERR_OBJ_CYLINDER "Object error : Cylinder"
# endif

# ifndef ERR_OBJ_CONE
#  define ERR_OBJ_CONE "Object error : Cone"
# endif

#endif
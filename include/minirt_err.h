/// @todo header

#ifndef MINIRT_ERR_H
# define MINIRT_ERR_H

# ifndef ERR_AMBIENT
#  define ERR_AMBIENT "An AMBIENT are wrong.\n\
Try like this \"A 0.2 255,255,255\"\n\
Identifier: A\n\
Ambient lighting ratio in the range [0.0,1.0]\n\
R, G, B colors in the range [0-255]: 255, 255, 255"
# endif

# ifndef ERR_LIGHT
#  define ERR_LIGHT "An AMBIENT are wrong.\n\
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
FOV: Horizontal field of view in degrees in the range [0,180]: 70\n"
# endif

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
3D normalized vector of axis of cylinder, in the range [-1,1]\
for each x, y, z axis: 0.0,0.0,1.0\n\
The cylinder diameter: 14.2\n\
The cylinder height: 21.42\n\
R, G, B colors in the range [0,255]: 10, 0, 255"
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
R, G, B colors in the range [0,255]: 10, 0, 255"
# endif

# ifndef ERR_ARG
#  define ERR_ARG "Please try ./miniRT \"files_name.rt\""
# endif

# ifndef ERR_SCENE
#  define ERR_SCENE "SCENE"
# endif

# ifndef ERR_ID
#  define ERR_ID "Please try with a valid object"
# endif

# ifndef ERR_OPEN_FAILED
#  define ERR_OPEN_FAILED "Open at xxx.c at line xx failed please \
check the presence, permission and reload"
# endif

#endif
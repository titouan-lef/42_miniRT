/// @todo header

#ifndef MINIRT_ERR_H
# define MINIRT_ERR_H

# ifndef ERR_AMBIENT
#  define ERR_AMBIENT "Error\n\
Try this like this \"A 0.2 255,255,255\"\n\
Identifier: A\n\
Ambient lighting ratio in the range [0.0,1.0]\n\
R, G, B colors in the range [0-255]: 255, 255, 255"
# endif

# ifndef ERR_LIGHT
#  define ERR_LIGHT "Error\nPlease try ./miniRT \"files_name.rt\""
# endif

# ifndef ERR_CAMERA
#  define ERR_CAMERA "Error\nPlease try ./miniRT \"files_name.rt\""
# endif

# ifndef ERR_SPHERE
#  define ERR_SPHERE "Error\nPlease try ./miniRT \"files_name.rt\""
# endif

# ifndef ERR_PLAN
#  define ERR_PLAN "Error\nPlease try ./miniRT \"files_name.rt\""
# endif

# ifndef ERR_CYLINDER
#  define ERR_CYLINDER "Error\nPlease try ./miniRT \"files_name.rt\""
# endif

# ifndef ERR_CONE
#  define ERR_CONE "Error\nPlease try ./miniRT \"files_name.rt\""
# endif

# ifndef ERR_ARG
#  define ERR_ARG "Error\nPlease try ./miniRT \"files_name.rt\""
# endif

# ifndef ERR_ID
#  define ERR_ID "Error\nPlease try with a valid object"
# endif

# ifndef ERR_OPEN_FAILED
#  define ERR_OPEN_FAILED "Open at xxx.c at line xx failed please check the presence, permission and reload"
# endif

# ifndef GNL_NULL
#  define GNL_NULL "Your files is empty or get_next_line have failed"
# endif

# ifndef SPLIT_NULL
#  define SPLIT_NULL "ft_split_charset have failed"
# endif

#endif
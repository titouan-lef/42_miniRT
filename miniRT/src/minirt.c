/// @todo header

#include "minirt.h"

int	main(int ac, char **av)
{
	int	result;
	t_scene	scene;

	//t_quaternion q = ft_create_quaternion(1,ft_create_vector3(2,3,4));
	//t_quaternion p = ft_create_quaternion(-5,ft_create_vector3(6,-7,8));
	//t_quaternion m = ft_product_quaternion(q, p);
	//t_quaternion c = ft_conjugation_quaternion(p);
	//printf("quaternion(%f, %f, %f, %f)\n", c.scalar, c.axis.x, c.axis.y, c.axis.z);

	/*t_vector3 point = ft_create_vector3(0,1,0);
	t_vector3 axis = ft_create_vector3(1,0,0);
	t_vector3 new = ft_rotation_quaternion(point, M_PI / 2.0, axis);
	printf("new(%f, %f, %f)\n", new.x, new.y, new.z);*/
	t_vector3 point = ft_create_vector3(0,1,0);
	double angle = 1.0 * M_PI / 2.0;
	t_vector3 axis = ft_create_vector3(1,0,0);
	t_vector3 new = ft_rotation_quaternion(point, angle, axis);
	printf("new(%f, %f, %f)\n", new.x, new.y, new.z);
	//manage_graphical_system();
	result = parsing(ac, av, &scene);
	exit_error_parsing(&scene);
	return (result);
}

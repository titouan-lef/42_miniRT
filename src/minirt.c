/// @todo header

#include "minirt.h"

int	main(int ac, char **av)
{
	t_scene scene;
	void 	*test;
	t_sphere *tes;

	parsing(ac, av, &scene);
	test = (((t_obj *)(scene.lst_obj->content))->data);
	tes = (t_sphere *)test;
	printf("%d\n", ((t_obj *)(scene.lst_obj->content))->type);
	printf("%f\n", tes->diam);
	return (0);
}

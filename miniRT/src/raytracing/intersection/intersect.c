/// @todo header

#include "minirt.h"

t_soluce	create_soluce(double t, const t_vec3 *p, const t_vec3 *n)
{
	t_soluce	soluce;

	soluce.t = t;
	soluce.p = *p;
	soluce.n = *n;
	return (soluce);
}
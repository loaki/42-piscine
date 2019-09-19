#include "bsq.h"

int		ft_stdin(void)
{
	t_data data;
	int  err;

	d_init(&data);
	data.fd = 0;
	if ((err = ft_ligne_argin(data.fd, &data)))
		return (err);

	return (ft_first_ligne2in(&data));
}

int 	main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac < 2)
		if (ft_stdin() != 0)
			write(1, "map error\n", 10);
	while (++i < ac)
	{
		if (ft_bsq(av[i]) != 0)
			write(1, "map error\n", 10);
		else if (i + 1 < ac)
			write(1, "\n", 1);
	}
}

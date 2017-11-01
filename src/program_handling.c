#include "graphics.h"

int	init_prog(t_prog* p)
{
	p->mode = (sfVideoMode){800, 600, 32};
	p->win = sfRenderWindow_create(p->mode,
				       "MyRunner",
				       sfClose | sfResize,
				       NULL);
	if (!p->win)
		exit(EXIT_FAILURE);
	p->color = sfBlack;
	return EXIT_SUCCESS;
}

int	start_prog(t_prog* prog)
{
	while (sfRenderWindow_isOpen(prog->win)) {
		events_main_loop(prog);
		sfRenderWindow_clear(prog->win, prog->color);
		sfRenderWindow_display(prog->win);
	}
	return EXIT_SUCCESS;
}

int	end_prog(t_prog* prog)
{
	sfRenderWindow_destroy(prog->win);
	return EXIT_SUCCESS;
}

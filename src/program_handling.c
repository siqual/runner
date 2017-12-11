#include "graphics.h"
#include <stdio.h>

int	prog_init(t_prog* p)
{
	t_pix*		pixels;
	t_pix*		pixels2;
	sfTexture*	texture;
	sfTexture*	texture2;
	
	p->mode = (sfVideoMode){800, 600, 32};
	p->win = sfRenderWindow_create(p->mode,
				       "MyRunner",
				       sfClose | sfResize,
				       NULL);
	if (!p->win)
		exit(EXIT_FAILURE);
	p->color = sfBlack;

	pixels = buffer_create(50, 50, sfBlue);
	texture = sfTexture_create(pixels->height, pixels->width);
	sfTexture_updateFromPixels(texture, pixels->data,
				   pixels->height, pixels->width,
				   0, 0);

	p->sprites[0] = sfSprite_create();
	sfSprite_setTexture(p->sprites[0], texture, sfTrue);
	buffer_destroy(pixels);

	pixels2 = buffer_create(50, 50, sfRed);
	texture2 = sfTexture_create(pixels2->height, pixels2->width);
	sfTexture_updateFromPixels(texture2, pixels2->data,
				   pixels2->height, pixels2->width,
				   0, 0);
	p->sprites[1] = sfSprite_create();
	sfSprite_setTexture(p->sprites[1], texture2, sfTrue);
	sfSprite_setPosition(p->sprites[1], (sfVector2f){200, 200});
	return EXIT_SUCCESS;
}

int	prog_start(t_prog* prog)
{
	while (sfRenderWindow_isOpen(prog->win)) {
		events_main_loop(prog);
		sfRenderWindow_clear(prog->win, prog->color);
		sfRenderWindow_drawSprite(prog->win, prog->sprites[0], NULL);
		sfRenderWindow_drawSprite(prog->win, prog->sprites[1], NULL);
		sfRenderWindow_display(prog->win);
	}
	return EXIT_SUCCESS;
}

int	prog_end(t_prog* prog)
{
	sfSprite_destroy(prog->sprites[0]);
	sfSprite_destroy(prog->sprites[1]);
	sfRenderWindow_destroy(prog->win);
	return EXIT_SUCCESS;
}

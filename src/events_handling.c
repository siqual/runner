/*
** events_handling.c for  in /home/siqual/igraph/runner/src
** 
** Made by Siqual
** Login   <siqual@8570p>
** 
** Started on  Tue Oct 31 16:29:30 2017 Siqual
** Last update Tue Oct 31 16:30:48 2017 Siqual
*/

#include "graphics.h"

int	events_main_loop(t_prog* prog)
{
	while (sfRenderWindow_pollEvent(prog->win, &(prog->event))) {
		events_window(prog);
		events_keyboard(prog);
		events_mouse(prog);
	}
	return EXIT_SUCCESS;
}

int	events_window(t_prog* prog)
{
	if (prog->event.type == sfEvtClosed)
		sfRenderWindow_close(prog->win);
	return EXIT_SUCCESS;
}

int	events_keyboard(t_prog* prog)
{
	if (prog->event.type == sfEvtKeyPressed) {
		if (sfKeyboard_isKeyPressed(sfKeySpace)) {
		 	prog->color =
				sfColor_toInteger(prog->color) ==
				sfColor_toInteger(sfWhite) ?
				sfBlack : sfWhite;
		}
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(prog->win);
	}
	return EXIT_SUCCESS;
}

int	events_mouse(t_prog* prog)
{
	(void)prog;
	return EXIT_SUCCESS;
}

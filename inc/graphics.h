/*
** graphics.h for  in /home/siqual/igraph/runner/inc
** 
** Made by Siqual
** Login   <siqual@8570p>
** 
** Started on  Tue Oct 31 11:25:40 2017 Siqual
** Last update Tue Oct 31 17:22:39 2017 Siqual
*/

#pragma once

#include <stdlib.h>
#include <SFML/Graphics.h>

struct	s_prog
{
	sfRenderWindow*	win;
	sfVideoMode	mode;
	sfEvent         event;
	sfColor         color;
};

typedef struct s_prog t_prog;

/* program_handling.c */
int	init_prog(t_prog*);
int	start_prog(t_prog*);
int	end_prog(t_prog*);

/* event_handling.c */
int	events_main_loop(t_prog*);
int	events_window(t_prog*);
int	events_keyboard(t_prog*);
int	events_mouse(t_prog*);

/* collision_handling.c */
int	circle_collision(sfSprite*, sfSprite*);

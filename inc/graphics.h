/*
** graphics.h for  in /home/siqual/igraph/runner/inc
** 
** Made by Siqual
** Login   <siqual@8570p>
** 
** Started on  Tue Oct 31 11:25:40 2017 Siqual
** Last update Fri Nov 10 15:32:54 2017 Siqual
*/

#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <SFML/Graphics.h>

struct	s_pixels
{
	sfUint8*	data;
	uint32_t	height;
	uint32_t	width;
};

typedef struct s_pixels t_pix;

struct s_sprite
{
	sfSprite*	sprite;
	sfTexture*	texture;
	t_pix*		pixels;
};

typedef struct s_sprite t_sprite;

struct	s_prog
{
	sfRenderWindow*	win;
	sfVideoMode	mode;
	sfEvent         event;
	sfColor         color;
	sfSprite**	sprites; // sprites' container
};

typedef struct s_prog t_prog;

/* program_handling.c */
int	prog_init(t_prog*);
int	prog_start(t_prog*);
int	prog_end(t_prog*);

/* program_sprites_handling.c */
t_sprite*	prog_sprites_create();
void		prog_sprites_add();
void		prog_sprites_delete();


/* event_handling.c */
int	events_main_loop(t_prog*);
int	events_window(t_prog*);
int	events_keyboard(t_prog*);
int	events_mouse(t_prog*);

/* collision_handling.c */
int	collision_sprite(sfSprite*, sfSprite*);
int	collision_rectangle(sfRectangleShape*, sfRectangleShape*);

/* buffer_handling.c */
t_pix*	buffer_create(uint32_t, uint32_t, sfColor);
void	buffer_destroy(t_pix*);

/* sprite_handling.c */
t_sprite*	sprite_create(sfTexture*, t_pix*);
void		sprite_setTexture(t_sprite*, sfTexture*);
void		sprite_destroy(t_sprite*);
/* void		sprite_updateBuffer(t_sprite*); */

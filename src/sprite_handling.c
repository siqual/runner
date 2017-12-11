/*
** sprite_handling.c for  in /home/siqual/igraph/runner/inc
** 
** Made by Siqual
** Login   <siqual@8570p>
** 
** Started on  Thu Nov  2 15:56:31 2017 Siqual
** Last update Thu Nov  2 16:47:09 2017 Siqual
*/

#include "graphics.h"

t_sprite*	sprite_create(sfTexture* texture, t_pix* pixels)
{
	t_sprite*	new;

	new = malloc(sizeof(*new_sprite));
	if (!new)
		return NULL;
	new->sprite = sfSprite_create();
	new->texture = texture;
	new->pixels = pixels;
	sfTexture_updateFromPixels(new->texture, new->pixels->data,
				   new->pixels->height, new->pixels->width,
				   0, 0);
	sfSprite_setTexture(new->sprite, new->texture, sfTrue);
	return new;
}

void		sprite_setTexture(t_sprite* this, sfTexture* texture)
{
	if (texture) {
		if (this->texture)
			sfTexture_destroy(this->texture);
		this->texture = texture;
	}
}

void		sprite_destroy(t_sprite* this)
{
	buffer_destroy(this->pixels);
	sfTexture_destroy(this->texture);
	sfSprite_destroy(this->sprite);
	free(this);
}

/*
** collision_handling.c for  in /home/siqual/igraph/runner/src
** 
** Made by Siqual
** Login   <siqual@8570p>
** 
** Started on  Tue Oct 31 17:21:39 2017 Siqual
** Last update Thu Nov  2 14:11:48 2017 Siqual
*/

#include "graphics.h"
#include <math.h>

int	collision_sprite(sfSprite* obj1, sfSprite* obj2)
{
	sfFloatRect r1;
	sfFloatRect r2;

	r1 = sfSprite_getGlobalBounds(obj1);
	r2 = sfSprite_getGlobalBounds(obj2);
	return sfFloatRect_intersects(&r1, &r2, NULL);
}

int	collision_rectangle(sfRectangleShape* obj1, sfRectangleShape* obj2)
{
	sfFloatRect r1;
	sfFloatRect r2;

	r1 = sfRectangleShape_getGlobalBounds(obj1);
	r2 = sfRectangleShape_getGlobalBounds(obj2);
	return sfFloatRect_intersects(&r1, &r2, NULL);
}

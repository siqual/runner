/*
** collision_handling.c for  in /home/siqual/igraph/runner/src
** 
** Made by Siqual
** Login   <siqual@8570p>
** 
** Started on  Tue Oct 31 17:21:39 2017 Siqual
** Last update Wed Nov  1 09:37:51 2017 Siqual
*/

#include "graphics.h"
#include <math.h>

int	circle_collision(sfSprite* obj1, sfSprite* obj2)
{
	float	radius1;
	float	radius2;
	float	x_dist;
	float	y_dist;

	radius1 = (sfSprite_getPosition(obj1).x +
		   sfSprite_getPosition(obj1).y) / 4;
	radius2 = (sfSprite_getPosition(obj2).x +
		   sfSprite_getPosition(obj2).y) / 4;
	x_dist = (sfSprite_getPosition(obj1).x -
		  sfSprite_getPosition(obj2).x);
	y_dist = (sfSprite_getPosition(obj1).y -
		  sfSprite_getPosition(obj2).y);
	return sqrt(x_dist * x_dist + y_dist * y_dist) <= radius2 + radius1;
}

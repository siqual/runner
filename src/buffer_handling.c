/*
** buffer_handling.c for  in /home/siqual/igraph/runner/src
** 
** Made by Siqual
** Login   <siqual@8570p>
** 
** Started on  Thu Nov  2 14:03:37 2017 Siqual
** Last update Thu Nov  2 14:10:35 2017 Siqual
*/

#include "graphics.h"

t_pix*	buffer_create(uint32_t x, uint32_t y, sfColor c)
{
	t_pix*		pixels;
	uint32_t	i;
	
	pixels = malloc(sizeof(*pixels));
	pixels->data = malloc(x * y * 4 * sizeof(sfUint8));
	if (!pixels && !pixels->data)
		return NULL;
	i = 0;
	while (i < x * y * 4) {
		pixels->data[i + 0] = c.r;
		pixels->data[i + 1] = c.g;
		pixels->data[i + 2] = c.b;
		pixels->data[i + 3] = c.a;
		i += 4;
	}
	pixels->height = x;
	pixels->width = y;
	return pixels;
}

void	buffer_destroy(t_pix* pix)
{
	if (pix) {
		free(pix->data);
		free(pix);
	}
}

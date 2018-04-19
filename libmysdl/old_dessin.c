#include <stdint.h>
#include "libmysdl.h"

void dessin(SDL_Renderer *ren, t_point size) 
{
	uint32_t		*pixels;
	uint32_t		*p;
	SDL_Texture		*tex;
	uint8_t			r,g,b;
	int				x,y;

	pixels = (uint32_t*) malloc(width * height * sizeof(uint32_t));
	if (!img)
		return ;
	tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING, width, height);
	p = pixels;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			r = 255 * y / height;
			g = 255 * x / width;
			b = 255 * (x+y) / (width + height);
			*p = get_color(255,r,g,b);
			p++;
			x++;
		}
		y++;
	}
	SDL_UpdateTexture(tex, NULL, pixels, width * sizeof (Uint32));
	SDL_RenderCopy(ren,tex, NULL, NULL);
	SDL_RenderPresent(ren);
	SDL_DestroyTexture(tex);
	free(pixels);
}

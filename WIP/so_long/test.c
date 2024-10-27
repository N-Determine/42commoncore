#include "so_long.h"

#define WWIDTH 1280
#define WHIGHT 720

int	get_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

int main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WWIDTH, WHIGHT, "new window");
	while (1)
	{
		void *image = mlx_new_image(mlx_ptr, WWIDTH, WHIGHT);
		mlx_put_image_to_window(mlx_ptr, mlx_win, image, 0, 0);
		
	}

	mlx_destroy_window(mlx_ptr, mlx_win);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}
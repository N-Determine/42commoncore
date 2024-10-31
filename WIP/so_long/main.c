#include "so_long.h"

#define WWIDTH 1280
#define WHIGHT 720
#define WINDOW_NAME "new window"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	image;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WWIDTH, WHIGHT, WINDOW_NAME);

	image.img = mlx_new_image(mlx_ptr, WWIDTH, WHIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);


		
		

	mlx_put_image_to_window(mlx_ptr, mlx_win, image.img, 0, 0);
	mlx_destroy_image(mlx_ptr, image.img);

	mlx_loop(mlx_ptr);

	// Getting rid of stuff
	mlx_destroy_window(mlx_ptr, mlx_win);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}
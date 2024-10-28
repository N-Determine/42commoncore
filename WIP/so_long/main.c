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


typedef struct s_square_bounded {
	int x_offset;
	int y_offset;
	int x_size;
	int y_size;
	int fill_color;
	int bound_color;
	int bound_size;

}			t_square_bounded;










int main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	image;
	t_square_bounded sqr; 

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WWIDTH, WHIGHT, WINDOW_NAME);
	while (1)
	{
		image.img = mlx_new_image(mlx_ptr, WWIDTH, WHIGHT);
		image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);


		/*
		// Making a single colored square
		int x_offset = 5;
		int y_offset = 5;
		int x_size = 50;
		int y_size = 50;
		int color = 0x0000FFFF;
		for (int i = 0; i < x_size; i++)
		{
			for (int j = 0; j < y_size; j++)
			{
				ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, color);
			}
		}*/

		// Making a square with a gradient
		int x_offset = 5;
		int y_offset = 5;
		int x_size = 500;
		int y_size = 500;
		int color = 0x0000FFFF;
		for (int i = 0; i < x_size; i++)
		{
			for (int j = 0; j < y_size; j++)
			{
				ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, get_rgb(255, 0, i / 2)); // Check how to map i so it goes from 0 to 255
			}
		}

		/*
		// Draw a square using a the square struct
		sqr.x_offset = 5;
		sqr.y_offset = 5;
		sqr.x_size = 50;
		sqr.y_size = 50;
		sqr.fill_color = 0x00d6caa5;
		sqr.bound_color = 0x00af9c63;
		sqr.bound_size = 2;
		for (int i = 0; i < sqr.x_size; i++)
		{
			for (int j = 0; j < sqr.y_size; j++)
			{
				if (i < sqr.bound_size)
					ft_mlx_pixel_put(&image, sqr.x_offset + i, sqr.y_offset + j, sqr.bound_color);
				else if (j < sqr.bound_size)
					ft_mlx_pixel_put(&image, sqr.x_offset + i, sqr.y_offset + j, sqr.bound_color);
				else if (i >= sqr.y_size - sqr.bound_size)
					ft_mlx_pixel_put(&image, sqr.x_offset + i, sqr.y_offset + j, sqr.bound_color);
				else if (j >= sqr.x_size - sqr.bound_size)
					ft_mlx_pixel_put(&image, sqr.x_offset + i, sqr.y_offset + j, sqr.bound_color);
				else
					ft_mlx_pixel_put(&image, sqr.x_offset + i, sqr.y_offset + j, sqr.fill_color);
			}
		}
		*/

		/*
		// Making a square with a bound
		x_offset = 5;
		y_offset = 5;
		x_size = 50;
		y_size = 50;
		int fill_color = 0x00d6caa5;
		int bound_color = 0x00af9c63;
		int bound_size = 2;
		for (int i = 0; i < x_size; i++)
		{
			for (int j = 0; j < y_size; j++)
			{
				if (i < bound_size)
					ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, bound_color);
				else if (j < bound_size)
					ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, bound_color);
				else if (i >= y_size - bound_size)
					ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, bound_color);
				else if (j >= x_size - bound_size)
					ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, bound_color);
				else
					ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, fill_color);
			}
		}*/


		/*
		// Making a square next to the other one with different colors
		int x_offset = 5 + 50;
		int y_offset = 5;
		int x_size = 50;
		int y_size = 50;
		int fill_color = 0x001e8eec;
		int bound_color = 0x00f4ba7d;
		int bound_size = 2;
		for (int i = 0; i < x_size; i++)
		{
			for (int j = 0; j < y_size; j++)
			{
				if (i < bound_size)
					ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, bound_color);
				else if (j < bound_size)
					ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, bound_color);
				else if (i >= y_size - bound_size)
					ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, bound_color);
				else if (j >= x_size - bound_size)
					ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, bound_color);
				else
					ft_mlx_pixel_put(&image, x_offset + i, y_offset + j, fill_color);
			}
		}*/











		mlx_put_image_to_window(mlx_ptr, mlx_win, image.img, 0, 0);
		mlx_destroy_image(mlx_ptr, image.img);
	}

	mlx_destroy_window(mlx_ptr, mlx_win);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}
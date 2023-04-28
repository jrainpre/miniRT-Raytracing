#ifndef IMAGE_H
# define IMAGE_H

# define WIN_W 1920.0
# define WIN_H 1080.0

# include "sphere.h"
# include "light.h"
# include "ray.h"

typedef struct s_resolution
{
	int	width;
	int	height;
}			t_resolution;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_scene	*scene;
	t_lst_ref		*scene_lines;
	t_img			*img;
	t_resolution	win;
	t_color			*pixelcolors;
	int 			pixelcolors_int;
	t_lst			*slected_obj;
}			t_data;

int		loop_hook(t_data *data);
int		key_hook1(int keysym, t_data *data);
int		close_app(t_data *data);
int		start_mlx(t_data *data);
void	img_pix_put(t_data *data, int x, int y, int color);
void	render_background(t_data *data, int color);
float_t	deg_to_rad(float_t deg);
void	render_scene(t_data *data);

#endif
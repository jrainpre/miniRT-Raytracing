#ifndef IMAGE_H
# define IMAGE_H

# define WIN_W 1280
# define WIN_H 720

# include "miniRT.h"
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
	t_img			img;
}			t_data;

int		loop_hook(t_data *data);
int		key_hook1(int keysym, t_data *data);
int		close_app(t_data *data);
int		start_mlx(t_data *data);
void	img_pix_put(t_img *img, t_pt pt);
void	render_background(t_img *img, int color);

#endif
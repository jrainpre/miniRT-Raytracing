#ifndef COLORS_H
# define COLORS_H

# define RED	0x00FF0000
# define DRED	0x00660000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define DBLUE	0x00000066
# define PURPLE	0x00B491C8
# define WHITE	0x00FFFFFF
# define DGREEN	0x00006600
# define BLACK	0x00000000
# define GREY	0x00888888
# define DGREY	0x00333333
# define NOCOLOR	0x00000000

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}			t_color;

#endif

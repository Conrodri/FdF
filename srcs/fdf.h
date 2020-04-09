/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/03 17:30:29 by rcodazzi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 18:04:33 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define BUFF_SIZE 4096
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# define X 1980
# define Y 1200
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF

typedef struct	s_points
{
	int			xi;
	int			yi;
	int			xf;
	int			yf;
	int			xinc;
	int			yinc;
	int			i;
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			inc;
	int			color;
}				t_points;

typedef struct	s_struct
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*line;
	char		**map;
	int			**intmap;
	int			sizex;
	int			sizey;
	int			sizez;
	int			l;
	t_points	*bresen;
}				t_struct;

void			decrease_z(t_struct *mlx);
int				get_next_line(int fd, char **line);
void			ft_print_map(char **map);
char			**addline(char **map, char *line);
char			**getmap(t_struct *mlx, int *fd);
int				getsizemap(t_struct *mlx, int i, int j, int k);
void			ft_error(void);
int				**getintmap(t_struct *mlx, int i, int j, int k);
void			print_int_map(t_struct *mlx);
int				**ft_feed_tab(t_struct *mlx, int i, int j, int k);
void			ft_bresen(t_struct *mlx, t_points *bresen);
t_points		*ft_init_bresen(t_points *bresen);
void			print_tab_win(t_struct *mlx, t_points pos);
int				trace_horizontal(t_struct *mlx, t_points bresen);
void			ft_trace_horizontal(int i, t_struct *mlx, t_points bresen);
void			ft_fdf(int key, t_struct *mlx, t_points *bresen);
int				ft_sqrt(int nb);
void			plot_line (t_struct *mlx, t_points *bresen, int err, int e);
void			increase_z(t_struct *mlx);
void			parall_horiz(t_struct *mlx, t_points *bresen, int j, int i);
void			parall_vertical(t_struct *mlx, t_points *bresen, int j, int i);
void			ft_color_white(t_struct *mlx);
void			ft_color_blue(t_struct *mlx);
void			ft_increase_z(t_struct *mlx);
void			ft_decrease_z(t_struct *mlx);

#endif

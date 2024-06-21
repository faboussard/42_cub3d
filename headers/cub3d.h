/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:46:46 by mbernard          #+#    #+#             */
/*   Updated: 2024/06/21 15:46:50 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

#define mapWidth 24
#define mapHeight 24
#define WIDTH_DISPLAY 640
#define HEIGHT_DISPLAY 480

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_image;

typedef struct s_player
{
	size_t		x;
	size_t		y;
	size_t		moves;
}				t_player;

typedef struct s_map
{
	size_t		rows;
	size_t		cols;
	size_t		coins;
	char		**grid;
	char		**copy;
	bool		status;
	t_player	player;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*empty;
	void		*wall;
	void		*coll;
	void		*exit;
	void		*up;
	void		*down;
	void		*left;
	void		*right;
	char		emp_img[26];
	char		wall_img[25];
	char		coll_img[26];
	char		exit_img[26];
	char		up_img[23];
	char		down_img[25];
	char		left_img[25];
	char		right_img[26];
	t_map		map;
	t_image		my_image;
	double      pos_X;
	double      pos_Y;
	double      dir_X;
	double      dir_Y;
	double      plane_X;
	double      plane_Y;
	double      ray_Dir_X;
	double      ray_Dir_Y;
	int         **worldMap;
}				t_data;

////////////////////////////////////////////////////////////////////////
////////     				ERRORS                  ////////
////////////////////////////////////////////////////////////////////////
void			no_such_file_error(void);
void			malloc_error(void);
void			input_error(void);
void			map_error(char **map, char **copy);
void			empty_file_error(void);
////////////////////////////////////////////////////////////////////////
////////     				UTILS			////////
////////////////////////////////////////////////////////////////////////
int				close_window(t_data *img);
void			free_tabs(char **map, char **copy);
bool			ends_by_ber(char *file);
bool			ft_search_char(char letter, char *charset);
void			ft_put_pos_nbr_fd(size_t n, int fd);
////////////////////////////////////////////////////////////////////////
////////     				INIT			////////
////////////////////////////////////////////////////////////////////////
void			init_mlx_win(t_data *img);
void			init_screen(t_data *img);
////////////////////////////////////////////////////////////////////////
////////     				MAP			////////
////////////////////////////////////////////////////////////////////////
void			define_map(t_map *map, char *ber);
void			launch_checks(t_map *map, char *tmp_map);
void			fill_paths(t_map map, size_t x, size_t y);
bool			check_path(t_map *map);
////////////////////////////////////////////////////////////////////////
////////     				MOVES			////////
////////////////////////////////////////////////////////////////////////
void			move_player_img(t_data *img, size_t x, size_t y, int direction);
void			increment_moves(t_data *img);
void			move_up(t_data *img);
void			move_down(t_data *img);
void			move_left(t_data *img);
void			move_right(t_data *img);
////////////////////////////////////////////////////////////////////////
////////     				RAYCASTING			////////
////////////////////////////////////////////////////////////////////////
void raycasting(t_data *cub);
int	key_hook(int keysym, t_data *cub);
void	destroy_images(t_data *cub);
void	render(t_data *cub);

#endif

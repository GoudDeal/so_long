/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:11:21 by user42            #+#    #+#             */
/*   Updated: 2022/01/20 14:58:52 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1024
# define RED 0x00ff0000
# define BLACK 0x00000000
# define BLUE 0x000000ff
# define WHITE 0x00ffffff
# define PURPLE 0x00800080
# define GREEN 0x00008000
# define GRAY 0x00808080

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "../mlx-linux/mlx_int.h"
# include "../mlx-linux/mlx.h"
# include "./libft.h"

typedef struct s_data {
	t_img	*wall;
	t_img	*player;
	t_img	*free_space;
	t_img	*exit;
	t_img	*collectible;
	char	*wall_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
	char	**map;
	int		horizontal;
	int		vertical;
	int		collectible;
	int		exit;
	int		start;
	int		error;
	int		pos_x;
	int		pos_y;
	int		exit_pos_x;
	int		exit_pos_y;
	int		moves;
}				t_map;

typedef struct s_ptr {
	void	*mlx_ptr;
	void	*mlx_win;
	t_map	*map;
	t_data	*img;
}				t_ptr;

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
void	my_mlx_pixel_puts(t_data *data, int x, int y, int color);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		get_map(int fd, char *av, t_map **map);
t_map	*init_t_map(int ac, char *str, char **av);
char	*get_next_line(int fd);
int		verify_map(t_map *map);
t_data	*init_images(t_map *map, void *mlx_ptr);
void	launch(t_ptr *ptr);
void	fill_map(t_ptr *ptr);
void	put_player(t_ptr *ptr, int i, int j);
void	put_collectible(t_ptr *ptr, int i, int j);
void	put_exit(t_ptr *ptr, int i, int j);
void	put_wall(t_ptr *ptr, int i, int j);
void	put_grass(t_ptr *ptr, int i, int j);
int		exit_window(void *ptr);
int		move(int keycode, void *ptr);
void	move_up(t_ptr *ptr, t_map *map);
void	move_left(t_ptr *ptr, t_map *map);
void	move_right(t_ptr *ptr, t_map *map);
void	move_down(t_ptr *ptr, t_map *map);
void	free_them_all(t_ptr *ptr, int mode);
void	print_moves(t_ptr *ptr);
int		ft_cinset(const char c, const char *set);
int		verify_keys(t_map *map);
void	update_collectible(t_ptr *ptr);

#endif
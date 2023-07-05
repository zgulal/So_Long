#include "get_next_line/get_next_line.h"
#include "printf/ft_printf.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);


typedef struct s_main
{
	void    *mlx;
	void    *mlx_win;
	void    **img;
	char    *map;
	char    **split;
	char    **linesplit;
	int     row;
	int		column;
	int		map_y;
	int		map_x;
	int		image_x;
	int		image_y;
	int		step;
	int		coin;
	int		player;
	int		exit;
	int		exit_x;
	int		exit_y;

}   t_main;

void	line(t_main *data, int y, int x)
{
	if (data->linesplit[y][x + 1] == '0' || data->linesplit[y][x + 1] == 'C'
		|| data->linesplit[y][x + 1] == 'P')
	{
		data->linesplit[y][x + 1] = '.';
		line(data, y, x + 1);
	}
	if (data->linesplit[y][x - 1] == '0' || data->linesplit[y][x - 1] == 'C'
		|| data->linesplit[y][x - 1] == 'P')
	{
		data->linesplit[y][x - 1] = '.';
		line(data, y, x - 1);
	}
	if (data->linesplit[y + 1][x] == '0' || data->linesplit[y + 1][x] == 'C'
		|| data->linesplit[y + 1][x] == 'P')
	{
		data->linesplit[y + 1][x] = '.';
		line(data, y + 1, x);
	}
	if (data->linesplit[y - 1][x] == '0' || data->linesplit[y - 1][x] == 'C'
		|| data->linesplit[y - 1][x] == 'P')
	{
		data->linesplit[y - 1][x] = '.';
		line(data, y - 1, x);
	}
}

void	player_location(t_main *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split[i])
	{
		j = 0;
		while (data->split[i][j])
		{
			if (data->split[i][j] == 'P')
			{
				data->map_x = j;
				data->map_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	data->linesplit = ft_split(data->map, '\n');
	line(data, data->map_y, data->map_x);
}

void	exit_location(t_main *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split[i])
	{
		j = 0;
		while (data->split[i][j])
		{
			if (data->split[i][j] == 'E')
			{
				data->exit_x = j;
				data->exit_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	coin_reach(t_main *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->linesplit[i])
	{
		j = 0;
		while (data->linesplit[i][j])
		{
			if (data->linesplit[i][j] == 'C')
			{
				write(2, "Not reach the coin\n", 19);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	exit_reach(t_main *data)
{
	if (data->linesplit[data->exit_y][data->exit_x - 1] == '.')
		return ;
	if (data->linesplit[data->exit_y - 1][data->exit_x] == '.')
		return ;
	if (data->linesplit[data->exit_y][data->exit_x + 1] == '.')
		return ;
	if (data->linesplit[data->exit_y + 1][data->exit_x] == '.')
		return ;
	else
	{
		write(2, "not reach the exit\n", 19);
		exit(0);
	}
}

int    close_(t_main *z)
{
	mlx_destroy_window(z->mlx, z->mlx_win);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	step_by_step(t_main *data)
{
	char	*step;

	step = ft_itoa(data->step);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[2], 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[2], 64, 0);
	mlx_string_put(data->mlx, data->mlx_win, 0, 10, 0xffffff, "STEP =");
	mlx_string_put(data->mlx, data->mlx_win, 45, 10, 0xfffff, step);
	free(step);
}


void	step_plus(t_main *data)
{
	data->step++;
	step_by_step(data);
}

int	step_escape(t_main *data)
{
	step_plus(data);
	ft_printf("%d\n", data->step);
	exit(EXIT_FAILURE);
}

void	key_w(t_main *data)
{
	if (data->split[data->map_y - 1][data->map_x] == 'C')
	{
		data->coin--;
		data->split[data->map_y - 1][data->map_x] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		data->map_y--;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y - 1][data->map_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		data->map_y--;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y - 1][data->map_x] == 'E'
			&& data->coin == 0)
		step_escape(data);
}

void	key_d(t_main *data)
{
	if (data->split[data->map_y][data->map_x + 1] == 'C')
	{
		data->coin--;
		data->split[data->map_y][data->map_x + 1] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		data->map_x++;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x + 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		data->map_x++;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x + 1] == 'E'
			&& data->coin == 0)
		step_escape(data);
}

void	key_a(t_main *data)
{
	if (data->split[data->map_y][data->map_x - 1] == 'C')
	{
		data->coin--;
		data->split[data->map_y][data->map_x - 1] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		data->map_x--;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		data->map_x--;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y][data->map_x - 1] == 'E'
			&& data->coin == 0)
		step_escape(data);
}

void	key_s(t_main *data)
{
	if (data->split[data->map_y + 1][data->map_x] == 'C')
	{
		data->coin--;
		data->split[data->map_y + 1][data->map_x] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		data->map_y++;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y + 1][data->map_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4],
			data->map_x * 64, data->map_y * 64);
		data->map_y++;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			data->map_x * 64, data->map_y * 64);
		step_plus(data);
	}
	else if (data->split[data->map_y + 1][data->map_x] == 'E'
			&& data->coin == 0)
		step_escape(data);
}

void	view(t_main *data, int i, int j)
{
	if (data->split[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0], j * 64,
			i * 64);
	if (data->split[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[3], j * 64,
			i * 64);
	if (data->split[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[1], j * 64,
			i * 64);
	if (data->split[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[2], j * 64,
			i * 64);
	if (data->split[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4], j * 64,
			i * 64);
}

int key_press(int keyc, t_main *z)
{
	if (keyc == 53)
		close_(z);
	if ((keyc == 13 || keyc == 126) && z->split[z->map_y - 1][z->map_x] != '1')
		key_w(z);
	if ((keyc == 1 || keyc == 125) && z->split[z->map_y + 1][z->map_x] != '1')
		key_s(z);
	if ((keyc == 2 || keyc == 124) && z->split[z->map_y][z->map_x + 1] != '1')
		key_d(z);
	if ((keyc == 0 || keyc == 123) && z->split[z->map_y][z->map_x - 1] != '1')
		key_a(z);
	return (EXIT_SUCCESS);
}

void    map_reader(t_main *data, char *str)
{
	int fd;

	data->row = 0;
	fd = open(str, O_RDWR, 0777);
	if (fd == -1)
	{
		write (2, "Map couldn't read\n", 18);
		exit(EXIT_FAILURE);
	}
	data->map = get_next_line(fd);
	if (!data->map)
	{
		write (2, "Data couldn't find at map!\n", 27);
		exit(EXIT_FAILURE);
	}
	data->split = ft_split(data->map, '\n');
	while (data->split[data->row])
	{
		data->column = 0;
		while (data->split[data->row][data->column])
			data->column++;
		data->row++;
	}
}

void	background(t_main *data)
{
	int i;
	int j;

	i = -1;
	while (data->split[++i])
	{
		j = -1;
		while (data->split[i][++j])
		{
			if (data->split[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0], j * 64, i * 64);
			if (data->split[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[1], j * 64, i * 64);
			if (data->split[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[2], j * 64, i * 64);
			if (data->split[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[3], j * 64, i * 64);
			if (data->split[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[4], j * 64, i * 64);
			view(data, i, j);
		}
	}
	step_by_step(data);
}

void	window(t_main *data)
{
	data->img = malloc(sizeof(void *) * 5   );
	data->mlx = mlx_init();

	data->img[0] = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm", &data->image_x, &data->image_y);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "./textures/collectable.xpm", &data->image_x, &data->image_y);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &data->image_x, &data->image_y);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "./textures/door.xpm", &data->image_x, &data->image_y);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "./textures/background.xpm", &data->image_x, &data->image_y);
	data->mlx_win = mlx_new_window(data->mlx, data->column * 64, data->row * 64, "Welcome to Lokum's game!");
	background(data);
}

void	cpe_control(t_main *data)
{
	int	i;

	data->player = 0;
	data->exit = 0;
	data->coin = 0;
	data->step = 0;
	i = -1;
	while (data->map[++i])
	{
		if (data->map[i] == 'P')
			data->player++;
		if (data->map[i] == 'E')
			data->exit++;
		if (data->map[i] == 'C')
			data->coin++;
	}
	if ((data->coin == 0) || data->exit != 1 || data->player != 1)
	{
		write(2, "CPE BOOM!\n", 10);
		exit(EXIT_FAILURE);
	}
}

int	control(t_main *data, char *av)
{
	(void)av;
	cpe_control(data);
	player_location(data);
	coin_reach(data);
	exit_location(data);
	exit_reach(data);
	window(data);
	return (1);
}

int main(int ac, char **av)
{
	t_main *data;

	if (ac == 2)
	{
		data = (t_main *)malloc(sizeof(t_main));
		map_reader(data, av[1]);
		if (!control(data, av[1]))
			return (EXIT_FAILURE);
		mlx_hook(data->mlx_win, 2, 1L<<0, key_press, data);
		mlx_hook(data->mlx_win, 17, 1L<<17, close_, data);
		mlx_loop(data->mlx);
	}
}

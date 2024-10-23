/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:38:11 by messs             #+#    #+#             */
/*   Updated: 2024/10/23 21:14:54 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_input_error(int	argc)
{
	if (argc != 2)
		ft_print_error_msg("Error: Need to input a map(.ber)");
}

int is_ber_file(const char *filename)
{
    const char *extension = ".ber";
    size_t len_filename = ft_strlen(filename);
    size_t len_extension = ft_strlen(extension);

    if (len_filename >= len_extension)
        return (ft_strncmp(&filename[len_filename - len_extension], extension, len_extension) == 0);
    return 0;
}

void    get_window_size(window_data *window, char **av)
{
    int fd;

    fd = open(av[1], O_RDONLY);
    if(fd < 0)
    {
        perror("Error opening file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    if(is_ber_file(av[1]) == 0)
    {
        perror("ERROR : Map has to be a .ber extension.");
        close(fd);
        exit(EXIT_FAILURE);
    }
    window->width = (ft_line_length(fd) * IMG_W);
    window->height = (ft_count_lines(fd,window->width,IMG_W) * IMG_H);
    close(fd);
}

void	read_lines_to_map(window_data *window, int fd, char **map)
{
	int		i;
	char	*line;

	i = 0;
	while (i < window->height / IMG_H)
	{
		line = get_next_line(fd);

		if (line == NULL)
			ft_print_error_msg("Error: Reading line failed.");

		map[i] = ft_strndup(line, (size_t)(window->width / IMG_W)); 
		free(line);
		i++;
	}
}

void	ft_ber_to_array(window_data *window, int argc, char **argv)
{
	int		fd;
	char	**map;

	ft_input_error(argc);
	get_window_size(window, argv);

	map = (char **)malloc(sizeof(char *) * (window->height / IMG_H));
	if (!map)
        ft_print_error_msg("Error: Memory allocation failed.");

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		free(map);
        close(fd);
		exit(EXIT_FAILURE);
	}

	read_lines_to_map(window, fd, map);

	close(fd);
	window->map->map = map;

	ft_check_map(window);
}


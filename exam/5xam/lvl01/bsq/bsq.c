/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:07:12 by hthant            #+#    #+#             */
/*   Updated: 2025/12/01 19:04:55 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

static void error_exit(char **line, FILE *stream){
	fprintf(stderr, "Error: Invalid\n");
	if (*line)
        	free(*line);
	if (stream)
        	fclose(stream);
	exit(EXIT_FAILURE);
}

static bool check_char(char *row, char empty, char fill, char obstacle){
	for (size_t i = 0; row[i]; i++){
		if (row[i] == fill || (row[i] != empty && row[i] != obstacle))
			return false;
	}
	return true;
}

static void ft_free(void **arr, int rows){
	for(int i = 0; i < rows; i++){
		free(arr[i]);
	}
	free(arr);
}

static void solve_bsq(char **map, int rows, int cols, char empty, char fill, char obstacle){
	int **digit_map;
	int max_size = 0;
	int max_j = 0;
	int max_i = 0;

	digit_map = malloc(sizeof(int *) * rows); 
	if(!digit_map)
		return;
	for(int i = 0; i < rows; i++){
		digit_map[i] = calloc(cols, sizeof(int));
		if(!digit_map[i])
			return;
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(map[i][j] == obstacle)
				digit_map[i][j] = 0;
			else if ( i == 0 || j == 0)
				digit_map[i][j] = 1;
			else
			{
				int a = digit_map[i-1][j];
				int b = digit_map[i][j -1];
				int c = digit_map[i-1][j-1];

				int min = a;
				if( b < min )
					min = b;
				if (c < min)
					min = c;
				digit_map[i][j] = 1 + min;
			}
			if(digit_map[i][j] > max_size){
				max_size =  digit_map[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	for(int x = max_i; x > max_i - max_size; x--){
		for(int y = max_j ; y > max_j - max_size ; y--){
			map[x][y] = fill;
		}
	}    
	ft_free((void**)digit_map, rows);
}

int main(int argc, char *argv[]){
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int line_count;
	char empty;
	char obstacle;
	char fill;
	int total_char = 0;

	stream = (argc < 2) ? stdin : fopen(argv[1], "r");
	if (!stream)
		error_exit(&line, NULL);

	if(fscanf(stream,"%d%c%c%c\n", &line_count, &empty, &obstacle, &fill) != 4)
		error_exit(&line, stream);

	if (empty == obstacle || obstacle == fill || empty == fill)
		error_exit(&line, stream);

	char **map = calloc(line_count + 1, sizeof(char*));
	if (!map)
		error_exit(&line, stream);
	int first_len = -1;	
	for (int i = 0; i < line_count; i++){
		nread = getline(&line, &len, stream);
		if (nread <= 0)
			error_exit(&line, stream);

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		if(! check_char(line, empty, fill, obstacle))
			error_exit(&line,stream);

		int current_len = 0;
		while(line[current_len])
			current_len++;
		total_char = current_len;
		if(first_len == -1)
			first_len = current_len;
		else if(current_len != first_len)
			error_exit(&line, stream);

		map[i] = calloc(current_len + 1, sizeof(char));
		if (!map[i])
			error_exit(&line, stream);

		for (int j = 0; line[j]; j++)
			map[i][j] = line[j];
	}

	free(line);
	fclose(stream);
	solve_bsq(map, line_count , total_char, empty, fill, obstacle);
	int i = 0;
    	while (i < line_count)
    	{
        	printf("%s\n", map[i]);
        	i++;
	}
	ft_free((void**)map, line_count);
	return 0;
}

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	error(FILE *stream , char *line){
	fprintf(stderr, "ERROR: Invalid input\n");
	if(stream){
		fclose(stream);
	}
	if(line){
		free(line);
	}
	exit(EXIT_FAILURE);
}

int check_line_char(char *line, int char_count, char empty, char obstacle, char fill){
	if(!line)
		return -1;
	for(int i = 0; i < char_count - 2; ++i){
		if(line[i] == fill)
			return -1;
		else if (line[i] != empty && line[i] != obstacle)
			return -1;
	}
	return 1;
}

void	ft_free(char **map, int i){
	while(i --){
		free(map[i]);
		free(map);
	}
}

void	solve(char **map, char empty, char obstacle, char fill, int y, int x){
	int **new_map = calloc(y, sizeof(int *));
	for(int i = 0; i < y ; ++i){
		new_map[i] = calloc(x, sizeof(int));
		for(int j = 0; j < x ; ++j){
			new_map[i][j] = 0;
		}
	}
	int newx = 0;
	int newy = 0;
	int newsize = 0;
	for(int i = 0; i < y ; ++i){
		for(int j = 0; j < x; ++j){
			if(map[i][j] == obstacle)
				new_map[i][j] = 0;
			else if(i == 0 || j == 0)
				new_map[i][j] = 1;
			else{
				int a = new_map[i -1][j];
				int b = new_map[i][j -1];
				int c = new_map[i - 1][j -1];
				int min = a;
				if( b < min )
					min = b;
				if ( c < min )
					min = c;

				new_map[i][j] = min + 1;
			}
			if( new_map[i][j] > newsize )
			{
				newsize = new_map[i][j];
				newx = j;
				newy = i;
			}
		}
	}
	for(int y = newy - newsize + 1; y <= newy; y++){
		for(int x = newx - newsize + 1; x <= newx; x++){
				map[y][x] = fill;
		}
	}
	for(int i = 0; i < y ; i ++){
		for(int j = 0; j < x ; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void getinput(FILE *stream){
	ssize_t	nread;
	size_t	len = 0;
	char	*line = NULL;
	int	line_count;
	char	empty;
	char	obstacle;
	char	fill;
	char	newline;
	int	char_count = -1;

	int check =fscanf(stream, "%d%c%c%c%c", &line_count, &empty, &obstacle, &fill, &newline);
	if(check != 5 || newline != '\n')
		error(stream , line);
	if(empty == obstacle || empty == fill || obstacle == fill)
		error(stream , line);
	char ** map = calloc(line_count, sizeof(char *));
	if(! map)
		return ;
	for(int i = 0; i < line_count ; ++i){
		nread = getline(&line, &len, stream);
		if( char_count  == -1 )
			char_count = (int)nread;
		else if( char_count != (int)nread )
			error(stream , line);
		if(check_line_char(line, char_count, empty, obstacle, fill) == -1)
			error(stream , line);
		map[i] = calloc(char_count -1 , sizeof(char));
		if(!map[i]){
			ft_free(map, i);
			return;
		}
		for(int j = 0; j < char_count - 2; ++j)
			map[i][j] = line[j];
	}
	solve(map, empty, obstacle, fill, line_count, (char_count - 1));
	ft_free(map,0);
}

int main(int argc, char **argv){
	FILE	*stream;

	if(argc < 2)
		stream = stdin;
	else if (argc == 2)
		stream = fopen(argv[1], "r");
	else{
		fprintf(stderr ,"ERROR: Invalid Input\n");
		exit(EXIT_FAILURE);
	}
	if(stream == NULL){
		fprintf(stderr, "ERROR: Invalid Input\n");
		exit(EXIT_FAILURE);
	}
	getinput(stream);
	return 0;
}

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
	for(int i = 0; i < line_count ; ++i){
		nread = getline(&line, &len, stream);
		fprintf(stdout, "The length of the line is %zu\nthe line is %s", nread, line);
	}
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

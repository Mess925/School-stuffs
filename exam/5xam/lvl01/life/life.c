# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void ft_free(int i, char **str){
	while(i--){
		free(str[i]);
	}
	free(str);
}

int main(int ac, char **av){
	if(ac != 4)
	{
		printf("wrong usage\n");
		return -1;
	}
	int	width = atoi(av[1]);
	int	height = atoi(av[2]);
	int	iteration = atoi(av[3]);
	char 	c;
	char	**strr = malloc(sizeof(char*) * height);
	bool	pen =false;
	if(!strr)
		return -1;
	for(int i = 0 ; i < height; i++){
		strr[i] = malloc(sizeof(char) * (width + 1));
		if(!strr[i]){
			ft_free(i, strr);
			return 0;
		}
	}
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			strr[i][j] =' ';
		}
		strr[i][width] = '\0';
	}
	int	x = 0;
	int	y = 0;
	while(read(0,&c, 1) > 0){
		if( c == '\n')
			continue;
		if(c  == 'x'){
			pen = !pen;
		}
		else if(c == 'w'){
			if(y > 0)
				y--;
		}
		else if (c == 's'){
			if(y < height -1 )
				y++;
		}
		else if (c == 'a'){
			if( x > 0 )
				x--;
		}
		else if (c == 'd'){
			if(x < width -1 )
				x++;
		}
		else {
			ft_free(height, strr);
			printf("%c is not supposed to be here\n", c);
			return -1;
		}
		if(pen)
			strr[y][x] = '#';
	}
	for(int i = 0; i < height; i++){
		printf("%s\n", strr[i]);
	}
	ft_free(height, strr);
	(void) iteration;
	return 0;
}

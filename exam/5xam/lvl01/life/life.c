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

int aliveCount(char **str, int i, int j, int height, int width){
	int count = 0;
	for(int x = -1; x <= 1; x++){
		for(int y = -1; y <= 1; y++){
			if(x == 0 && y == 0){
				continue;
			}
			int newx = i + x;
			int newy = j + y;
			if(newy >= 0 && newy < widht && newx >= 0 && newx < height){
				if(str[newx][newy] == 'O')
					count++;
			}
		}
	}
	return count;
}

void	copy(char **dst, char **src, int height, int width){
	for(int i = 0; i <height ; i++){
		for(int j = 0; j < width; j++){
			dst[i][j] = src[i][j];
		}
		dst[i][width] = '\0';
	}
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
	char	**new = malloc(sizeof(char*) * height);
	bool	pen =false;
	if(!strr)
		return -1;
	for(int i = 0 ; i < height; i++){
		strr[i] = malloc(sizeof(char) * (width + 1));
		new[i] = malloc(sizeof(char) * (width + 1));
		if(!strr[i] || !new[i]){
			ft_free(i, new);
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
			ft_free(height, new);
			ft_free(height, strr);
			printf("%c is not supposed to be here\n", c);
			return -1;
		}
		if(pen)
			strr[y][x] = 'O';
	}
	while(iteration --){
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				int n = aliveCount(strr, i , j, height, width);	
				if(strr[i][j] == 'O'){
					if(n < 2)
						new[i][j] = ' ';
					else if ( n == 2 || n == 3 )
						new[i][j] = 'O';
					else
						new[i][j] = ' ';
				}
				else{
					if(n == 3){
						new[i][j] = 'O';
					}
					else{
						new[i][j] =' ';
					}
				}
			}
			new[i][width] = '\0';
		}
		copy(strr, new, height, width);
	}
	for(int i = 0; i < height; i++){
		printf("%s\n", strr[i]);
	}
	ft_free(height, strr);
	ft_free(height, new);
	return 0;
}

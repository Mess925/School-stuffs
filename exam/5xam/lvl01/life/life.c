# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int main(int ac, char **av){
	if(ac != 4)
		return -1;
	int	width = atoi(av[1]);
	int	height = atoi(av[2]);
	int	iteration = atoi(av[3]);
	char 	c;
	char	**strr = malloc(sizeof(char*) * width);
	if(!strr)
		return -1;
	for(size_t i = 0 ; i < width; i++){
		strr[i] = malloc(sizeof(char) * height);
		if(!strr[i]){
			while(i--){
				free(strr[i]);
			}
			free(strr);
		}
	}
	for(size_t i = 0; i < width; i++){
		for(size_t j = 0; j < height; j++){
			strr[i][j] ='a';
		}
	}
	for(size_t i = 0; i < width ; i++){
		printf("%s\n",strr[i]);
	}

	while(read(0,&c, 1)){
		if(c = 'x'){
		}
	}

	return 0;
}

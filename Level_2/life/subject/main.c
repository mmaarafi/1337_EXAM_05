#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac != 4)
		return (putchar('e'), 1);
	int width = atoi(av[1]), height = atoi(av[2]), iterations = atoi(av[3]);
	int array[2][width + 2][height + 2];
	for (int i = 0 ; i < 2; i++)
		for(int h = 0 ; h < (height + 2) ; h++)
			for(int w = 0 ; w < (width + 2) ; w++)
				array[i][w][h] = 0;

	int x = 1, y = 1, pen = 0;
	char cmd;
	while (read(0, &cmd, 1) > 0)
	{
		if (cmd == 'w' && y > 1)
			y--;
		else if (cmd == 'a' && x > 1)
			x--;
		else if (cmd == 's' && y < height)
			y++;
		else if (cmd == 'd' && x < width)
			x++;
		else if	(cmd == 'x')
			pen = !pen;
		if (pen)
			array[0][x][y] = pen;
	}
	for (int iter = 0 ; iter < iterations; iter++){
		for(int h = 1 ; h < (height + 1) ; h++){
			for(int w = 1 ; w < (width + 1) ; w++){
				int nb = 0;
				for (int x = -1; x <= 1; x++)
					for (int y = -1; y <= 1; y++)
						if (!(x == 0 && y == 0))
							nb += array[iter % 2][w + x][h + y];
				// printf("\n==========%d========\n", nb);
				if (array[iter % 2][w][h])
				{
					if (nb == 2 || nb == 3)
						array[(iter + 1) % 2][w][h] = 1;
					else
						array[(iter + 1) % 2][w][h] = 0;
				}
				else
				{
					if (nb == 3)
						array[(iter + 1) % 2][w][h] = 1;
					else
						array[(iter + 1) % 2][w][h] = 0;
				}
			}
		}
	}
	for(int h = 1 ; h < (height + 1) ; h++)
	{
		for(int w = 1 ; w < (width + 1) ; w++)
		{
			if (array[iterations % 2][w][h])
				printf("0");
			else
				printf(" ");
		}
		printf("\n");
	}
	// printf("====================\n");
	// for(int h = 1 ; h < (height + 1) ; h++)
	// {
	// 	for(int w = 1 ; w < (width + 1) ; w++)
	// 	{
	// 		if (array[1][w][h])
	// 			printf("0");
	// 		else
	// 			printf(" ");
	// 	}
	// 	printf("\n");
	// }
}

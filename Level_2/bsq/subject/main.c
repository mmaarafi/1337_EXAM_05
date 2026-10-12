#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
	int size;
} biggest_square;

typedef struct {
	int height;
	int width;
	char empty;
	char obstacle;
	char full;
	int map[1000][1000];
	biggest_square coordinate;
} parameters;


parameters param;

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}


int first_line_parse(FILE *fptr)
{
	char	*line = NULL;
	size_t	size = 0;
	int		return_value;
	int num = 0;
	int i;

	return_value = getline(&line, &size, fptr);
	// printf("return value : %d\n", return_value);
	if (return_value < 5)
		return 0;
	for (i = 0; line[i] >= '0' && line[i] <= '9'; i++)
		num = (num * 10) + (line[i] - '0');
	if (num < 1)
		return (0);
	param.height = num;
	param.empty = line[i++];
	param.obstacle = line[i++];
	param.full = line[i++];

	if (param.obstacle == param.empty || param.empty == param.full || param.full == param.obstacle)
		return (0);
	// printf("%d\n%c\n%c\n%c\n", param.height, param.empty, param.obstacle, param.full);
	if (line[i] != '\n')
		return (0);
	free(line);
	return (1);
}

int map_parsing(FILE *fptr)
{
	char	*line = NULL;
	size_t	size = 0;
	int line_length;
	int i;

	for (i = 0; i < param.height && getline(&line, &size, fptr) != -1 ; i++)
	{
		line_length = ft_strlen(line);
		if (line_length <= 1)
			return (free(line), 1);
		line[--line_length] = 0;
		if (i == 0)
			param.width = line_length;
		else
			if (line_length != param.width)
				return (free(line), 1);
		for (int x = 0; x < param.width; x++)
		{
			if (line[x] == param.empty)
				param.map[i][x] = 1;
			else if (line[x] == param.obstacle)
				param.map[i][x] = 0;
			else
				return (free(line), 1);
		}
	}
	if (i != param.height)
		return (free(line), 1);
	if (getline(&line, &size, fptr) != -1)
		return (free(line), 1);
	return (free(line), 0);
}

int min_3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void bsq()
{
	param.coordinate.size = 0;
	for (int i = 0; i < param.height; i++)
	{
		for (int j = 0; j < param.width; j++)
		{
			if (!param.map[i][j])
				continue ;
			else if(i == 0 || j == 0)
				param.map[i][j] = 1;
			else
				param.map[i][j] = min_3(param.map[i - 1][j], param.map[i - 1][j - 1], param.map[i][j - 1]) + 1;
			if (param.map[i][j] > param.coordinate.size)
			{
				param.coordinate.size = param.map[i][j];
				param.coordinate.x = j - param.map[i][j] + 1;
				param.coordinate.y = i - param.map[i][j] + 1;
			}
		}
	}
}

void print_bsq()
{
	int x_coordinate, y_coordinate, size;
	x_coordinate = param.coordinate.x;
	y_coordinate = param.coordinate.y;
	size = param.coordinate.size;
	for (int y = 0; y < param.height; y++)
	{
		for (int x = 0; x < param.width; x++)
		{
			if (x >= x_coordinate && x < (x_coordinate + size) && y >= y_coordinate && y < (y_coordinate + size))
				fprintf(stdout, "%c", param.full);
			else if (param.map[y][x] == 0)
				fprintf(stdout, "%c", param.obstacle);
			else
				fprintf(stdout, "%c", param.empty);
		}
		fprintf(stdout, "\n");
	}
}

void find_biggest_square(FILE *fptr)
{
	if (!first_line_parse(fptr))
	{
		fprintf(stdout, "invalid first line\n");
		return ;
	}
	if (map_parsing(fptr))
	{
		printf("im here\n");
		fprintf(stdout, "invalid map\n");
		return ;
	}
	bsq();
	print_bsq();
}

int main(int ac, char **av)
{
	if (ac == 1)
		find_biggest_square(stdin);
	if (ac == 2)
	{
		FILE *fptr = fopen(av[1], "r");
		if (!fptr)
		{
			fprintf(stdout, "Error: file not found\n");
			return 1;
		}
		find_biggest_square(fptr);
	}
	return (0);
}
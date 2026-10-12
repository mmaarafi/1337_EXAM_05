#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct {
	int x,y,size;
} coordinate;

typedef struct {
	char empty, obstacle, full;
	int height;
	int width;
	int map[1000][1000];
	coordinate xy;
} param;

param data;

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int parse_first_line(FILE *fptr)
{
	char *line = NULL;
	size_t size = 0;
	int i;
	int return_value = getline(&line, &size, fptr);
	if (return_value < 5)
		return (0);
	int res = 0;
	for (i = 0; line[i] >= '0' && line[i] <= '9'; i++)
		res = (res * 10) + (line[i] - '0');
	if (res == 0)
		return (0);
	data.height = res;
	data.empty = line[i++];
	data.obstacle = line[i++];
	data.full = line[i];
	if (line[++i] != '\n')
		return (0);
	return (1);
}

int parse_map(FILE *fptr)
{
	char *line = NULL;
	size_t size = 0;
	int i;

	for (i = 0; i < data.height && getline(&line, &size, fptr); i++)
	{
		int length = ft_strlen(line);
		if (length <= 1)
			return (0);
		if (line[--length] != '\n')
			return (0);
		line[length] = 0;
		if (i == 0)
			data.width = length;
		else
		{
			if (data.width != length)
				return (0);
		}
		for (int x = 0; x < data.width; x++)
		{
			if (line[x] == data.empty)
				data.map[i][x] = 1;
			else if (line[x] == data.obstacle)
				data.map[i][x] = 0;
			else
				return (0);
		}
	}
	if (i < data.height)
		return (free(line), 0);
	if (getline(&line, &size, fptr) != -1)
		return (free(line), 0);
	return (1);
}

int min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void bsq()
{
	data.xy.size = 0;
	for (int y = 0; y < data.height; y++)
	{
		for (int x = 0; x < data.width; x++)
		{
			if (data.map[y][x] == 0)
				data.map[y][x] = 0;
			else if (x == 0 || y == 0)
				data.map[y][x] = 1;
			else
				data.map[y][x] = min3(data.map[y - 1][x], data.map[y - 1][x - 1], data.map[y][x - 1]) + 1; 
			if (data.map[y][x] > data.xy.size)
			{
				data.xy.size = data.map[y][x];
				data.xy.x = x - data.xy.size + 1;	
				data.xy.y = y - data.xy.size + 1;	
			}
		}
	}
}

void print_bsq()
{
	for (int y = 0; y < data.height; y++)
	{
		for (int x = 0; x < data.width; x++)
		{
			if (x >= data.xy.x && x < (data.xy.x + data.xy.size) && y >= data.xy.y && y < (data.xy.y + data.xy.size))
				fprintf(stdout, "%c", data.full);
			else if (data.map[y][x] == 0)
				fprintf(stdout, "%c", data.obstacle);
			else
				fprintf(stdout, "%c", data.empty);
		}
		printf("\n");
	}
}

int find_biggest_square(FILE *fptr)
{
	if (!parse_first_line(fptr))
	{
		fprintf(stdout, "first line error\n");
		return (0);
	}
	if (!parse_map(fptr))
	{
		fprintf(stdout, "map parsing error\n");
		return (0);
	}
	bsq();
	print_bsq();
	return (1);
}

int main(int ac, char **av)
{
	FILE *fptr;

	if (ac == 1)
	{
		fptr = stdin;
		if (!fptr)
		{
			fprintf(stdout, "couldnt open file");
			return (1);
		}
	}
	else
	{
		fptr = fopen(av[1], "r");
		if (!fptr)
		{
			fprintf(stdout, "couldnt open file");
			return (1);
		}
	}
	if (!find_biggest_square(fptr))
	{
		fprintf(stdout, "map error\n");
			return (1);
	}
	return (0);
}

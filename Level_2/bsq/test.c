#include "stdio.h"
#include "stdlib.h"

enum
{
    EMPTY,
    OBSTACLE,
    FULL
};

typedef struct s_bsq
{
    int x;
    int y;
    int size;
}   t_bsq;


typedef struct s_data
{
    int x;
    int y;
    char empty, obstacle, full;
    t_bsq bsq;
    int map[1000][1000];
}   t_data;

int ft_strlen(char *line)
{
    int i = 0;
    while (line[i])
        i++;
    return i;
}


int get_num_line(char *line, int *i)
{
    int rs = 0;
    while(line[*i] >= '0' && line[*i] <= '9')
    {
        rs = rs * 10 + (line[*i] - '0');
        (*i)++;
    }
    return rs;
}

int parse_map(FILE *file, t_data *data)
{
    // char tmp;
    size_t len = 0;
    int y = 0, line_len = 0;
    char *line = NULL;
    // if (fscanf(file, "%d%c%c%c\n", &data->y, &data->empty, &data->obstacle, &data->full) != 4)
    //     return 1;
    if (getline(&line, &len, file) != -1)
    {
        int i = 0;
        data->y = get_num_line(line, &i);
        data->empty = line[i++];
        data->obstacle = line[i++];
        data->full = line[i];
    }
    // data->y = tmp - '0';
    // printf(" adsfasffdsff\n");
    // fprintf(stdin, "%d", data->y);
    if (data->y < 1)
        return 1;
    if (data->empty == data->obstacle || data->empty == data->full || data->full == data->obstacle)
        return 1;
    while (getline(&line, &len, file) != -1 && y < data->y)
    {
        line_len = ft_strlen(line);
        if (line[line_len - 1] == '\n')
            line[--line_len] = 0;
        if (line_len < 0)
        {
            free(line);
            return 1;
        }
        if (y == 0)
            data->x = line_len;
        else if (data->x != line_len)
        {
            free(line);
            return 1;
        }
        for (int x = 0; x < line_len; x++)
        {
            if (line[x] == data->empty)
                data->map[y][x] = EMPTY;
            else if (line[x] == data->obstacle)
                data->map[y][x] = OBSTACLE;
            else
            {
                free(line);
                return 1;
            }
        }
        y++;
    }
    free(line);
    // printf("%d %c %c %c  %d ", data->y, data->empty, data->obstacle, data->full, y);
    if (y != data->y)
        return 1;
    return 0;
}

int min3(int a, int b, int c)
{
    int small = a;
    if (b < small)
        small = b;
    if (c < small)
        small = c;
    return small;
}


void    print_map(t_data *data)
{
    for (int y = 0; y < data->y; y++)
    {
        for (int x = 0; x < data->x; x++)
        {
            if (data->map[y][x] == EMPTY)
                fprintf(stdout, "%c", data->empty);
            if (data->map[y][x] == OBSTACLE)
                fprintf(stdout, "%c", data->obstacle);
            if (data->map[y][x] == FULL)
                fprintf(stdout, "%c", data->full);
        }
        fputs("\n", stdout);
    }
}


void    bsq(t_data *data)
{
    int dp[1000][1000];
    for (int y = 0; y < data->y; y++)
    {
        for (int x = 0; x < data->x; x++)
        {
            if (data->map[y][x] == OBSTACLE)
                dp[y][x] = 0;
            else if (y == 0 || x == 0)
                dp[y][x] = 1;
            else
                dp[y][x] = 1 + min3(dp[y - 1][x], dp[y][x - 1], dp[y - 1][x - 1]);
            if (data->bsq.size < dp[y][x])
            {
                data->bsq.size = dp[y][x];
                data->bsq.y = y - dp[y][x] + 1;
                data->bsq.x = x - dp[y][x] + 1;
            }
        }

    }
    for (int y = 0; y < data->bsq.size; y++)
    {
        for (int x = 0; x < data->bsq.size; x++)
            data->map[y + data->bsq.y][x + data->bsq.x] = FULL;
    }
}

void    proccess_input(FILE *file)
{
    t_data data = {0};

    if (parse_map(file, &data))
    {
        fprintf(stdout, "Error: invalid map\n");
        return ;
    }
    bsq(&data);
    print_map(&data);
}



int main(int argc, char **argv)
{
    if (argc == 1)
    {
        proccess_input(stdin);
    }
    else if (argc == 2)
    {
        FILE *file;
        file = fopen(argv[1], "r");
        if (!file)
        {
            fprintf(stdout, "Error: file not found\n");
            return 1;
        }
        proccess_input(file);
        fclose(file);
    }
    return 0;
}
/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** load
*/

#include "solver.h"

char **clean_array(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            map[i][j] = map[i][j] == '\n' ? '\0' : map[i][j];
        }
    }
    return (map);
}

char **load_map(char *filepath)
{
    FILE *stream = fopen(filepath, "r");
    size_t size = 0;
    int i = 0;
    char *tab = NULL, **map;
    if (stream == NULL)
        exit(84);
    for (; getline(&tab, &size, stream) >= 0; i++);
    free(tab), tab = NULL;
    fclose(stream);
    stream = fopen(filepath, "r");
    map = malloc(sizeof(char *) * (i + 1));
    for (i = 0; getline(&tab, &size, stream) >= 0; i++) {
        map[i] = my_strdup(tab);
    } free(tab);
    map[i] = NULL;
    fclose(stream);
    return (map);
}
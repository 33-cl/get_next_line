/*
#include "get_next_line.h"

int main()
{
    size_t  i = 0;
    int fd = open("file", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    char *line;

//--------

    
    // while ((line = get_next_line(fd)) != NULL) {
    //     printf("x : %s", line);
    //     free(line);

    // }


//--------

    line = get_next_line(fd);
    printf("gnl   : %s", line);
    free(line);

    line = get_next_line(fd);
    printf("gnl   : %s", line);
    free(line);

    line = get_next_line(fd);
    printf("gnl   : %s", line);
    free(line);

    line = get_next_line(fd);
    printf("gnl   : %s", line);
    free(line);

    line = get_next_line(fd);
    printf("gnl   : %s", line);
    free(line);

    line = get_next_line(fd);
    printf("gnl   : %s", line);
    free(line);

    close(fd);

//---------

    return 0;
}
*/
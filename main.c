#include "get_next_line.h"

int main()
{

    int fd = open("fichier.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
/*
    char *line;
	printf("%s\n", line);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);

    }
    free(line);
    close(fd);
*/

	printf("gnl : %s\n", get_next_line(fd));
	printf("gnl : %s\n", get_next_line(fd));

    return 0;
}
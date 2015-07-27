#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "cumd.h"

int main(){
    int fd;
    char c = 0;
    cum_t *cum;

    fd = shm_open(CUM_PATH, O_RDONLY, 0);
    if (fd == -1){
        perror("open");
        return -1;
    }

    cum = mmap(NULL, sizeof(cum_t), PROT_READ, MAP_SHARED, fd, 0);
    if (!cum){
        perror("mmap");
        close(fd);
        return -1;
    }

    printf("Press ENTER to display data, or 'x' and ENTER to quit.\n");

    while(c != 'x'){
        printf("%f\n", cum->idle);
        c = getchar();
    }

    munmap(cum, sizeof(cum_t));
    close(fd);

    return 0;
}

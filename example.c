/*
 * -------------------------
 *  CPU Utilisation Monitor
 * -------------------------
 *  example.c
 * -----------
 *  Copyright (c) 2015 Citrix
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License only.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Please read the README file.
 */

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

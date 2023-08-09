#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <syslog.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]) {
    openlog("writer.c", LOG_CONS, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Error: Two arguments required!");
        closelog();
        return 1;
    }

    int fd = creat(argv[1], 0644);
    if (fd == -1) {
        syslog(LOG_ERR, "Error: Could not create or open file.");
        closelog();
        return 1;
    }


    ssize_t nr = write(fd, argv[2], strlen(argv[2]));
    if (nr == -1) {
        syslog(LOG_ERR, "Error: Could not write.");
        close(fd);
        closelog();
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
    close(fd);
    closelog();

    return 0;
}

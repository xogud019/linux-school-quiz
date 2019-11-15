#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	int fd;
	if (argc<2) {
		printf("usage with cmd\n");
		exit(1);
	}
	else {
		if (argc == 2) {
			if (!strcmp(argv[1], "exit")) {
				printf("program end\n");
				exit(1);
			}
			else if (argv[1] != '\0') {
				system(argv[1]);
				exit(1);

			}
		}//argc 2 end
		else if (argc == 3) {
			if (argv[1] != '\0' && !strcmp(argv[2], '&')) {
				if (fork() == 0) {
					execl("/bin/argv[1]", "argv[1]", "&", NULL);
					fprintf(stderr, "first failed\n");
					exit(1);
				}
			}

		}//argc 3end
		else if (argc == 4) {
			if (argv[1], argv[3] != '\0' && !strcmp(argv[2], '>')) {
				fd = open(argv[3], O_CREAT | O_TRUNC | O_WRONLY, 0600);
				system(argv[1]);
				dup2(1, fd);
				close(fd);
			}
			else if (argv[1], argv[3] != '\0' && !strcmp(argv[2], '<')) {
				fd = open(argv[3], O_RDWR, 0777);
				system(argv[1]);
				dup2(fd, 1);
				close(fd);
			}

		}//argc 4ed
		else if (argc == 5) {
			if (argv[1], argv[3], argv[5] != '\0' && !strcmp(argv[2], ';') && !strcmp(argv[4], ';')) {
				system(argv[1]);
				system(argv[3]);
				system(argv[5]);
			}
		}//else if argc 5 end


	}//else end
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 1024

char *GetNextString(char *cmd, char det, char *buf, char del);

static char line[MAX];
int main() {
	int fp;
	char buf[MAX];
	char *cmd;
	char *next;
	int input = 0;
	int first = 1;
	char exit[MAX] = "exit";
	do {
		printf("# : ");
		if (!fgets(line, sizeof(line), stdin)) {
			return 0;
		}


		cmd = line;

		if ((next = strchr(cmd, '|')) == NULL) {
			system(cmd);
		}
		else if ((next = strchr(cmd, '|')) != NULL) {
			system(cmd);
			cmd = GetNextString(cmd, '|', buf, ' ');
			system(cmd);

		}
		else if ((next = strchr(cmd, '&')) != NULL) {
			execl("bin/cmd", "cmd", "next", NULL);
		}//else if end
		else if ((next = strchr(cmd, '>')) != NULL) {
			system(cmd);
			cmd = GetNextString(cmd, '>', buf, ' ');
			fp = open(cmd, O_CREAT | O_TRUNC | O_WRONLY, 0600);
			dup2(1, fp);
			close(fp);
		}
		else if ((next = strchr(cmd, '<')) != NULL) {
			system(cmd);
			cmd = GetNextString(cmd, '>', buf, ' ');
			fp = open(cmd, O_RDWR, 0777);
			dup2(fp, 1);
			close(fp);
		}
	} while (strcmp(cmd, "exit"));
}

char *GetNextString(char *cmd, char det, char *buf, char del) {
	while (*a &&*a == d)  a++;
	while (*a &&*a != b) *c++ = *a++;
	*c = 0;

	if (*a == b) a++;
	return a;
}


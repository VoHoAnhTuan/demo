#include <stdio.h>
#include <string.h>

typedef enum{
	Info,
	Warning,
	Error
} log_type;

int main(){
	char buf[128] = {0};
	log_type type = Info;

	printf("Enter a message: ");
	fgets(buf,128,stdin);
	buf[strlen(buf) - 1] = 0;

	printf("Enter the log type (0-Info, 1-Warning, 2-Error): ");
	scanf("%d", (int *)&type);

	if (type == Info){
		printf("[Info] %s\n", buf);
	} else if (type == Warning){
		printf("[Warning] %s\n", buf);
	} else if (type == Error){
		printf("[Error] %s\n", buf);
	}
	return 0;
}
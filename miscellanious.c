#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c = 0, count = 0, count_tab = 0, count_blank = 0;
	while((c = getchar()) != EOF){
		if (c == ' '){
			++count;
		}
		if (c == '\t'){
			++count_tab;
		}
		if (c == '\n'){
			++count_blank;
		}
	}
	printf("%d %d %d\n", count, count_tab, count_blank);
	return 0;
}
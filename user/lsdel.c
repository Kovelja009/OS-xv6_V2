#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"


void moj_ls(char *path)
{
	char* result = (char *) malloc(64*(DIRSIZ+1));

	int n = lsdel(path, result);
	
	// if(n == -1)
	// 	fprintf(2, "lsdel: cannot open %s\n", path);
	// if(n == -2)
	// 	printf("probably init\n");
	// if(n == -3)
	// 	printf("closing lsdel\n");
	// if(n == -4)
	// 	fprintf(2, "lsdel: cannot stat %s\n", path);
	// if(n == -5)
	// 	printf("lsdel: can`t search trough %s!\n", path);
	// if(n == -6)
	// 	printf("lsdel: path too long\n");
	// if(n == -7)
		// printf("lsdel: argptr problem\n");
	if(n < 0)
		fprintf(2, "lsdel: can`t open %s\n", path);
	if(n == 0)
		printf("lsdel: nothing to recover from given directory\n");
	if(n > 0){
		for(int i = 0; i < n*(DIRSIZ+1); i+=DIRSIZ+1){
			for(int j = 0; j < DIRSIZ+1; j++){
				printf("%c", *(result+i+j));
			}
			printf("\n");
		}
	}

}


int
main(int argc, char *argv[])
{
	int i;

	if(argc < 2){
		moj_ls(".");
		exit();
	}
	for(i=1; i<argc; i++)
		moj_ls(argv[i]);
	exit();
}

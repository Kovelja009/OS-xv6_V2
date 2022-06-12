#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"


void recovery(char *path)
{
	int n = rec(path);

	switch (n)
	{
	case -1:
		printf("rec: %s is a nonexistent path!\n", path);
		break;
	case -2:
		printf("rec: file %s doesn`t exist on a given path!\n", path);
		break;
	case -3:
		printf("rec: Can`t recover %s. Inode has been reused!\n", path);
		break;
	case -4:
		printf("rec: Can`t recover %s. Some blocks have been reused!\n", path);
		break;
	default:
		printf("Successful recovery of %s\n", path);
		break;
	}
}


int
main(int argc, char *argv[])
{
	if(argc != 2){
		printf("rec format: rec <file_name>\n");
		exit();
	}
	recovery(argv[1]);
	exit();
}

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

#define BLOCK_SIZE 512

int
main(int argc, char *argv[])
{
	if(argc != 3){
		printf("Format: writer <file_name> <file_size>\n");
		exit();
	}
	int size = atoi(argv[2]);
	if(!size){
		printf("Illegal size argument!\n");
		exit();
	}
	
	int fd = open(argv[1], (O_CREATE | O_WRONLY));
	
	if(fd < 0){
		printf("writer: problem with fd!\n");
		exit();
	}

	char a[size + 1];
	for(int i = 0; i < size; i++){
		a[i] = i/BLOCK_SIZE + 'a';
	}
	a[size] = '\0';
	write(fd, a, size);
	close(fd);
	exit();
}

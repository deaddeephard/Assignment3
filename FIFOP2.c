#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int gy1;
        
	char* fifptr ="/tmp/myfifo";
	
	mkfifo(fifptr , 0666);
	
	char randstr[100] , ja[10];
	
	int idxcurr =1;
	
	while(idxcurr<50){
		memset(ja ,0,10);	
		gy1 =open(fifptr , O_RDONLY);
		read(gy1 , randstr , 100);

		printf("\nStrings have been recieved from P1\n%s", randstr);
		close(gy1);
		memset(randstr,0,100);	
		idxcurr +=5;
		char pak[5];
		sprintf(pak , "%d" ,idxcurr);
		strcpy(ja,pak);


		gy1 = open(fifptr , O_WRONLY);
		write(gy1 , ja , strlen(ja)+1);
		close(gy1);
		

	}

	return 0;
	
}


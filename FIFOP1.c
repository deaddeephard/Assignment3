#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

void generate(char randstr[][12]){
	srand (time(NULL));
	for(int i=0;i<=50;i++){
		for(int j=0;j<=9 ;j++){
			randstr[i][j] =rand() % 26 +65;
		}
	}
}



int main(){
	int gy;
	char* fifptr = "/tmp/myfifo";
	mkfifo(fifptr , 0666);
	char mid[51][12] ={{0}};
	generate(mid);
	
	char src[80] , dest[80];
		

	
	int idxcurr= 1;
	char aaja[5];
	char ja[100];
	
	while(idxcurr<=50){
		memset(ja , 0, 100);
		gy = open(fifptr , O_WRONLY);
	
		strcat(mid[idxcurr],"\n");
		
		for(int j= idxcurr+1 ; j<=idxcurr+4 ; j++){

			strcat(mid[idxcurr],mid[j]);
			strcat(mid[idxcurr] , "\n");
		}
		printf("\nStrings has been sent to Program p2\n");
		strcpy(ja , mid[idxcurr]);
		write(gy , ja , strlen(ja)+1);
		close(gy);
		gy = open(fifptr , O_RDONLY);
		
		read(gy , aaja , sizeof(aaja));
		idxcurr =atoi(aaja);

		printf("\n Max Index sent by P2 %d\n" , idxcurr-1);
	
		close(gy);
		memset(aaja , 0, 5);
	}
	return 0;
}


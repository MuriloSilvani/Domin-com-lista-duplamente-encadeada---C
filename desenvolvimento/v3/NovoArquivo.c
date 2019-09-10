#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
	
	int contDar = 28;
	
	while(contDar > 0){
		
		srand((unsigned)time(NULL));
		int randomValue = (rand() % contDar)+1;
		
		printf("%d\n",randomValue);

		contDar--;
	};

	
	
	
	
	return 0;
}
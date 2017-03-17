#include <stdio.h>


int DetInput(long long srt,long long stp, int bad);
int PerfectNumber(int number, int bad);

int main()
{
	long long start = 0,stop = 0; 
	int badness = 0, numofper,iter =0;
	int result[3]={0};

	scanf("%lld %lld %d",&start,&stop,&badness);


	while(DetInput(start,stop,badness)){

		numofper = 0;
		for(int i=start; i<=stop; i++){

			numofper += PerfectNumber(i, badness);
			
		}

		result[iter++] = numofper;
		scanf("%lld %lld %d",&start,&stop,&badness);
	}

	for(int i=0; i<iter; i++)
		printf("Test %d: %d\n",i+1,result[i]);

	return 0;
}

int DetInput(long long srt,long long stp, int bad)
{
	if(srt == 0 && stp == 0 && bad == 0)
		return 0;
	
	else
		return 1;

}

int PerfectNumber(int number,int bad)
{
	int remain = 1,a=0;
	int num = 0;
	for(num =2; num*num <number;num++){

		if(number%num == 0){
			remain += num;
			remain += number/num;
		}
	}

	if(num*num == number)
		remain += num;


	if(remain<=number+bad && remain >= number-bad)
		return 1;

	else
		return 0;
}

#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
//함수로 만들어보기.

int Calc_ans(int *x,int *y,int **a, int **b,int n);

int main()
{
	//clock_t before;
	//before = clock();
	//double result=0;
	int n,length = 0,max=0,x_max,y_max,k;

	scanf("%d",&n);

	length = n*n;
	int *xl = (int *)malloc(sizeof(int)*length);
	int *yl = (int *)malloc(sizeof(int)*length);


	int **bamboo = (int**)malloc(sizeof(int *)*n);
	int **bam = (int **)malloc(sizeof(int *)*n);
	for(int i=0; i<n;i++){
		*(bamboo+i) = (int *)malloc(sizeof(int)*n);  //대나무숲 
		*(bam+i) = (int *)malloc(sizeof(int)*n);
	}

	int **ans = (int**)malloc(sizeof(int *)*n);
	for(int i=0;i<n;i++){
		*(ans+i) = (int *)malloc(sizeof(int)*n); //결과값들 저장  
	}

	
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			scanf("%d",(*(bamboo+i)+j));  //숲 정보 입력  
		}
	}

	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			*(*(bam+i)+j) = *(*(bamboo+i)+j);  //숲 정보 복제 
		}
	}

	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			*(*(ans+i)+j) = 1;  //결과값 변수들 초기화
		}
	}


	//최대값들 탐색해서 순서대로 좌표값 저장.
	k = 0;
	while(k<length){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if( max < *(*(bamboo+i)+j) ){

					max = *(*(bamboo+i)+j);
					x_max = i;
					y_max = j;
				}
			}
		}
		*(xl+k) = x_max;
		*(yl+k) = y_max;
		*(*(bamboo+x_max)+y_max) = 0;
		max = 0;
		k++;
	}


	k = 0, max = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			*(*(ans+(*(xl+k)))+(*(yl+k))) = Calc_ans((xl+k),(yl+k),ans,bam,n);

			if( max <*(*(ans+(*(xl+k)))+(*(yl+k))))
				max = *(*(ans+(*(xl+k)))+(*(yl+k)));
			
			k++;
		}
	}


	printf("\n");

	printf("%d",max);
	printf("\n");


	for(int i=0; i<n;i++){
		free(*(bamboo+i));
		free(*(bam+i));
		free(*(ans+i));
	}
	free(bamboo);
	free(bam);
	free(ans);

	free(xl);
	free(yl);

	//result = (double)(clock()-before);
	//printf("걸린시간은 %5.2f입니다\n",result);

	return 0;
}


int Calc_ans(int *x,int *y,int **a,int **b,int n){

	int tmp = 0;
	if(*x==0){
		if(*y==0){
			if(*(*(b+(*x))+(*y)) < *(*(b+(*x)+1)+(*y))){
				if(tmp<*(*(a+(*x)+1)+(*y))){
					tmp = *(*(a+(*x)+1)+(*y));
				}
			}

			if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)+1)){
				if(tmp<*(*(a+(*x))+(*y)+1)){
					tmp = *(*(a+(*x))+(*y)+1);
				}
			}

		}
		else if((*y)==(n-1)){
			if(*(*(b+(*x))+(*y)) < *(*(b+(*x)+1)+(*y))){
				if(tmp<*(*(a+(*x)+1)+(*y))){
					tmp = *(*(a+(*x)+1)+(*y));
				}
			}

			if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)-1)){
				if(tmp<*(*(a+(*x))+(*y)-1)){
					tmp = *(*(a+(*x))+(*y)-1);
				}
			}

		}
		else{
			if(*(*(b+(*x))+(*y)) < *(*(b+(*x)+1)+(*y))){
				if(tmp<*(*(a+(*x)+1)+(*y))){
					tmp = *(*(a+(*x)+1)+(*y));
				}
			}

			if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)-1)){
				if(tmp<*(*(a+(*x))+(*y)-1)){
					tmp = *(*(a+(*x))+(*y)-1);
				}
			}

			if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)+1)){
				if(tmp<*(*(a+(*x))+(*y)+1)){
					tmp = *(*(a+(*x))+(*y)+1);
				}
			}

		}
	}

	else if((*x)== (n-1)){
		if((*y)==0){
			if(*(*(b+(*x))+(*y)) < *(*(b+(*x)-1)+(*y))){
				if(tmp<*(*(a+(*x)-1)+(*y))){
					tmp = *(*(a+(*x)-1)+(*y));
				}
			}

			if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)+1)){
				if(tmp<*(*(a+(*x))+(*y)+1)){
					tmp = *(*(a+(*x))+(*y)+1);
				}
			}

		}
		else if((*y)== (n-1)){
			if(*(*(b+(*x))+(*y)) < *(*(b+(*x)-1)+(*y))){
				if(tmp<*(*(a+(*x)-1)+(*y))){
					tmp = *(*(a+(*x)-1)+(*y));
				}
			}

			if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)-1)){
				if(tmp<*(*(a+(*x))+(*y)-1)){
					tmp = *(*(a+(*x))+(*y)-1);
				}
			}

		}
		else{
			if(*(*(b+(*x))+(*y)) < *(*(b+(*x)-1)+(*y))){
				if(tmp<*(*(a+(*x)-1)+(*y))){
					tmp = *(*(a+(*x)-1)+(*y));
				}
			}

			if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)-1)){
				if(tmp<*(*(a+(*x))+(*y)-1)){
					tmp = *(*(a+(*x))+(*y)-1);
				}
			}

			if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)+1)){
				if(tmp<*(*(a+(*x))+(*y)+1)){
					tmp = *(*(a+(*x))+(*y)+1);
				}
			}

		}
	}

	else if((*y)==0){
		if(*(*(b+(*x))+(*y)) < *(*(b+(*x)-1)+(*y))){
			if(tmp<*(*(a+(*x)-1)+(*y))){
				tmp = *(*(a+(*x)-1)+(*y));
			}
		}

		if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)+1)){
			if(tmp<*(*(a+(*x))+(*y)+1)){
				tmp = *(*(a+(*x))+(*y)+1);
			}
		}

		if(*(*(b+(*x))+(*y)) < *(*(b+(*x)+1)+(*y))){
			if(tmp<*(*(a+(*x)+1)+(*y))){
				tmp = *(*(a+(*x)+1)+(*y));
			}
		}

	}
	else if((*y)==(n-1)){
		if(*(*(b+(*x))+(*y)) < *(*(b+(*x)-1)+(*y))){
			if(tmp<*(*(a+(*x)-1)+(*y))){
				tmp = *(*(a+(*x)-1)+(*y));
			}
		}

		if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)-1)){
			if(tmp<*(*(a+(*x))+(*y)-1)){
				tmp = *(*(a+(*x))+(*y)-1);
			}
		}

		if(*(*(b+(*x))+(*y)) < *(*(b+(*x)+1)+(*y))){
			if(tmp<*(*(a+(*x)+1)+(*y))){
				tmp = *(*(a+(*x)+1)+(*y));
			}
		}

	}
	else{
		if(*(*(b+(*x))+(*y)) < *(*(b+(*x)-1)+(*y))){
			if(tmp<*(*(a+(*x)-1)+(*y))){
				tmp = *(*(a+(*x)-1)+(*y));
			}
		}

		if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)-1)){
			if(tmp<*(*(a+(*x))+(*y)-1)){
				tmp = *(*(a+(*x))+(*y)-1);
			}
		}

		if(*(*(b+(*x))+(*y)) < *(*(b+(*x)+1)+(*y))){
			if(tmp<*(*(a+(*x)+1)+(*y))){
				tmp = *(*(a+(*x)+1)+(*y));
			}
		}

		if(*(*(b+(*x))+(*y)) < *(*(b+(*x))+(*y)+1)){
			if(tmp<*(*(a+(*x))+(*y)+1)){
				tmp = *(*(a+(*x))+(*y)+1);
			}
		}
	}
	tmp += *(*(a+(*x))+(*y));
	return tmp;

}



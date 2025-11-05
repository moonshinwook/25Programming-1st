#include "Sample.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Selectjob(JOB* myJOBPtr)
{
	int input = 0;

	printf("종족을 선택하세요 (0 : , 1 : 2 : \n");
	scanf("%d", &input);

	*myJOBPtr = input;
	JOB tempjob = *myJOBPtr;

	if (tempjob == WARRIOR)
	{
		printf("당신의 직업은 전사입니다.\n");
	}

	else if (tempjob == WARRIOR)
	{
		printf("당신의 직업은 전사입니다.\n");
	}


	else
	{
		printf("잘못된 입력을 하였습니다.\n");
	}

	//printf("전사 = 0, 도적 = 1를 누르세요 : \n");
	//scanf("%d", &input);
	//if(job == WARRIOR)
	//{ 
	//	printf("당신의 직업은 전사입니다. \n"); 
	//}
	//else if (job == THIEF)
	//{
	//	printf("당신의 직업은 도적입니다. \n");
	//}


}
void SetplayerStat(JOB selcectJob, int* hpPtr, int* atkPtr)
{
	// JOB 열거형을 사용하여 각 직업별 스탯을 설정해보세요.

	switch(selcectJob)
	{
		case WARRIOR:
			*hpPtr = 10;
			*atkPtr = 5;
			break;
		case THIEF:
			*hpPtr = 3;
			*atkPtr = 10;
			break;
		case WIZARD:
			*hpPtr = 3;
			*atkPtr = 10;
			break;
		default:
				printf("정의된 직업이 없습니다.\n");
				break;
	}

}
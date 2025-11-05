#pragma once

#ifndef JOB_H // JOB_H가 정의가 안되어있다면 밑의 구조체를 이용해라

#define JOB_H // define

typedef enum JOB
{
	WARRIOR,
	THIEF,
	WIZARD,
	JOBUNDEFINED 



}JOB;

#endif // !1

void Selectjob(JOB* myJOBPtr);

void SetplayerStat(JOB selcectJob, int* hpPtr, int* atkPtr);
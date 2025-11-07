#pragma once

#ifndef JOB_H // JOB_H가 정의가 안되어있다면 밑의 구조체를 이용해라

#define JOB_H // define

typedef enum JOB
{
	UNDEFINED,
	WARRIOR,
	THIEF


}JOB;

#endif // !1


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // 함수 사용을 위한 헤더
#include <time.h> // 컴퓨터 난수 설정을 위한 헤더

// 함수 선언
void SetplayerStat(JOB selcetCharacter, int* baseHPptr, int* baseATKptr); // 타입에 대한 선언이 없었음. -> JOB, int*, int*에 대한 타입 붙여줌. -> 붙이지 않은 경우 포인터활용 의미 없음.
void StartBattle(); // 스테이지 1 시작



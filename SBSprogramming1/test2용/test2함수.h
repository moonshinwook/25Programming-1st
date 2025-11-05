#pragma once

#ifndef JOB_H // JOB_H가 정의가 안되어있다면 밑의 구조체를 이용해라

#define JOB_H // define

typedef enum JOB
{
	WARRIOR,
	THIEF,
	UNDEFINED
	



}JOB;

#endif // !1


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // 함수 사용을 위한 헤더
#include <time.h> // 컴퓨터 난수 설정을 위한 헤더

// 함수 선언
void StartCharacterchoice(); // 시작캐릭터 선택
void StartBattle(); // 스테이지 1 시작
void SetplayerStat(myJOB, baseHPptr, baseATKptr);


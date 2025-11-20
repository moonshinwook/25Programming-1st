#pragma once
#include <stdbool.h>

#ifndef JOB_H // JOB_H가 정의가 안되어있다면 밑의 구조체를 이용해라

#define JOB_H // define

// 중독 구조체
typedef struct {
	bool debuffed;
	int remainTurn;
	int damage;
}Debuff;

typedef enum JOB
{
	UNDEFINED,
	WARRIOR,
	THIEF


}JOB;

#endif // !1

//typedef struct STAGE1ENEMY // 산적1  체력, 공격력, 방어력 구조체
//{
//	ENEMY1 Enemy1;
//	ENEMY2 Enemy1;
//	BOSS Enemy1;
//
//}STAGE1ENEMY;  // 아직 한 번에 묶을 이유가 있는지 몰라서 보류

typedef struct ENEMY // 산적1  체력, 공격력, 방어력 구조체
{
	int hp;
	int atk;
	int def;
}ENEMY;



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // 함수 사용을 위한 헤더
#include <time.h> // 컴퓨터 난수 설정을 위한 헤더
#include <stdbool.h> 

// 함수 선언
void SetplayerStat(JOB selcetCharacter, int* baseHPptr, int* baseATKptr, int* baseDEFptr, int *baseCTRptr, int* basePOISONptr); // 타입에 대한 선언이 없었음. -> JOB, int*, int*에 대한 타입 붙여줌. -> 붙이지 않은 경우 포인터활용 의미 없음.
void StartBattle(JOB selcetCharacter, int* baseHPptr, int* baseATKptr, int* baseDEFptr, int *baseCTRptr, int* basePOISONptr); // 스테이지 1 시작
void StageReward(ENEMY Enemy1, int* baseHPptr, int* baseATKptr); // 스테이지 클리어 보상




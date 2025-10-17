/*
* 날짜	: 2025 - 10 - 16
* 학습목표 : 자료형과 변수
* 실습목표 : 실제 게임을 분석해서 자료형을 이해한다.
*/

// 자료형 Data Type
// Data : 숫자, 그림, 기호 정의되어 있지 않은 정보들
// 컴퓨터에게 명령을 내리고 싶다. 
// 더블킬(문자),	킬수 스코어 정보(소숫점이 없는 숫자 = 정수), 스탯 정보(소숫점이 있는 숫자 = 소수)
// 이미지 1920 x 1080, 소리(파장)

// 자료들의 특징에 따라서 형태를 분류를 했다. Type 
// 자료형 : 문자, 정수, 실수, 

// 자료형을 이용하는 방법
// (어떤 타입) "이름" variable 변수
// 함수를 사용하는 방법
// int :정수를 표현하는 타입
// flaot :실수
// char :문자 "H e l l o" 
// string 문자열

#include <stdio.h>

int main()
{
	// 더블킬 게임 화면에 출력하고 싶다. 
	printf("더블킬 \n"); 
	// 레드팀과 블루팀의 스코어를 출력하고 싶다. 
	printf("10 vs 25\n");
	// 챔피언이 가지고 있는 스탯을 화면에 출력하고 싶다. 
	int level = 18;

	int GarenfirstLevelHP = 690; 
	float GarengrowthHP = 98;
	int GarenfirstLevelMP = 0;
	float GarengrowthMP = 0;
	int Garenfirstatteck = 69;
	float Garengrowthatteck = 4;
	float Garrenfirstatteckspeed = 0.625;
	float Garrengrowthatteckspeed = 3.65;
	int GarenfirstHealthrecoveryper5seconds = 5;
	float GarenfirstgrowthHealthrecoveryper5seconds = 0;




	// %d, %s 

	printf(" 가렌의 1렙 스탯 정보 \n");
	printf(" AD : 10 \n ");
	printf(" 체력 : %f \n", GarenfirstLevelHP + (level - 1) * GarengrowthHP);
	printf(" 현재 체력 : %f \n", GarenfirstLevelHP + (level - 1) * GarengrowthHP);
	printf(" 현재 마나 : %f \n ", GarenfirstLevelMP + (level - 1) * GarengrowthMP);
	printf(" 공격력 : %f \n", Garenfirstatteck + (level - 1) * Garengrowthatteck);		//69 + 4(현재레벨 - 1)
	printf(" 공격 속도 : %f \n", Garrenfirstatteckspeed +(level - 1) * Garrengrowthatteckspeed / 100);
	printf(" 5초당 체력회복 : %f \n", GarenfirstHealthrecoveryper5seconds + (level - 1) * GarenfirstgrowthHealthrecoveryper5seconds);
	printf(" 5초당 마나회복 : 0 \n");
	printf(" 방어력 : 38 (+4) \n");
	printf(" 마법 저항력 : 32 (+1) \n");
	printf(" 이동속도 : 340 \n");
	printf(" 사정거리 : 175 \n"); 

	// 이 정보를 컴퓨터가 내가 원하는 결과값으로 실행을 했나요? 
	// 만족 vs 조금 더 해야한다. 

	// 문제1. 5레벨일 때의 가렌의 정보는 어떻게 되나요? 

	// 문제2. 다른 챔피언으로도 위의 방식으로 정보를 표현해보세요. 


	// 문제3. 분석해보고 싶은 게임의 정보를 하나 가져옵니다. 
	// 수식 표현 

	// 실습. 리그오브레전드 공식. 

	// 이차 함수를 공식으로 사용하는 하나의 예제 
	// 게임에서 사용할 수 있는 예제 고민 
	// 앵그리버드 속 포물선 운동(단순 포물선 운동)

	// step 1~10
	// step1 캐릭터의 발사 위치 값은 (0,0)으로 원점 
	// step2 위치값의 변화는 a,b 변수값의 변화에 따라 달라짐
	// step3 a, b의 값은 정수값으로 표현하여 단순화
	// 
	// Result
	// printf
	// 
	

	// 경험치 : 
	// 미니언 처치 : 경험치 획득 일정
	// 레벨		:	레벨이 높을수록 경험치를 적게 획득시켜야 한다. 


	// 미니언의 경험치를 시간이 지날수록 적게 주게 할까? 
	// -> 챔피언을 죽였는데도 경험치를 준다. 게임의 성질. 

	// 경험치를 갈수록 크게 획득해야 하면 경험치 요구량을 크게 하게 하자.
	// 어떤 방식으로 크게 할까요? 공식으로 게임을 만들면 변수 조정만으로 바뀔 수 있지만 MagicNumber의 경우에는 노가다 필요.
	// 1레벨 10 2레벨 30 3레벨 60 4레벨 MagicNumber(일종의 때려맞치기)
	// step 1 ~ 10

	// 유저의 피드백 10레벨이 밸런스에 대한 혹평 <- 10레벨 어떻게 처리하지..
	// 10레벨 Debug -> 무엇이 의도한 내용과 달랐는가? 

	//디버깅에서 중단점은 매우 중요!! 중단점을 많이 찍어보기(이유를 토대로)

}
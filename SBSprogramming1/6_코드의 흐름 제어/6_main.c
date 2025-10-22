// 2025-10-22
// 가위 바위 보
// 실습 목표 : 다른 미니 게임 직접 설계하고 코드를 작성해보는 것

#include <stdio.h>
#include <stdbool.h>

// (1)가위 바위 보 게임을 한글로 표현해보세요
// - 유저, 컴퓨터,  
// 가위, 바위, 보 중에서 하나를 선택해주세요. 
// 결과 : 컴퓨터가 무엇을 냈는가 따라서 결과가 달라진다. 

/*
*  프로그램 혼자서 작성할 때 권장하는 순서
*  1. 한글로 먼저 어떤 것을 구현할 지 주석으로 표현해보세요.
*  2. 한글로 표현한 내용을 컴퓨터에게 어떻게 명령할지 직접 작성을 해보세요.
*  2-1. 특별한 문법, 헤더를 가져와서 사용한다, 오류가 나는 부분
*  2-2. 출력을 해서 결과를 성공시켜보기
*/

/*
*  유저가 승리하면 유저의 점수가 1점 증가, 컴퓨터가 승리하면 컴퓨터의 점수를 1점 증가시키세요.
*  반복해서 사용하고 싶다. 유저가 승리하면 유저의 점수가 1점 증가, 컴퓨터가 승리하면 컴퓨터의 점수를 1점 증가시키세요.
*
*  버그가 있는 것 같다. 컴퓨터가 무엇을 냈는지 알고 싶다. <- 반영. 컴퓨터와 플레이어의 행동을 추력하는 코드를 만들어보세요.
*  Hint -> playerChoice, computerChoice가 보이도록 해야한다.
*/

/*
*  스팀 게임 levelup system
*/

/*
*  숫자 맞추기 게임
*/

/*
*  가위바위보게임을 완성하기 위해 필요한 구현 사항
*  1. 유저의 입력 기능이 없다.
*  2. 컴퓨터가 정해진 결과만 출력합니다 -> 랜덤성 부여
*  3. 스코어. => 반복. 3점 먼저 취득하면 승리한다. -> 점수가 아닌 생명력으로 ?
*  4. 아이템 부여, 3스테이지마다 아이템은 3가지 중 택일 
*  5. 캐릭터 종류 2가지, 각자 능력 가지고 있음 
*  6. 
*  7. 스테이지 10까지 BOSS 존재 
*  8. BOSS는 이기면 생명력 2개 까임.
*  앞으로 남은 작업 리스트.
*  -> 당장 구현할 수 있는 순위
*/

int main()
{
	// 조건문 출력 테스트 
	// 세미클론 명령이 끝이 났다.
	bool value = 5 < 3; // 참이면 value, 숫자가 0이면 조건이 거짓이다, 숫자가 1이면 조건이 참이다. -> 참이면 실행 거짓이면 실행x

	// if(); 세미클론을 넣지마세요


	if (true) // 참이면 실행 거짓이면 실행x, '==' 이 같다 '!=' 같지 않다
	{
		printf("조건이 실행되었다!\n");//실행할 내용
	}


	printf("가위 바위 보 게임!\n");

	// 플레이어가 선택한 결과를 저장
	// 1. 가위 2. 바위 3. 보 (임의의 약속) 
	int playerChoice = 1; // 플레이어는 가위를 선택했습니다. 
	int computerChoice = 1; // 컴퓨터도 가위를 선택했습니다. 
	int playerScore = 0;
	int compueterScore = 0;
	// 가위 -> 이겼다, 비겼다, 졌다.
	// 조건 - 가위 -> 보  "1" -> "3" 
	// 조건 - 가위 -> 가위 "1" -> "1" 
	// 조건 - 가위 -> 바위 "1" -> "2" 

	if (playerChoice == 1 && computerChoice == 3) // && AND조건
	{
		// 실제로 유저의 점수를 1점 증가시키는 것 -> playerScore
		playerScore = playerScore + 1;
		printf("유저가 승리했습니다.\n");
	}
	else if (playerChoice == 1 && computerChoice == 1)
	{
		printf("유저가 비겼습니다.\n");

	}
	else if (playerChoice == 1 && computerChoice == 2)
	{
		compueterScore = compueterScore + 1;
		printf("유저가 패배했습니다.\n");
	}
	else
	{
		// computerChoice값이 0보다 작거나 같거나, 3보다 큰 경우
		if (computerChoice <= 0 && computerChoice > 3)
			printf("예외가 발생했습니다\n");
	}

	// 플레이어가 바위 -> 
	if (playerChoice == 2 && computerChoice == 1) // && AND조건
	{
		playerScore = playerScore + 1;
		printf("유저가 승리했습니다.\n");
	}
	else if (playerChoice == 2 && computerChoice == 2)
	{
		printf("유저가 비겼습니다.\n");

	}
	else if (playerChoice == 2 && computerChoice == 3)
	{
		compueterScore = compueterScore + 1;
		printf("유저가 패배했습니다.\n");
	}
	else
	{
		// computerChoice값이 0보다 작거나 같거나, 3보다 큰 경우
		if (computerChoice <= 0 && computerChoice > 3)
			printf("예외가 발생했습니다\n");
	}

	// 플레이어가 보 -> 
	if (playerChoice == 3 && computerChoice == 2)
	{
		playerScore = playerScore + 1;
		printf("유저가 승리했습니다.\n");
	}
	else if (playerChoice == 3 && computerChoice == 3)
	{
		printf("유저가 비겼습니다.\n");

	}
	else if (playerChoice == 3 && computerChoice == 1)
	{
		compueterScore = compueterScore + 1;
		printf("유저가 패배했습니다.\n");
	}
	else
	{
		// computerChoice값이 0보다 작거나 같거나, 3보다 큰 경우
		if (computerChoice <= 0 && computerChoice > 3)
			printf("예외가 발생했습니다\n");
	}

	//if ((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) || (playerChoice == 3 && computerChoice == 2))
	//{
	//	printf("playerPoint : %d", +1);
	//}

	// 플레이어의 선택 출력

	const char* playerCharacter = "가위";		// 문자를 저장할 수 있는 변수, 포인터
	const char* computerCharacter = "보";		// 

	if (playerChoice == 1)
	{
		playerCharacter = "가위";
	}
	else if (playerChoice == 2)
	{
		playerCharacter = "바위";
	}
	else if (playerChoice == 3)
	{
		playerCharacter = "보";
	}

	if (computerCharacter == 1)
	{
		computerCharacter = "가위";
	}
	else if (computerCharacter == 2)
	{
		computerCharacter = "바위";
	}
	else if (computerCharacter == 3)
	{
		computerCharacter = "보";
	}

	printf("숫자 1 = 가위, 숫자 2 = 바위, 숫자 3 = 보\n");
	if (playerChoice == 1)
		printf("플레이어의 선택 = %s, 컴퓨터의 선택 : %s\n", playerCharacter, computerCharacter);
	if (playerChoice == 2)
		printf("플레이어의 선택 = %d, 컴퓨터의 선택 : %d\n", playerCharacter, computerCharacter);
	if (playerChoice == 3)
		printf("플레이어의 선택 = %d, 컴퓨터의 선택 : %d\n", playerCharacter, computerCharacter);

	// 플레이어의 점수 vs 컴퓨터의 점수 출력 
	//printf("당신의 점수 : %d\n", playerScore);  스스로 작성해본 것
	//printf("컴퓨터의 점수 : %d\n", compueterScore); 스스로 작성해본 것
	printf("플레이어의 점수 : %d vs 컴퓨터의 점수 : %d\n", playerScore, compueterScore);


}
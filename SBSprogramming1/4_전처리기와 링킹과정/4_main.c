/*
*		날짜		: 2025-10-20
* 학습목표		: 헤더 파일을 생성하고 링킹 과정을 이해한다.
*/


#include <stdio.h> // 이름으로 생각. include : 포함하다. std + i + o .h
#include "GameInfo.h" // 어떻게 이 파일에 해당 경로에 있는지 아나요.
#include "4_main.h"

// 표준 입출력의 머리 정보가 담겨있는 코드를 포함하세요. 
// #include 헤더를 명시해줘야한다.
// 전처리기 : 프로그램이 시작되기 전에 실행하라. 
// why? 프로그램이 시작되기 전에 실행하라.
// 컴퓨터 어딘가에 설치되어있는 windows kit 생성된 코드를 가져와서 사용하고 싶다. 
// Copy Paste 복사 붙여넣기.

// 컴퓨터의 입력을 받는 코드가 필요하다 => 구현해놓은 헤더 파일을 참조해야겠구나.
// 컴퓨터에게 입력을 감지하는 코드가 필요하다 => AI 코드를 작성. #include < > ...

/*
*  #include <이름.h> : 시스템 폴더에서 파일을 찾는다. 
*  #include "이름.h"	: 프로젝트 안에서 파일을 찾는다. 
*/

// 콘솔 커서의 위치를 설정하는 함수
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() 
{

    update();
    Rendering();
    Buffering();



    return KeyboardMove(); // 프로그램이 어떻게 실행이 되는지 분할하는 것이 좋다.  
}

int KeyboardMove()
{

    /*printf("최 대 발사 가능한 총알수 : %d\n", BulletMaxCount);*/




    int x = 10, y = 10;
    int key;

    // 프로그램 시작 시 커서를 숨김
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    // 콘솔 화면을 지움
    system("cls");

    while (1) {
        // 이전 위치의 문자(' ')를 지움
        gotoxy(x, y);
        printf(" ");

        // 키 입력을 대기
        key = _getch();

        // 특수 키(방향키) 입력은 두 번의 `_getch()` 호출이 필요
        if (key == 224 || key == 0) {
            key = _getch();
            switch (key) {
            case 72: // 위쪽 화살표
                y--;
                break;
            case 80: // 아래쪽 화살표
                y++;
                break;
            case 75: // 왼쪽 화살표
                x--;
                break;
            case 77: // 오른쪽 화살표
                x++;
                break;
            }
        }

        // 'q' 키를 누르면 종료
        if (key == 'q') {
            break;
        }

        // 새 위치에 문자('@')를 그림
        gotoxy(x, y);
        printf("@");
    }

    // 프로그램 종료 시 커서를 다시 보이게 함
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    system("cls"); // 화면을 깨끗하게 정리

    return 0;
}


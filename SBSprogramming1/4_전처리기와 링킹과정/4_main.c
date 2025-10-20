/*
*		��¥		: 2025-10-20
* �н���ǥ		: ��� ������ �����ϰ� ��ŷ ������ �����Ѵ�.
*/


#include <stdio.h> // �̸����� ����. include : �����ϴ�. std + i + o .h
#include "GameInfo.h" // ��� �� ���Ͽ� �ش� ��ο� �ִ��� �Ƴ���.
#include "4_main.h"

// ǥ�� ������� �Ӹ� ������ ����ִ� �ڵ带 �����ϼ���. 
// #include ����� ���������Ѵ�.
// ��ó���� : ���α׷��� ���۵Ǳ� ���� �����϶�. 
// why? ���α׷��� ���۵Ǳ� ���� �����϶�.
// ��ǻ�� ��򰡿� ��ġ�Ǿ��ִ� windows kit ������ �ڵ带 �����ͼ� ����ϰ� �ʹ�. 
// Copy Paste ���� �ٿ��ֱ�.

// ��ǻ���� �Է��� �޴� �ڵ尡 �ʿ��ϴ� => �����س��� ��� ������ �����ؾ߰ڱ���.
// ��ǻ�Ϳ��� �Է��� �����ϴ� �ڵ尡 �ʿ��ϴ� => AI �ڵ带 �ۼ�. #include < > ...

/*
*  #include <�̸�.h> : �ý��� �������� ������ ã�´�. 
*  #include "�̸�.h"	: ������Ʈ �ȿ��� ������ ã�´�. 
*/

// �ܼ� Ŀ���� ��ġ�� �����ϴ� �Լ�
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() 
{

    update();
    Rendering();
    Buffering();



    return KeyboardMove(); // ���α׷��� ��� ������ �Ǵ��� �����ϴ� ���� ����.  
}

int KeyboardMove()
{

    /*printf("�� �� �߻� ������ �Ѿ˼� : %d\n", BulletMaxCount);*/




    int x = 10, y = 10;
    int key;

    // ���α׷� ���� �� Ŀ���� ����
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    // �ܼ� ȭ���� ����
    system("cls");

    while (1) {
        // ���� ��ġ�� ����(' ')�� ����
        gotoxy(x, y);
        printf(" ");

        // Ű �Է��� ���
        key = _getch();

        // Ư�� Ű(����Ű) �Է��� �� ���� `_getch()` ȣ���� �ʿ�
        if (key == 224 || key == 0) {
            key = _getch();
            switch (key) {
            case 72: // ���� ȭ��ǥ
                y--;
                break;
            case 80: // �Ʒ��� ȭ��ǥ
                y++;
                break;
            case 75: // ���� ȭ��ǥ
                x--;
                break;
            case 77: // ������ ȭ��ǥ
                x++;
                break;
            }
        }

        // 'q' Ű�� ������ ����
        if (key == 'q') {
            break;
        }

        // �� ��ġ�� ����('@')�� �׸�
        gotoxy(x, y);
        printf("@");
    }

    // ���α׷� ���� �� Ŀ���� �ٽ� ���̰� ��
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    system("cls"); // ȭ���� �����ϰ� ����

    return 0;
}


// ������Ʈ 
// �α׶���ũ ���� ���� 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // �Լ� ����� ���� ���
#include <time.h> // ��ǻ�� ���� ������ ���� ���

// �÷��̾�� ���� ���¸� �����ϴ� ����ü

// �Լ� ����
void StartBattle();
void Characterchoice();
int main() {
    char RestartChoice;
    int Characterchoice = 0;

    // ���� ������� ���� while ����
    while (1) {
        printf("==================================\n");
        printf("          �α׶���ũ �������\n");
        printf("==================================\n");

        StartBattle(); // ���� ����
        Characterchoice(); E0109

        printf("������ �ٽ� �����Ͻðڽ��ϱ�? : (Y / N)  ");
        scanf(" %c", & RestartChoice);

        // �Է� ���� ���� (���� �Է¿� ���� ������)
        int c;
        while ((c = getchar()) != '\n' && c != EOF); //EOF -> ������ �� ǥ��: ���α׷��� ������ ���������� �о�� �� �� �̻� ���� �����Ͱ� ���ٴ� ���� �˷��ִ� ����
                                                                                // != ���� �ʴ�.

        // 'y'�� 'Y'�� �ƴϸ� ���� ����
        if (RestartChoice != 'y' && RestartChoice != 'Y') {
            break;
        }
    }

    printf("\n������ �����մϴ�. �����մϴ�!\n");
    return 0;
}


// ������ �����մϴ�!
// ���� ���� ���ĳ�������.
// ĳ���͸� �����Ͻÿ�. 
// ���� = 1, ���� = 2�� �������� 
// ����
// ���� = 1, ���� ���� = 2,  ��� = 3
// ����
// ���� = 1, ��Į ���� = 2, ȸ�� = 3

// ĳ���� ���� �Լ�
void Characterchoice(){
printf("ö�� =1, ���� = 2�� �������� : \n");
scanf("%d", &Characterchoice);

if (Characterchoice == 1)
{
    printf(" ����� ö���Դϴ�. ü�� ������(30) ���ݷ� 10\n\n");
   
}
else if (Characterchoice == 2)
{
    printf(" ����� �����Դϴ�. ü�� ����(20) ���ݷ� 15\n\n");
    
}
else
{
    printf(" 1 �Ǵ� 2 �� �Է����ּ���.\n\n");
}
    }






void StartBattle() {
    int Characterchoice = 0;
    int player1Healthpoint = 30; // ������ ü�� = ������, 30 ���ݷ� 10
    int player1Attack = 10;
    int player2Healthpoint = 20; // ������ ü�� = ����, 20 ���ݷ� 15
    int player2Attack = 15;
    int Enemy1Healthpoint = 30; // ����1 = ������, 30 ���ݷ� 10
    int Enemy1Attack = 10;
    int Enemy2Healthpoint = 20; // ����2 = ����, 20 ���ݷ� 15
    int Enemy2Attack = 10;
    int BossHealthpoint = 40; // ���� ����= ��������, ���ݷ� 20
    int BossAttack = 20;
    int playerTurn = 1; // �÷��̾� ����
    int playerchoice = 0; // �÷��̾� ���� ���� �� ���û���
    int Enemychoice = 0; // �� ���� ���� �� ���û���
    srand(time(NULL)); // ���� ������ �ʱ�ȭ srand(time(NULL));�� �� �Ͽ��� ȣ���ϸ� ���� �� �ȿ� �Է��ϸ� ���� ������ ���� �� �ֽ��ϴ�. ���� ���� ���� �� ���� ȣ��


    //ĳ���� ���ÿ� ���� ü�� �� ���ݷ� ���
    if (Characterchoice == 1)
    {
        printf(" ����� �����Դϴ�. ü�� ������(%d) ���ݷ� %d, \n\n", player1Healthpoint, player1Attack);

    }
    else if (Characterchoice == 2)
    {
        printf(" ����� �����Դϴ�. ü�� ����(%d) ���ݷ� %d, \n\n", player2Healthpoint, player2Attack);

    }


    // ������ ���� while ����
    while (player1Healthpoint > 0 || player2Healthpoint  > 0 && Enemy1Healthpoint > 0) {
        printf("����1�� ��Ÿ����!\n");
        // stage 1  ��1 ü�� ������ ���ݷ� 10
        printf("�������� 1 ����!\n");
        printf("�� ü�� ������(30) ���ݷ� 10\n");
        // ����, ���� ���ÿ� ���� �ൿ ���û��� ����ڵ� 
        if (Characterchoice == 1) {
            printf("����(1) ���� ����(2) ���(3) �� �ش� ���ڸ� �Է��ϼ��� : ");
            scanf("%d", &playerchoice);
        }
        else if (Characterchoice == 2)
        {
            printf("����(1) ��Į ����(2) ȸ��(3) �� �ش� ���ڸ� �Է��ϼ��� :  ");
            scanf("%d", &playerchoice);
        }
      
        //�� ���� ����
        int Enemychoice = rand() % 3 + 1; // 1~3 ������ ���� ���� (1 = ����, 2 = ���, 3 = ȸ��)
        printf("���� ����: %d\n\n", Enemychoice); // ������ computerchoice�� �Ͽ��� �� �����ǵ��� �ʰ� ����� ��!!

        // �÷��̾� ����, ���� ����, ��Į, ���, ȸ�� vs ���� ����, ���, �ƹ��͵� ���Կ� ���� ��� 
        if (Characterchoice == 1 && playerchoice <= 0 || playerchoice > 3)
        {
            printf("�߸� �Է��Ͽ����ϴ�.\n\n");
        }
        else if (Characterchoice == 1 && playerchoice == 1)
        {
            printf("�����ϴ�.\n\n");
        }
        else if (Characterchoice == 1 || (playerchoice == 1 && Enemychoice == 3) || (playerchoice == 2 && Enemychoice == 1) || (playerchoice == 3 && Enemychoice == 2))
        {
            if (Characterchoice == 1) {
                printf("�����߽��ϴ�.\n\n");
                Enemy1Healthpoint = Enemy1Healthpoint - player1Attack;
            }
        }
        else
        {
            printf("�й��߽��ϴ�.\n\n");
            player1Healthpoint = player1Healthpoint - Enemy1Attack;
            player2Healthpoint = player2Healthpoint - Enemy1Attack;
        }
    }
    printf("----------------------------------\n");

    // ���� ��� ����
    if (player1Healthpoint <= 0 || player2Healthpoint <= 0) {
        printf("���� ����! �÷��̾ �й��߽��ϴ�.\n");
    }
    else {
        printf("�¸��߽��ϴ�! ���� �����ƽ��ϴ�.\n");
    }
}

// 3 �������� ���� (�������� 1, �������� 2, ����)
// ��� : ���� �� ��
// �� �������� Ŭ���� �� ü�� ���� ȸ�� ���ݷ� 0.4 ������,  
// ��������1 Ŭ���� �� �������� 1 Ŭ����, �������� 2 Ŭ����, ������ �����ƽ��ϴ�. -> ���� ���� �Բ� ���α׷� ����
// ����, ���� ü���� 0�� �Ǹ� �ٽ� ĳ���� ���ú��� ����

// ĳ���� ����
// ������ ü�� = ������, 30 ���ݷ� 10
// ������ ü�� = ����, 20 ���ݷ� 15
// ����1 = ������, 30 ���ݷ� 10
// ����2 = ������, 20 ���ݷ� 14
// ���� ���� = ��������, 40 ���ݷ� 20 ���� 5 , ü�� 20 ������ �� ������ 2 : ���� 7.5�� up  
// ���� �� �ִ�ü�� ���������� �ִ�
// ü�� ǥ�� ��, �������� ���� ü�� ��, �� ü�� �� 

// ���� �帧 
// ����: ���ݷ¸�ŭ �������� �ش�
// ���� ����: 1.5�踸ŭ �������� �ش�, ���� ������ ���� �ʿ� 2�Ͽ� �ѹ� ��� ���� 
// ��Į ����:  ���ݷ��� ���ݵ����� + �ߵ� �ο� ���� ���� �� 1.5�� �������� �ش�. 
// ȸ��: ������ ���� Ȯ�� 12.5% Ȯ��
// ���: 4��ŭ ���
// �������� ���� �� ����  1. ���ݷ� ������ or 2. ü�� ȸ�� ���(full ȸ��)
// ���ӿ��� playerHealthpoint = 0�̸� �ٽ� ���� ĳ���� �������� ���ư�.
// �������� = Esc or p ��ư
// ���� vs ����϶� ��� ������ ������ = ���� - ���ݷ�
// ȸ���� �÷��̾� 20%
// ȸ���� �� 10%  

// �߰� ��� 
// �������� Ŭ���� �� ��� 2���� �� �ϳ� ���� ���� = 1, ������ = 2 �� ��������
// �����̻� ���, �Ǹ� -> ������, ���� -> 0.1 ���� 1���� ������ ��
// �������� Ŭ���� �� ü�� Ǯȸ��, ������ ����â �����(������ ���ݷ� ���� or ���� ����)    

// ü�¿� ���� ǥ���� ������ ��ü�Ͽ� ǥ�� ex) healthpoint == 30 -> 30�� ������ ��ü


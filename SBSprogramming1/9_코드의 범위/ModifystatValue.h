#pragma once

int modifyINT = ReturnStatAmount(INT, 1);
printf("전투에 사용될 INT 스탯 : %d\n", modifyINT); // 가위 바위 보 보상에 따른 공격력 증가 함수로 활용 가능하지 않을까??

int modifyDEX = ReturnStatAmount(DEX, 1);
printf("전투에 사용될 DEX 스탯 : %d\n", modifyDEX); // 전투에만 필요한 것들은 함수로 표현 

int modifyLUK = ReturnStatAmount(LUK, 1);
printf("전투에 사용될 LUK 스탯 : %d\n", modifyLUK);

int modifySTR = ReturnStatAmount(STR, 1);
printf("전투에 사용될 STR 스탯 : %d\n", modifySTR);

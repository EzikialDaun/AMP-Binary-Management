#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "init.h"
#include "function.h"



void main()
{
    while(1)
    {
        system("cls");

        init_variable();
        input_filename(1);
        BIN_ex();               // bin 파일 읽어들여 온도 구간별로 정리

        if(fp == NULL)
        {         // 파일 입출력 오류
            system("pause");
            return -1;
        }

        printf("\n\n추출을 원하는 테이블의 온도를 입력하시오.\n");    // 5도 간격의 테이블에선 5의 배수로 입력
        printf("입력 --> ");
        scanf("%d", &object);

        if((object < tmin) || (object > pmax))
        {
            system("cls");
            printf("%s 파일은 %d 도에서 %d 도 사이에서 유효한 값을 가집니다.\n", fname, tmin, pmax);
            system("pause");
            return -1;
        }
        else if(((object % interval) && (object >= 0)) || (((-1 * object) % 5) && (object < 0)))
        {
            system("cls");
            printf("%s 파일은 %d도 간격으로 기록된 테이블 데이터 입니다.\n", fname, interval);
            system("pause");
            return -1;
        }

        system("cls");

        search_copy_data();                         // 입력한 온도 테이블을 배열에 저장하고 화면에 표시
        input_filename(0);

        system("cls");

        BIN_ex();                                   // 수정 대상 파일

        if(fp == NULL)
        {
            system("pause");
            return -1;
        }

        check_equality();

        printf("\n\nsh : %d, c : %d, b : %d", sh, c[0], b[0]);
        printf("\ntemp : %d, interval, : %d, tmin : %d, tmax, : %d\n", temp, interval, tmin, tmax);


        if(!ch_eq)
        {
            system("cls");
            printf("%s 파일에 %d 도 데이터가 존재하지 않습니다.\n", fname, object);
            system("pause");
            return -1;
        }

        if(object > pmax)
        {
            printf("%s 파일에 %d 도 데이터가 존재하지 않습니다.\n", fname, object);
            system("pause");
            return -1;
        }

        printf("\n\n\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("%s 파일의 %d도 테이블 데이터를 아래의 데이터로 대체하였습니다.\n", fname, object);
        printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");

        display_copy_data();    // 삽입 테이블 표시

        BIN_copy();             // 위에서 지정한 온도의 테이블 삽입

        if(fp == NULL)
        {
            system("pause");
            return -1;
        }

        printf("\n\n\n");
        printf("■■■■■■■■■■■\n");
        printf("■ 1. 다시 실행     ■\n");
        printf("■ 2. 프로그램 종료 ■\n");
        printf("■■■■■■■■■■■\n\n");

        printf("원하는 작업코드를 입력하시오.\n");
        printf("입력 --> ");
        scanf("%d", &op);

        if(op == 1)
            continue;
        else if(op == 2)
            break;
        free(c);
    }
    system("pause");
    printf("\n");
}

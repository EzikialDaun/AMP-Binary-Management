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
        BIN_ex();               // bin ���� �о�鿩 �µ� �������� ����

        if(fp == NULL)
        {         // ���� ����� ����
            system("pause");
            return -1;
        }

        printf("\n\n������ ���ϴ� ���̺��� �µ��� �Է��Ͻÿ�.\n");    // 5�� ������ ���̺��� 5�� ����� �Է�
        printf("�Է� --> ");
        scanf("%d", &object);

        if((object < tmin) || (object > pmax))
        {
            system("cls");
            printf("%s ������ %d ������ %d �� ���̿��� ��ȿ�� ���� �����ϴ�.\n", fname, tmin, pmax);
            system("pause");
            return -1;
        }
        else if(((object % interval) && (object >= 0)) || (((-1 * object) % 5) && (object < 0)))
        {
            system("cls");
            printf("%s ������ %d�� �������� ��ϵ� ���̺� ������ �Դϴ�.\n", fname, interval);
            system("pause");
            return -1;
        }

        system("cls");

        search_copy_data();                         // �Է��� �µ� ���̺��� �迭�� �����ϰ� ȭ�鿡 ǥ��
        input_filename(0);

        system("cls");

        BIN_ex();                                   // ���� ��� ����

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
            printf("%s ���Ͽ� %d �� �����Ͱ� �������� �ʽ��ϴ�.\n", fname, object);
            system("pause");
            return -1;
        }

        if(object > pmax)
        {
            printf("%s ���Ͽ� %d �� �����Ͱ� �������� �ʽ��ϴ�.\n", fname, object);
            system("pause");
            return -1;
        }

        printf("\n\n\n�������������������������������������\n");
        printf("%s ������ %d�� ���̺� �����͸� �Ʒ��� �����ͷ� ��ü�Ͽ����ϴ�.\n", fname, object);
        printf("�������������������������������������\n\n");

        display_copy_data();    // ���� ���̺� ǥ��

        BIN_copy();             // ������ ������ �µ��� ���̺� ����

        if(fp == NULL)
        {
            system("pause");
            return -1;
        }

        printf("\n\n\n");
        printf("������������\n");
        printf("�� 1. �ٽ� ����     ��\n");
        printf("�� 2. ���α׷� ���� ��\n");
        printf("������������\n\n");

        printf("���ϴ� �۾��ڵ带 �Է��Ͻÿ�.\n");
        printf("�Է� --> ");
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

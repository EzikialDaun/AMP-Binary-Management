
// �Է��� �µ��� �����ϰ��� �ϴ� ����� ���̺� �����ϴ��� üũ�ϴ� �Լ�
void check_equality()
{
    for(i=0;i<nob * temp * (sizeof(char));i++)
    {
        if((c[i] == object) && ((i % nob) == 0) && (object == tmin + ((i / nob) * interval)))
        {
            sh = ((object - tmin) / interval) + 1;
            ch_eq = 1;
        }
    }
}



//������ �ʱ�ȭ�ϴ� �Լ�
void init_variable()
{
    fp = NULL;                   // ���� ������

    (char*) memset(fname, 0, 20);
    temp = 0;
    interval = 0;
    tmin = 0;
    tmax = 0;
    object = 0;
    i = 0;
    j = 0;
    sh = 0;
    b = (char*) memset(b, 0, nob * temp * (sizeof(char)));
    ch_eq = 0;
    (char*) memset(a, 0, nob);
    pmax = 0;
    op = 0;
    pinterval = 0;
}



// ���� �̸��� �Է¹޾� Ȯ���ڸ� �ٿ��ְ� �����ϴ� �Լ�
void input_filename(int x){
    if(x)
        printf("Ư�� �µ��� ���̺� ���� �����ϰ��� �ϴ� ������ �̸��� �Է��Ͻÿ�. (bin ����)\n");
    else
        printf("\n\nƯ�� �µ��� ���̺� ���� �����ϰ��� �ϴ� ������ �̸��� �Է��Ͻÿ�. (bin ����)\n");

    printf("�Է�(.bin ����) --> ");
    scanf("%s", fname);             // ���� �̸�  xx.bin

    i = 0;

    while(fname[i] != NULL){
        i++;
    }

    fname[i] = '.';
    fname[i + 1] = 'b';
    fname[i + 2] = 'i';
    fname[i + 3] = 'n';
    fname[i + 4] = NULL;
}


// ���� �������� ���� ��ġ�� ã�� 88����Ʈ ��ŭ �迭�� ����
void search_copy_data()
{
    b = (char*) malloc(nob * temp *(sizeof(char)));
    fp = fopen(fname,"rtb");   // "rb" : ���̳ʸ� ���� �б� ���

    if(fp == NULL)
    {
        system("cls");
        printf("\n%s ���� �б� ��� ���� ����\n", fname);
        return -1;
    }

    fread(b,nob,temp,fp);

    for(i=0;i<nob * temp * (sizeof(char));i++)
    {
        if((b[i] == object) && ((i % nob) == 0) && (object == tmin + ((i / nob) * interval)))
        {
            for(j = 0;j < nob;j++)
            {
                a[j] = b[i + j];
                if(((i + j) % nob) == 0)
                {
                    if(a[j] >= 0xffffff10)
                       printf("\n\n�µ� : %d ��, 16���� : %x\n", a[j], a[j] - 0xffffff00);
                    else if(a[j] < 0x10)
                        printf("\n\n�µ� : %d ��, 16���� : 0%x\n", a[j], a[j]);
                    else
                        printf("\n\n�µ� : %d ��, 16���� : %x\n", a[j], a[j]);
                }
                else
                {
                    if(a[j] >= 0xffffff10)
                        printf("%x  ", a[j] - 0xffffff00);
                    else if(a[j] < 0x10)
                        printf("0%x  ", a[j]);
                    else
                        printf("%x  ", a[j]);
                }
            }
        }
    }

    free(b);
    fclose(fp);
}



void display_copy_data()
{           // ����Ǿ� ���Ե� �����͸� ǥ��
    for(j = 0;j < nob;j++)
    {
        if(j == 0)
        {
            if(a[j] >= 0xffffff10)
               printf("\n\n�µ� : %d ��, 16���� : %x\n", a[j], a[j] - 0xffffff00);
            else if(a[j] < 0x10)
                printf("\n\n�µ� : %d ��, 16���� : 0%x\n", a[j], a[j]);
            else
                printf("\n\n�µ� : %d ��, 16���� : %x\n", a[j], a[j]);
        }
        else
        {
            if(a[j] >= 0xffffff10)
                printf("%x  ", a[j] - 0xffffff00);
            else if(a[j] < 0x10)
                printf("0%x  ", a[j]);
            else
                printf("%x  ", a[j]);
        }
    }
}



void BIN_copy()
{
    fp = fopen(fname,"rb");   // "rb" : ���̳ʸ� ���� �б� ���

    if(fp == NULL)
    {
        system("cls");
        printf("\n%s ���� �б� ��� ���� ����\n", fname);
        return -1;
    }

    b = (char*) malloc(nob * temp * (sizeof(char)));

    fread(b,nob,temp,fp);

    fclose(fp);

    fp = fopen(fname, "wb");

    if(fp == NULL)
    {
        system("cls");
        printf("\n%s ���� ���� ��� ���� ����\n", fname);
        return -1;
    }

    fwrite(b, nob, sh - 1, fp);
    fwrite(a, nob, 1, fp);
    fwrite((b + (nob * sh)), nob, temp - sh, fp);
    free(b);

    fclose(fp);
}



void BIN_ex()
{         // ������ ������ ȭ�鿡 ǥ���ϴ� ���
    temp = max_temp_count;
    b = (char*) malloc(nob * temp * (sizeof(char)));
    b = (char*) memset(b, 0, nob * temp * (sizeof(char)));

    fp = fopen(fname,"rb");   // "rb" : ���̳ʸ� ���� �б�

    if(fp == NULL){
        system("cls");
        printf("%s ���� �б� ��� ���� ����\n", fname);
        return -1;
    }

    fread(b,nob,temp,fp);

    tmin = b[0];
    interval = b[nob] - b[0];

    //  fp�� FILE ����ü ������
    //  fread(b,nob,temp,fp);
    //  fp�� FILE ����ü ������

    for(i=0;i<nob * temp * (sizeof(char));i++)
    {
        if((((b[i + 88] == 0) && (b[i + 89] == 0) && (b[i + 90] == 0)) || (b[i + 88] == 0xffffffff)) && (i % 88 == 0))
        {
            tmax = b[i];
            pmax = b[i];
            break;
        }
    }

    if(object > pmax)
    {
        return -1;
    }

    temp = ((tmax - tmin) / interval) + 1;


    for(i = 0;i < nob * temp * (sizeof(char));i++)
    {
        c[i] = b[i];
        if((i % nob) == 0)
        {
            if(b[i] >= 0xffffff10)
                printf("\n\n�µ� : %d ��, 16���� : %x\n", b[i], b[i] - 0xffffff00);
            else if(b[i] < 0x10)
                printf("\n\n�µ� : %d ��, 16���� : 0%x\n", b[i], b[i]);
            else
                printf("\n\n�µ� : %d ��, 16���� : %x\n", b[i], b[i]);
        }
        else
        {
            if(b[i] >= 0xffffff10)
                printf("%x  ", b[i] - 0xffffff00);
            else if(b[i] < 0x10)
                printf("0%x  ", b[i]);
            else
                printf("%x  ", b[i]);
        }
    }




    fclose(fp);

    free(b);
}

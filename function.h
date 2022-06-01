
// 입력한 온도가 삽입하고자 하는 대상의 테이블에 존재하는지 체크하는 함수
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



//변수를 초기화하는 함수
void init_variable()
{
    fp = NULL;                   // 파일 포인터

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



// 파일 이름을 입력받아 확장자를 붙여주고 저장하는 함수
void input_filename(int x){
    if(x)
        printf("특정 온도의 테이블 값을 추출하고자 하는 파일의 이름을 입력하시오. (bin 파일)\n");
    else
        printf("\n\n특정 온도의 테이블 값을 수정하고자 하는 파일의 이름을 입력하시오. (bin 파일)\n");

    printf("입력(.bin 없이) --> ");
    scanf("%s", fname);             // 파일 이름  xx.bin

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


// 복사 데이터의 시작 위치를 찾아 88바이트 만큼 배열에 저장
void search_copy_data()
{
    b = (char*) malloc(nob * temp *(sizeof(char)));
    fp = fopen(fname,"rtb");   // "rb" : 바이너리 파일 읽기 모드

    if(fp == NULL)
    {
        system("cls");
        printf("\n%s 파일 읽기 모드 열기 실패\n", fname);
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
                       printf("\n\n온도 : %d 도, 16진수 : %x\n", a[j], a[j] - 0xffffff00);
                    else if(a[j] < 0x10)
                        printf("\n\n온도 : %d 도, 16진수 : 0%x\n", a[j], a[j]);
                    else
                        printf("\n\n온도 : %d 도, 16진수 : %x\n", a[j], a[j]);
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
{           // 복사되어 삽입될 데이터를 표시
    for(j = 0;j < nob;j++)
    {
        if(j == 0)
        {
            if(a[j] >= 0xffffff10)
               printf("\n\n온도 : %d 도, 16진수 : %x\n", a[j], a[j] - 0xffffff00);
            else if(a[j] < 0x10)
                printf("\n\n온도 : %d 도, 16진수 : 0%x\n", a[j], a[j]);
            else
                printf("\n\n온도 : %d 도, 16진수 : %x\n", a[j], a[j]);
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
    fp = fopen(fname,"rb");   // "rb" : 바이너리 파일 읽기 모드

    if(fp == NULL)
    {
        system("cls");
        printf("\n%s 파일 읽기 모드 열기 실패\n", fname);
        return -1;
    }

    b = (char*) malloc(nob * temp * (sizeof(char)));

    fread(b,nob,temp,fp);

    fclose(fp);

    fp = fopen(fname, "wb");

    if(fp == NULL)
    {
        system("cls");
        printf("\n%s 파일 쓰기 모드 열기 실패\n", fname);
        return -1;
    }

    fwrite(b, nob, sh - 1, fp);
    fwrite(a, nob, 1, fp);
    fwrite((b + (nob * sh)), nob, temp - sh, fp);
    free(b);

    fclose(fp);
}



void BIN_ex()
{         // 피추출 데이터 화면에 표시하는 기능
    temp = max_temp_count;
    b = (char*) malloc(nob * temp * (sizeof(char)));
    b = (char*) memset(b, 0, nob * temp * (sizeof(char)));

    fp = fopen(fname,"rb");   // "rb" : 바이너리 파일 읽기

    if(fp == NULL){
        system("cls");
        printf("%s 파일 읽기 모드 열기 실패\n", fname);
        return -1;
    }

    fread(b,nob,temp,fp);

    tmin = b[0];
    interval = b[nob] - b[0];

    //  fp는 FILE 구조체 포인터
    //  fread(b,nob,temp,fp);
    //  fp는 FILE 구조체 포인터

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
                printf("\n\n온도 : %d 도, 16진수 : %x\n", b[i], b[i] - 0xffffff00);
            else if(b[i] < 0x10)
                printf("\n\n온도 : %d 도, 16진수 : 0%x\n", b[i], b[i]);
            else
                printf("\n\n온도 : %d 도, 16진수 : %x\n", b[i], b[i]);
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

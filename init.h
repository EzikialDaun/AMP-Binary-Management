#define max_temp_count 30
#define nob 88              // number of bytes during one temperature interval



FILE *fp;                   // 파일 포인터

char fname[20];             // 파일 이름
unsigned int temp;          // 화면에 보여주는 온도 테이블의 개수, 초기값은 28개
unsigned int interval;      // 온도 간격
unsigned int pinterval;
int tmin, tmax;             // 온도의 최소값, 최대값
char object;                // 옮기고자 하는 온도
unsigned int i;             // 피추출 대상 파일 인덱스 변수
unsigned int j;             // 피추출 대상 파일 중, 추출을 원하는 한 개의 테이블에 대한 인덱스 변수
unsigned int sh;            // 삽입 대상의 인덱스
char *b;                    // 전체 테이블 데이터
char c[2000];
char a[nob];                // 삽입 대상의 데이터
char ch_eq;                 // 피추출 대상과 삽입 대상의 온도가 같은지 체크
char pmax;                  // 최대값 임시 저장 변수
int op;                     // 작업 선택 코드

#define max_temp_count 30
#define nob 88              // number of bytes during one temperature interval



FILE *fp;                   // ���� ������

char fname[20];             // ���� �̸�
unsigned int temp;          // ȭ�鿡 �����ִ� �µ� ���̺��� ����, �ʱⰪ�� 28��
unsigned int interval;      // �µ� ����
unsigned int pinterval;
int tmin, tmax;             // �µ��� �ּҰ�, �ִ밪
char object;                // �ű���� �ϴ� �µ�
unsigned int i;             // ������ ��� ���� �ε��� ����
unsigned int j;             // ������ ��� ���� ��, ������ ���ϴ� �� ���� ���̺� ���� �ε��� ����
unsigned int sh;            // ���� ����� �ε���
char *b;                    // ��ü ���̺� ������
char c[2000];
char a[nob];                // ���� ����� ������
char ch_eq;                 // ������ ���� ���� ����� �µ��� ������ üũ
char pmax;                  // �ִ밪 �ӽ� ���� ����
int op;                     // �۾� ���� �ڵ�

#include <stdio.h>
#include <string.h>

int �����Է�(int* hour, int* minute, int* fee); //�����Է� �Լ�
int ��ݰ��(int* hour, int* minute, int* fee); //��ݰ�� �Լ�

char car[20] = "car"; // ����

int main() {
    int minute = 0; // ��
    int hour = 0; // ��
    int fee = 0; // ���

    //�Լ��� ��������
    //Call by reference�� �Լ����� ���� ��ȯ�� �� �ִ�
    �����Է�(&hour, &minute, &fee);
    ��ݰ��(&hour, &minute, &fee);

    //������ �̿����� ���
    printf("�����ð� = %d�� %d�� \n���� = %s\n", hour, minute, car);
    printf("������� = %d\n", fee);

    return 0;
}
int �����Է�(int* hour, int* minute, int* fee) {
    while (1) {
        *minute = 0;
        *hour = 0;
        *fee = 0;

        printf("���������� �Է����ּ���\n�ð� = ");
        scanf_s("%d", hour);
        if (*hour < 0) { //������ �Է½� �ٽ��Է��ϱ�
            printf("0 �̻��� ���� �Է����ּ���\n");
            continue;
        }
        printf("�� = ");
        scanf_s("%d", minute);
        if (*minute < 0 || *minute > 59) { //0���� 59�б��� �Է°���
            printf("0 ~ 59 ������ ���� �Է����ּ���\n");
            continue;
        }
        printf("���� = ");
        scanf_s("%s", car, sizeof(car));
        break;
    }
}
int ��ݰ��(int* hour, int* minute, int* fee) {
    if (*hour > 4) { //�Ϸ� 4�ð� �ʰ� ������ �⺻ 25000��
        if ((*hour / 24) > 0) { // ��Ʋ �̻� ������ ��� üũ         
            *fee += (*hour / 24) * 25000;
            if ((*hour % 24) > 4) *fee += 25000;
            else *fee += (*hour % 24) * 6000;
        }
        else {
            *fee += 25000; //4�ð� �ʰ����� 24�ð������� 25000��
        }
    }
    else { //4�ð� ���� �����
        *fee += *hour * 6000;
        *fee += ((*minute / 10) * 1000);
        if (*minute % 10 > 0) *fee += 1000; //1���ڸ��� 0�� �ƴϸ� 1000�� �߰�
    }

    if (strcmp(car, "����") == 0) { // �迭�� ������ '����'�̸� ����� 50%�����Ѵ�
        printf("������� 50%% ���� ����Ǿ����ϴ�.\n");
        *fee /= 2;
    }
}

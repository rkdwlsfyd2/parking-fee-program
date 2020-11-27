#include <stdio.h>
#include <string.h>

int 정보입력(int* hour, int* minute, int* fee); //정보입력 함수
int 요금계산(int* hour, int* minute, int* fee); //요금계산 함수

char car[20] = "car"; // 차종

int main() {
    int minute = 0; // 분
    int hour = 0; // 시
    int fee = 0; // 요금

    //함수에 인자전달
    //Call by reference로 함수에서 값을 변환할 수 있다
    정보입력(&hour, &minute, &fee);
    요금계산(&hour, &minute, &fee);

    //주차장 이용정보 출력
    printf("주차시간 = %d시 %d분 \n차종 = %s\n", hour, minute, car);
    printf("주차요금 = %d\n", fee);

    return 0;
}
int 정보입력(int* hour, int* minute, int* fee) {
    while (1) {
        *minute = 0;
        *hour = 0;
        *fee = 0;

        printf("주차정보를 입력해주세요\n시간 = ");
        scanf_s("%d", hour);
        if (*hour < 0) { //음수값 입력시 다시입력하기
            printf("0 이상의 값을 입력해주세요\n");
            continue;
        }
        printf("분 = ");
        scanf_s("%d", minute);
        if (*minute < 0 || *minute > 59) { //0부터 59분까지 입력가능
            printf("0 ~ 59 사이의 값을 입력해주세요\n");
            continue;
        }
        printf("차종 = ");
        scanf_s("%s", car, sizeof(car));
        break;
    }
}
int 요금계산(int* hour, int* minute, int* fee) {
    if (*hour > 4) { //하루 4시간 초과 주차시 기본 25000원
        if ((*hour / 24) > 0) { // 이틀 이상 주차한 경우 체크         
            *fee += (*hour / 24) * 25000;
            if ((*hour % 24) > 4) *fee += 25000;
            else *fee += (*hour % 24) * 6000;
        }
        else {
            *fee += 25000; //4시간 초과부터 24시간까지는 25000원
        }
    }
    else { //4시간 이하 요금제
        *fee += *hour * 6000;
        *fee += ((*minute / 10) * 1000);
        if (*minute % 10 > 0) *fee += 1000; //1의자리가 0이 아니면 1000원 추가
    }

    if (strcmp(car, "경차") == 0) { // 배열의 내용이 '경차'이면 요금을 50%할인한다
        printf("경차요금 50%% 할인 적용되었습니다.\n");
        *fee /= 2;
    }
}

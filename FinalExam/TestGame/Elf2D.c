#include <stdio.h>
#include <Windows.h>
#include "Elf2D.h"
#include <math.h>

void Elf2DInitScreen()
{
    //커서 숨기기
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;  // 커서를 숨김
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
} 

// 화면 초기화 함수
void Elf2DClearScreen(char* Buffer, int width, int height)
{
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++) 
        {
            Buffer[i * (width + 1) + j] = ' ';  // 화면 초기화
        }
        Buffer[i * (width + 1) + width] = '\n';  // 개행 문자
    }
    Buffer[(width + 1) * height - 1] = '\0';  // 개행 문자

}

// 스크린버퍼를 이용하여 화면을 그리는 함수
void Elf2DDrawBuffer(char* Buffer)
{
    //0,0으로 이동
    COORD coord = { 0, 0 };  // 좌표 (0, 0)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // 스크린 버퍼 출력
    printf("%s", Buffer);  // 화면 출력
}

// 두 점을 연결하는 직선을 그리는 함수 (브레젠햄 알고리즘)
void Elf2DDrawLine(int x1, int y1, int x2, int y2, char* Buffer, int width, int height) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < height) {
            Buffer[y1 * (width + 1) + x1] = Elf2DDrawSymbol[0];  // 첫 번째 문자
            Buffer[y1 * (width + 1) + x1 + 1] = Elf2DDrawSymbol[1]; // 두 번째 문자
        }

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}


void Elf2DDrawLine2(float x1, float y1, float x2, float y2, char* Buffer, int width, int height)
{
    float dx = fabsf(x2 - x1);
    float dy = fabsf(y2 - y1);
    float sx = (x1 < x2) ? 1.0f : -1.0f;
    float sy = (y1 < y2) ? 1.0f : -1.0f;
    float err = dx - dy;

    while (1) {
        int ix1 = (int)x1;
        int iy1 = (int)y1;

        if (ix1 >= 0 && ix1 < width && iy1 >= 0 && iy1 < height) {
            Buffer[iy1 * (width + 1) + ix1] = '*'; // Draw point
        }

        if (fabsf(x1 - x2) < 0.01f && fabsf(y1 - y2) < 0.01f)
            break;

        float e2 = 2.0f * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

char Elf2DDrawSymbol[3] = "@@"; // 기본 심볼은 "**"로 설정

// 2. 심볼 설정 함수 추가
void Elf2DSetSymbol(const char* symbol) {
    strncpy_s(Elf2DDrawSymbol, sizeof(Elf2DDrawSymbol), symbol, _TRUNCATE);
}


void Elf2DSleep(int ms)
{
    Sleep(ms);
}
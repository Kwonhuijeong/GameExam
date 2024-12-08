#ifndef ELFOBJECT_H
#define ELFOBJECT_H

#include "ElfMath.h"

// ���� ������Ʈ - ��
typedef struct {
    Vector2 Position;
    float Rotation;
    Vector2 Scale;
    Vector2 Line[2];
    char* Symbol;
} GameObject_Line;

// ���� ������Ʈ - �ﰢ��
typedef struct {
    Vector2 Position;
    float Rotation;
    Vector2 Scale;
    Vector2 Lines[3][2]; // �ﰢ���� �� ���� ����
    char* Symbol;
} GameObject_Triangle;

#endif

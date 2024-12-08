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
    Vector2 Lines[3][2];  // �ﰢ���� �� �� (�� ���� �������� ����)
    Vector2 Position;     // �ﰢ�� �߽� ��ġ
    Vector2 Scale;        // ũ��
    float Rotation;       // ȸ��
    char Symbol[3];       // �׵θ� �ɺ� (��: "@@")
} GameObject_Triangle;

// ���� ������Ʈ - ��
typedef struct {
    Vector2 Position;  // ���� ��ġ
    char Symbol[2];    // ���� ��ȣ (�⺻��: "++")
} GameObject_Dot;


#endif

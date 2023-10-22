#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "res.h"   // ������Ϸ��Դ�ļ�
#include "game.h"  // ������Ϸ�߼��ļ�
#include "ui.h"    // �����û������ļ�
#include "prng.h"  // ����α������������ļ�

#ifdef DBG
#include <assert.h>
#endif

int main(int argc, char** args) {
    prngSrand(time(NULL));  // ʹ�õ�ǰʱ����Ϊ���ӳ�ʼ��α�����������

   
    if (!init()) {  // ��ʼ��SDL�ʹ�����Ϸ����
        printf("Failed to initialize!\n");
    }
    else {
        
        if (!loadMedia()) {  // ������Ϸý����Դ
            printf("Failed to load media!\n");
        }
        else {
            mainUi();  // ����������ѭ��
        }
    }

    cleanup();  // ������Դ

    return 0;
}
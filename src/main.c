#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "res.h"   // 导入游戏资源文件
#include "game.h"  // 导入游戏逻辑文件
#include "ui.h"    // 导入用户界面文件
#include "prng.h"  // 导入伪随机数生成器文件

#ifdef DBG
#include <assert.h>
#endif

int main(int argc, char** args) {
    prngSrand(time(NULL));  // 使用当前时间作为种子初始化伪随机数生成器

   
    if (!init()) {  // 初始化SDL和创建游戏窗口
        printf("Failed to initialize!\n");
    }
    else {
        
        if (!loadMedia()) {  // 加载游戏媒体资源
            printf("Failed to load media!\n");
        }
        else {
            mainUi();  // 进入主界面循环
        }
    }

    cleanup();  // 清理资源

    return 0;
}
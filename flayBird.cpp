/*#include<stdio.h>
#include<conio.h>//按键头文件
#include<graphics.h>//图形库头文件
#include<time.h>//随机函数
#include<mmsystem.h>//多媒体播放音乐
#include "tools.h"
#pragma comment(lib,"winmm.libn")
int main() {
	IMAGE  background;
	IMAGE  bigBird[2];
	IMAGE  down[2];
	IMAGE  up[2];
	IMAGE  end[2];
	struct bird
	{
		int x, y;
		int speed;
	};
	//255,539
	struct bird flayBird = { 255 / 2 ,539 / 2, 100 };
	struct pillar
	{
		int x, y;
		int height;  //显示的柱子
	};

	struct pillar arrayPillar[3];
	void initpillar(struct pillar arraypillar[], int i)
	{
		//c语言中随机数
		arraypillar[i].height = rand() % 100 + 160;
		arraypillar[i].x = 288;
		arraypillar[i].y = 0;
	}
	void drawPillar(struct pillar curpillar)
	{
		//一对柱子
		putimage(curpillar.x, 0, 52, curpillar.height, down + 1, 0, 320 - curpillar.height, SRCAND);
		putimage(curpillar.x, 0, 52, curpillar.height, down, 0, 320 - curpillar.height, SRCPAINT);
		putimage(curpillar.x, 512 - (320 - curpillar.height), 52, 320 - curpillar.height, up + 1, 0, 0, SRCAND);
		putimagecurpillar.x, 512 - (320 - curpillar.height), 52, 320 - curpillar.height, up + 1, 0, 0, SPCPAINT);


		
		
		)
	//加载资源
	void loadResource()
	{
		loadimage(background, "background.png");
		loadimage(&bigBird, "bigBird.png", 48, 48);
		loadimage(&smallBird, "smallBird.png", 48, 48);
		loadimage(down, "down.bmp");
		loadimage(down +1,"downy.bmp");
		loadimage(up, "up.bmp");
		loadimage(up + 1, "upy.bmp");
		loadimage(&end[0], "end.bmp");
		loadimage(&end[1], "endy.bmp");
		loadimage()
	}
	//绘制小鸟
	void drawBird()
	{
		putimage(flayBird.y, &bigBird);
		putimage(flayBird.y, &smallBird);
	}
	//音乐
	DWORD WINAPI playMusic(LPVOID lpvid)
	{
		muiSendString("open           alianss music", 0, 0, 0);
		mciSendstring("play music wait", 0, 0, 0);
		mciSendstring("close music", 0, 0, 0);
		return 0；
	}

	//做按键处理
	void keyDown()
	{
		char userKey = _getch();
		switch (userKey) {
			case ' ';
				FlayBird.y -= flayBird.speed;
				CreateThread(NULL, NULL, playMusic, NULL.NULL, NULL);
				break;
				default;
				break;
		}
	}

	//鸟钻地
	int hitEloor() {
		if (flaybird.y >= 222 || flayBird.y <= 0)
			return 1;
		else
			return 0;
	}
	//结束动画
	void gameOverAction()
	{
		int x = 50, y = 608;
		while (y >= 240) {
			putimage(0, 0, &background);
			putimage(x, y, end + 1, SRCAND);
			putimage(x, y, end, SRCPAINT);
			y -= 50;
			sleep(50);
		}
	}

	int main() {
		srand((unsigned int)time(NULL));
		loadResource();
		for (int i = 0;i < 3;i++)
		{
			initpillar(arraypillar, i);
			arraypillar[i].x = 288 + i * 150;
		}
		initgraph(288, 608);
		while (1)
		{
			putimage(0, 0, &background);
			drawBird();
			for (int i = 0;i < 3;i++)
			{
				arraypillar[i].x -= 10;
			}
			for (int i = 0;i < 3;i++)
			{
				drawpillar(arraypillar[i]);
				if (arraypillar[i].x < (-52 - 150)
				{
					initpillar(arraypillar, i);
				}
			}
			if (hitFloor)){
				break;
				}
				flayBird.y += 10;
				if（_kbhit())   {   //有按键返回非零值
					KeyDown();
				}//等待用户按键
				sleep(100);
			}
		putimage(0, 0, &background);
		outtextxy(200, 200, "GAMEOVER!");
		gameOverAction();
		_getch();
			closegraph();
			system("pause");
			return 0;
		}*/




































































/*#include <stdio.h>
#include <conio.h> // 按键头文件
#include <graphics.h> // 图形库头文件
#include <time.h> // 随机函数
#include <mmsystem.h> // 多媒体播放音乐
#pragma comment(lib, "winmm.lib")

// 定义全局变量
IMAGE background;
IMAGE bigBird[2];
IMAGE down;
IMAGE up;
IMAGE end[2];

struct bird {
    int x, y;
    int speed;
};

struct bird flayBird = { 255 / 2, 539 / 2, 100 };

struct pillar {
    int x, y;
    int height; // 显示的柱子
};

struct pillar arrayPillar[3];

void initPillar(struct pillar arrayPillar[], int i) {
    arrayPillar[i].height = rand() % 100 + 160;
    arrayPillar[i].x = 288;
    arrayPillar[i].y = 0;
}

void drawPillar(struct pillar curPillar) {
    putimage(curPillar.x, 0, &down);
    putimage(curPillar.x, 512 - curPillar.height, &up);
}

void loadResource() {
    loadimage(&background, _T("background.png"));
    loadimage(&bigBird[0], _T("bigBird.png"), 48, 48);
    loadimage(&bigBird[1], _T("bigBird.png"), 48, 48);
    loadimage(&down, _T("down.png"));
    loadimage(&up, _T("up.png"));
    loadimage(&end[0], _T("end.png"));
}

void drawBird() {
    putimage(flayBird.x, flayBird.y, &bigBird[0]);
}

DWORD WINAPI playMusic(LPVOID lpParam) {
    mciSendString(_T("open music.mp3 alias music"), NULL, 0, NULL);
    mciSendString(_T("play music repeat"), NULL, 0, NULL);
    return 0;
}

void keyDown() {
    char userKey = _getch();
    switch (userKey) {
        case ' ':
            flayBird.y -= flayBird.speed;
            CreateThread(NULL, 0, playMusic, NULL, 0, NULL);
            break;
        default:
            break;
    }
}

int hitFloor() {
    if (flayBird.y >= 539 || flayBird.y <= 0)
        return 1;
    else
        return 0;
}

void gameOverAction() {
	
    int x = 50, y = 608;
    while (y >= 240) {
		BeginBatchDraw();
        putimage(0, 0, &background);
		putimage(x, y, &end);
        y -= 50;
        Sleep(50);
		EndBatchDraw();
    }
}

int main() {
    srand((unsigned int)time(NULL));
    loadResource();
    for (int i = 0; i < 3; i++) {
        initPillar(arrayPillar, i);
        arrayPillar[i].x = 288 + i * 150;
    }
    initgraph(288, 608);
    while (1) {
        putimage(0, 0, &background);
        drawBird();
        for (int i = 0; i < 3; i++) {
            arrayPillar[i].x -= 10;
        }
        for (int i = 0; i < 3; i++) {
            drawPillar(arrayPillar[i]);
            if (arrayPillar[i].x < (-52 - 150)) {
                initPillar(arrayPillar, i);
                arrayPillar[i].x = 288 + 150 * 3;
            }
        }
        if (hitFloor()) {
            break;
        }
        flayBird.y += 10;
        if (_kbhit()) {
            keyDown();
        }
        Sleep(100);
    }
    putimage(0, 0, &background);
    gameOverAction();
    _getch();
    closegraph();
    system("pause");
    return 0;
}*/



























 
#include <stdio.h>
#include <conio.h> // 按键头文件
#include <graphics.h> // 图形库头文件
#include <time.h> // 随机函数
#include <mmsystem.h> // 多媒体播放音乐
#pragma comment(lib, "winmm.lib")

// 定义全局变量
IMAGE background;
IMAGE bigBird[2];
IMAGE down;
IMAGE up;
IMAGE end[2];

struct bird {
    int x, y;
    int speed;
};

struct bird flayBird = { 255 / 2, 539 / 2, 100 };

struct pillar {
    int x, y;
    int height; // 显示的柱子
};

struct pillar arrayPillar[3];

static void initPillar(struct pillar arrayPillar[], int i) {
    arrayPillar[i].height = rand() % 100 + 160;
    arrayPillar[i].x = 288;
    arrayPillar[i].y = 0;
}

static void drawPillar(struct pillar curPillar) {
    putimage(curPillar.x, 0, &down, SRCAND);
    putimage(curPillar.x, 0, &down, SRCPAINT);
    putimage(curPillar.x, 512 - curPillar.height, &up, SRCAND);
    putimage(curPillar.x, 512 - curPillar.height, &up, SRCPAINT);
}

static void loadResource() {
    loadimage(&background, _T("background.png"));
    loadimage(&bigBird[0], _T("bigBird.png"), 48, 48);
    loadimage(&bigBird[1], _T("bigBird.png"), 48, 48);
    loadimage(&down, _T("down.png"));
    loadimage(&up, _T("up.png"));
    loadimage(&end[0], _T("end.png"));
}

static void drawBird() {
    putimage(flayBird.x, flayBird.y, &bigBird[0]);
}

static DWORD WINAPI playMusic(LPVOID lpParam) {
    mciSendString(_T("open music.mp3 alias music"), NULL, 0, NULL);
    mciSendString(_T("play music repeat"), NULL, 0, NULL);
    return 0;
}

static void keyDown() {
    char userKey = _getch();
    switch (userKey) {
    case ' ':
        flayBird.y -= flayBird.speed;
        CreateThread(NULL, 0, playMusic, NULL, 0, NULL);
        break;
    default:
        break;
    }
}

static int hitFloor() {
    if (flayBird.y >= 539 || flayBird.y <= 0)
        return 1;
    else
        return 0;
}

static int hitPillar() {
    for (int i = 0; i < 3; i++) {
        if (flayBird.x + 48 > arrayPillar[i].x && flayBird.x < arrayPillar[i].x + 52) {
            if (flayBird.y < arrayPillar[i].height || flayBird.y + 48 > 512 - (320 - arrayPillar[i].height)) {
                return 1;
            }
        }
    }
    return 0;
}

static void gameOverAction() {
    int x = 50, y = 608;
    while (y >= 240) {
        BeginBatchDraw();
        putimage(0, 0, &background);
        putimage(x, y, &end[0], SRCAND);
        putimage(x, y, &end[0], SRCPAINT);
        y -= 50;
        Sleep(50);
        EndBatchDraw();
    }
}

int main() {
    srand((unsigned int)time(NULL));
    loadResource();
    for (int i = 0; i < 3; i++) {
        initPillar(arrayPillar, i);
        arrayPillar[i].x = 288 + i * 150;
    }
    initgraph(288, 608);
    while (1) {
        putimage(0, 0, &background);
        drawBird();
        for (int i = 0; i < 3; i++) {
            arrayPillar[i].x -= 10;
        }
        for (int i = 0; i < 3; i++) {
            drawPillar(arrayPillar[i]);
            if (arrayPillar[i].x < (-52 - 150)) {
                initPillar(arrayPillar, i);
                arrayPillar[i].x = 288 + 150 * 3;
            }
        }
        if (hitFloor() || hitPillar()) {
            break;
        }
        flayBird.y += 10;
        if (_kbhit()) {
            keyDown();
        }
        Sleep(100);
    }
    putimage(0, 0, &background);
    gameOverAction();
    _getch();
    closegraph();
    system("pause");
    return 0;
}
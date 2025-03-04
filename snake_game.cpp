#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define MAPHEIGHT 25
#define MAPWIDTH 60
#define SNAKESIZE 50

struct FOOD { 
    int x;
    int y;
} food;

struct {
    int x[SNAKESIZE];
    int y[SNAKESIZE];
    int len;
    int speed;
} snake;

int key = 'w';
int changFlag = 0;

void gotoxy(int x, int y);
void drawMap();
void createFood();
int snakeStatus();

void drawMap() {
    srand((unsigned)time(NULL));
    for (int i = 0; i <= MAPHEIGHT; i++) {
        gotoxy(0, i);
        printf("■");
        gotoxy(MAPWIDTH, i);
        printf("■");
    }
    for (int i = 0; i <= MAPWIDTH; i += 2) {
        gotoxy(i, 0);
        printf("■");
        gotoxy(i, MAPHEIGHT);
        printf("■");
    }
    snake.len = 3;
    snake.speed = 100;
    snake.x[0] = MAPWIDTH / 2;
    snake.y[0] = MAPHEIGHT / 2;
    gotoxy(snake.x[0], snake.y[0]);
    printf("■");
    for (int k = 1; k < snake.len; k++) {
        snake.x[k] = snake.x[k - 1] + 2;
        snake.y[k] = snake.y[k - 1];
        gotoxy(snake.x[k], snake.y[k]);
        printf("■");
    }
    food.x = rand() % (MAPWIDTH - 4) + 2;
    food.y = rand() % (MAPHEIGHT - 2) + 1;
    if (food.x % 2 != 0) {
        food.x = food.x + 1;
    }
    gotoxy(food.x, food.y);
    printf("●");
}

void createFood() {
    if (snake.x[0] == food.x && snake.y[0] == food.y) {
        srand((unsigned int)time(NULL));
        while (1) {
            int flag = 1;
            food.x = rand() % (MAPWIDTH - 4) + 2;
            food.y = rand() % (MAPHEIGHT - 2) + 1;
            for (int k = 0; k < snake.len; k++) {
                if (snake.x[k] == food.x && snake.y[k] == food.y) {
                    flag = 0;
                    break;
                }
            }
            if (flag && food.x % 2 == 0) {
                break;
            }
        }
        gotoxy(food.x, food.y);
        printf("●");
        snake.len++;
        changFlag = 1;
    }
}

void keyDown() {
    if (_kbhit()) {
        fflush(stdin);
        key = _getch();
    }
    if (!changFlag) {
        gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
        printf(" ");
    }
    for (int i = snake.len - 1; i > 0; i--) {
        snake.x[i] = snake.x[i - 1];
        snake.y[i] = snake.y[i - 1];
    }
    switch (key) {
        case 'W':
        case 'w':
            snake.y[0]--;
            break;
        case 'S':
        case 's':
            snake.y[0]++;
            break;
        case 'A':
        case 'a':
            snake.x[0] -= 2;
            break;
        case 'd':
        case 'D':
            snake.x[0] += 2;
            break;
    }
    gotoxy(snake.x[0], snake.y[0]);
    printf("■");
    changFlag = 0;
    gotoxy(MAPHEIGHT + 2, 0);
}

int snakeStatus() {
    if (snake.x[0] == 0 || snake.x[0] == MAPWIDTH || snake.y[0] == 0 || snake.y[0] == MAPHEIGHT) {
        return 0;
    }
    for (int k = 1; k < snake.len; k++) {
        if (snake.x[0] == snake.x[k] && snake.y[0] == snake.y[k]) {
            return 0;
        }
    }
    return 1;
}

void gotoxy(int x, int y) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(handle, coord);
}

int main() {
    // 设置控制台为UTF-8编码
    SetConsoleOutputCP(65001);

    drawMap();
    while (1) {
        createFood();
        Sleep(snake.speed);
        keyDown();
        if (!snakeStatus()) {
            break;
        }
    }
    gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2);
    printf("You lose!");
    system("pause"); // 暂停，等待用户按任意键退出
    return 0;
}
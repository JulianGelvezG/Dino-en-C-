#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

bool gameOver;
const int width = 50;
const int height = 20;
int dinoX, dinoY, obstacleX, score;
bool isJumping = false;
int jumpHeight = 0;

void Setup() {
    gameOver = false;
    dinoX = 5;
    dinoY = height - 1;
    obstacleX = width - 1;
    score = 0;
}

void Draw() {
    system("cls"); // Clear the console

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";

            if (i == dinoY && j == dinoX)
                cout << "R"; // Dinosaurio
            else if (i == height - 1)
                cout << "_"; // Suelo
            else if (i == height - 1 && j == obstacleX)
                cout << "+"; // Cactus
            else
                cout << " ";

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case ' ':
            if (!isJumping) {
                isJumping = true;
                jumpHeight = 0;
            }
            break;
        }
    }
}

void Logic() {
    if (isJumping) {
        dinoY--;
        jumpHeight++;
        if (jumpHeight > 2) {
            isJumping = false;
        }
    } else if (dinoY < height - 1) {
        dinoY++;
    }

    obstacleX--;
    if (obstacleX < 0) {
        obstacleX = width - 1;
        score += 10;
    }

    if (obstacleX == dinoX && dinoY == height - 1) {
        gameOver = true;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(50); // Ralentiza el juego
    }
    cout << "Game Over!" << endl;
    cout << "Final Score: " << score << endl;
    return 0;
}

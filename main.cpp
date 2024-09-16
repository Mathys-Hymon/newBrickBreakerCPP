#include "raylib.h"
#include <iostream>
#include "GameManager.h"

GameManager gameManager;

void Start();
void Update();
void Draw();
void Unload();

int main() {

    gameManager = GameManager();
    Start();

    while (!WindowShouldClose()) {

        Update();
        Draw();
    }

    Unload();
    return 0;
}

void Start()
{
    InitWindow(1000, 850, "brick breaker");
    SetTargetFPS(60);
    gameManager.Load();
}

void Update()
{
    gameManager.Update();
}

void Draw()
{
    BeginDrawing();
    gameManager.Draw();
    ClearBackground(BLUE);
    EndDrawing();
}

void Unload()
{
    CloseWindow();
    gameManager.Unload();
}

#include <raylib.h>

int main(void) {
    // --- INICIALIZAÇÃO ---
    const int larguraTela = 800;
    const int alturaTela = 600;
    InitWindow(larguraTela, alturaTela, "Jogo da Cobrinha - por Enzo");
    SetTargetFPS(60);

    // --- ESTADO DO JOGO ---
    Vector2 tamanhoCobra = { 20, 20 };
    Vector2 posicaoCobra = { (float)larguraTela / 2, (float)alturaTela / 2 };
    Vector2 direcao = { tamanhoCobra.x, 0 };
    int contadorFrames = 0;

    // --- LOOP PRINCIPAL DO JOGO ---
    while (!WindowShouldClose()) {
        
        // --- 1. ATUALIZAÇÃO (UPDATE) ---
        if (IsKeyPressed(KEY_UP) && direcao.y == 0) direcao = (Vector2){ 0, -tamanhoCobra.y };
        if (IsKeyPressed(KEY_DOWN) && direcao.y == 0) direcao = (Vector2){ 0, tamanhoCobra.y };
        if (IsKeyPressed(KEY_LEFT) && direcao.x == 0) direcao = (Vector2){ -tamanhoCobra.x, 0 };
        if (IsKeyPressed(KEY_RIGHT) && direcao.x == 0) direcao = (Vector2){ tamanhoCobra.x, 0 };

        contadorFrames++;

        if (contadorFrames >= 10) {
            contadorFrames = 0;
            posicaoCobra.x += direcao.x;
            posicaoCobra.y += direcao.y;
        }

        // --- 2. DESENHO (DRAW) ---
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangleV(posicaoCobra, tamanhoCobra, GREEN);
        EndDrawing();
    }

    // --- FINALIZAÇÃO ---
    CloseWindow();
    return 0;
}
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
    
    Vector2 posicaocomida = { 0, 0 };
    Vector2 tamanhocomida = { 20, 20 };
    bool comidaAtiva = false;

    // Gera a primeira posição aleatória para a comida
    posicaocomida.x = GetRandomValue(0, (larguraTela / (int)tamanhoCobra.x) - 1) * tamanhoCobra.x;
    posicaocomida.y = GetRandomValue(0, (alturaTela / (int)tamanhoCobra.y) - 1) * tamanhoCobra.y;
    comidaAtiva = true;

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

        // Verificar colisão com a comida
        if (comidaAtiva && CheckCollisionRecs(
            (Rectangle){ posicaoCobra.x, posicaoCobra.y, tamanhoCobra.x, tamanhoCobra.y },
            (Rectangle){ posicaocomida.x, posicaocomida.y, tamanhocomida.x, tamanhocomida.y }
        )) {
            comidaAtiva = false;
        }

        // Se a comida não está ativa, gerar uma nova
        if (!comidaAtiva) {
            posicaocomida.x = GetRandomValue(0, (larguraTela / (int)tamanhoCobra.x) - 1) * tamanhoCobra.x;
            posicaocomida.y = GetRandomValue(0, (alturaTela / (int)tamanhoCobra.y) - 1) * tamanhoCobra.y;
            comidaAtiva = true;
        }

        // --- 2. DESENHO (DRAW) ---
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangleV(posicaoCobra, tamanhoCobra, GREEN);
            if (comidaAtiva) DrawRectangleV(posicaocomida, tamanhocomida, RED);
        EndDrawing();
    }

    // --- FINALIZAÇÃO ---
    CloseWindow();
    return 0;
}
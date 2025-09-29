#include <raylib.h>

int main(void) {
    // --- INICIALIZAÇÃO ---
    const int larguraTela = 800;
    const int alturaTela = 600;

    InitWindow(larguraTela, alturaTela, "Jogo da Cobrinha - por Enzo");
    SetTargetFPS(60);

    // --- ESTADO DO JOGO ---
    // Posição inicial da cabeça da cobra.
    Vector2 posicaoCobra = { (float)larguraTela / 2, (float)alturaTela / 2 };
    // Tamanho de cada segmento da cobra.
    Vector2 tamanhoCobra = { 20, 20 };

    // --- LOOP PRINCIPAL DO JOGO ---
    while (!WindowShouldClose()) {
        
        // --- 1. ATUALIZAÇÃO (UPDATE) ---
        // Verificamos se alguma tecla de seta está pressionada e movemos a cobra.
        if (IsKeyDown(KEY_RIGHT)) posicaoCobra.x += 2.0f;
        if (IsKeyDown(KEY_LEFT))  posicaoCobra.x -= 2.0f;
        if (IsKeyDown(KEY_UP))    posicaoCobra.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN))  posicaoCobra.y += 2.0f;

        // --- 2. DESENHO (DRAW) ---
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Desenha um retângulo verde na posição atual da cobra.
            DrawRectangleV(posicaoCobra, tamanhoCobra, GREEN);

        EndDrawing();
    }

    // --- FINALIZAÇÃO ---
    CloseWindow();

    return 0;
}
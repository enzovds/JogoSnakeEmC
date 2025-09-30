#include <raylib.h>
#include <stdio.h>

void ResetGame(int *tamanhoCorpo, Vector2 corpoCobra[], Vector2 *direcao, bool *gameOver, bool *comidaAtiva, Vector2 *posicaocomida, const int larguraTela, const int alturaTela, const Vector2 tamanhoCobra) {
    *tamanhoCorpo = 1;
    corpoCobra[0] = (Vector2){ (float)larguraTela / 2, (float)alturaTela / 2 };
    *direcao = (Vector2){ tamanhoCobra.x, 0 };
    *gameOver = false;
    *comidaAtiva = true;
    posicaocomida->x = GetRandomValue(0, (larguraTela / (int)tamanhoCobra.x) - 1) * tamanhoCobra.x;
    posicaocomida->y = GetRandomValue(0, (alturaTela / (int)tamanhoCobra.y) - 1) * tamanhoCobra.y;
}

int main(void) {
    const int larguraTela = 800;
    const int alturaTela = 600;
    InitWindow(larguraTela, alturaTela, "Jogo da Cobrinha - por Enzo");
    SetTargetFPS(60);

    Vector2 tamanhoCobra = { 20, 20 };
    Vector2 corpoCobra[256];
    int tamanhoCorpo = 1;
    Vector2 direcao;
    int contadorFrames = 0;
    
    Vector2 posicaocomida;
    bool comidaAtiva = false;
    bool gameOver = false;

    // Usando a função para configurar o estado inicial do jogo
    ResetGame(&tamanhoCorpo, corpoCobra, &direcao, &gameOver, &comidaAtiva, &posicaocomida, larguraTela, alturaTela, tamanhoCobra);

    while (!WindowShouldClose()) {
        if (!gameOver) {
            if (IsKeyPressed(KEY_UP) && direcao.y == 0) direcao = (Vector2){ 0, -tamanhoCobra.y };
            if (IsKeyPressed(KEY_DOWN) && direcao.y == 0) direcao = (Vector2){ 0, tamanhoCobra.y };
            if (IsKeyPressed(KEY_LEFT) && direcao.x == 0) direcao = (Vector2){ -tamanhoCobra.x, 0 };
            if (IsKeyPressed(KEY_RIGHT) && direcao.x == 0) direcao = (Vector2){ tamanhoCobra.x, 0 };

            contadorFrames++;

            if (contadorFrames >= 10) {
                contadorFrames = 0;
                for (int i = tamanhoCorpo - 1; i > 0; i--) {
                    corpoCobra[i] = corpoCobra[i-1];
                }
                corpoCobra[0].x += direcao.x;
                corpoCobra[0].y += direcao.y;

                if ((corpoCobra[0].x > (larguraTela - tamanhoCobra.x)) || (corpoCobra[0].x < 0) ||
                    (corpoCobra[0].y > (alturaTela - tamanhoCobra.y)) || (corpoCobra[0].y < 0)) {
                    gameOver = true;
                }
                for (int i = 1; i < tamanhoCorpo; i++) {
                    if (corpoCobra[0].x == corpoCobra[i].x && corpoCobra[0].y == corpoCobra[i].y) {
                        gameOver = true;
                    }
                }

                if (comidaAtiva && CheckCollisionRecs(
                    (Rectangle){ corpoCobra[0].x, corpoCobra[0].y, tamanhoCobra.x, tamanhoCobra.y },
                    (Rectangle){ posicaocomida.x, posicaocomida.y, tamanhoCobra.x, tamanhoCobra.y }
                )) {
                    comidaAtiva = false;
                    tamanhoCorpo++;
                }

                if (!comidaAtiva) {
                    posicaocomida.x = GetRandomValue(0, (larguraTela / (int)tamanhoCobra.x) - 1) * tamanhoCobra.x;
                    posicaocomida.y = GetRandomValue(0, (alturaTela / (int)tamanhoCobra.y) - 1) * tamanhoCobra.y;
                    comidaAtiva = true;
                }
            }
        } else {
            if (IsKeyPressed(KEY_ENTER)) {
                ResetGame(&tamanhoCorpo, corpoCobra, &direcao, &gameOver, &comidaAtiva, &posicaocomida, larguraTela, alturaTela, tamanhoCobra);
            }
        }
    // --- 2. DESENHO (DRAW) ---

    // ADICIONE ESTA LINHA DE DEBUG BEM AQUI
    printf("Status do Jogo: gameOver = %d\n", gameOver);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            for (int i = 0; i < tamanhoCorpo; i++) {
                DrawRectangleV(corpoCobra[i], tamanhoCobra, (i == 0) ? DARKGREEN : GREEN);
            }
            if (comidaAtiva) DrawRectangleV(posicaocomida, tamanhoCobra, RED);
            if (gameOver) {
                DrawText("GAME OVER", larguraTela / 2 - MeasureText("GAME OVER", 40) / 2, alturaTela / 2 - 40, 40, DARKGRAY);
                DrawText("Pressione [ENTER] para jogar novamente", larguraTela / 2 - MeasureText("Pressione [ENTER] para jogar novamente", 20) / 2, alturaTela / 2 + 10, 20, DARKGRAY);
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
#include <raylib.h>

int main(void) {
    // --- INICIALIZAÇÃO ---
    const int larguraTela = 800;
    const int alturaTela = 600;
    InitWindow(larguraTela, alturaTela, "Jogo da Cobrinha - por Enzo");
    SetTargetFPS(60);

    // --- ESTADO DO JOGO ---
    Vector2 tamanhoCobra = { 20, 20 };
    Vector2 corpoCobra[256];
    corpoCobra[0] = (Vector2){ (float)larguraTela / 2, (float)alturaTela / 2 };
    int tamanhoCorpo = 1;
    
    Vector2 direcao = { tamanhoCobra.x, 0 };
    int contadorFrames = 0;
    
    Vector2 posicaocomida = { 0, 0 };
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

            // Mover o corpo
            for (int i = tamanhoCorpo - 1; i > 0; i--) {
                corpoCobra[i] = corpoCobra[i-1];
            }
            // Mover a cabeça
            corpoCobra[0].x += direcao.x;
            corpoCobra[0].y += direcao.y;
        }

        // Verificar colisão com a comida
        if (comidaAtiva && CheckCollisionRecs(
            (Rectangle){ corpoCobra[0].x, corpoCobra[0].y, tamanhoCobra.x, tamanhoCobra.y },
            (Rectangle){ posicaocomida.x, posicaocomida.y, tamanhoCobra.x, tamanhoCobra.y }
        )) {
            comidaAtiva = false;
            tamanhoCorpo++; // A cobra cresce!
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
            
            // Desenha cada segmento do corpo da cobra
            for (int i = 0; i < tamanhoCorpo; i++) {
                DrawRectangleV(corpoCobra[i], tamanhoCobra, GREEN);
            }
            
            // Desenha a comida
            if (comidaAtiva) DrawRectangleV(posicaocomida, tamanhoCobra, RED);
        EndDrawing();
    }

    // --- FINALIZAÇÃO ---
    CloseWindow();
    return 0;
}
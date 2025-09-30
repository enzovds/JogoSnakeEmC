# Jogo da Cobrinha (Snake) em C com Raylib

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)
![Licença](https://img.shields.io/badge/Licen%C3%A7a-MIT-green.svg)

![Screenshot do Jogo da Cobrinha](https://i.imgur.com/S4RBA0s.png)

Este é um projeto clássico do Jogo da Cobrinha (Snake) desenvolvido do zero em linguagem C pura, utilizando a biblioteca `raylib` para gráficos e som. O objetivo principal foi o aprendizado prático dos fundamentos de desenvolvimento de jogos, incluindo o game loop, renderização, detecção de colisões e gerenciamento de estado.

---

## 🚀 Funcionalidades

* Movimento contínuo da cobra e controle de direção pelo jogador.
* Sistema de crescimento ao comer a comida, que reaparece em locais aleatórios.
* Detecção de colisão com as paredes da tela e com o próprio corpo.
* Condição de "Game Over" com opção de reinício do jogo.
* Sistema de pontuação em tempo real na tela.
* Efeitos sonoros para os eventos de comer e colidir.

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C
* **Biblioteca Gráfica/Multimídia:** [raylib](https://www.raylib.com/)
* **Compilador:** GCC (através do ambiente MSYS2/MinGW-w64)
* **Versionamento:** Git & GitHub

---

## ⚙️ Como Compilar e Executar

O projeto foi desenvolvido e testado no Windows (via MSYS2), mas é totalmente compatível com Linux.

### Pré-requisitos

* **No Windows (usando MSYS2):**
    ```bash
    pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-raylib
    ```

* **No Linux (Debian/Ubuntu):**
    ```bash
    sudo apt install build-essential libraylib-dev
    ```

### Compilação

Com os pré-requisitos instalados, clone o repositório e compile o projeto com o seguinte comando:

```bash
# Clone o repositório (se ainda não o fez)
git clone [https://github.com/enzovds/JogoSnakeEmC.git](https://github.com/enzovds/JogoSnakeEmC.git)
cd JogoSnakeEmC

# Compile o jogo
gcc snake.c -o snake -lraylib -lopengl32 -lgdi32 -lwinmm
```
(No Linux, o nome do executável geralmente é snake; no Windows, ele se torna snake.exe)

### Execução

Execute o programa gerado:
```bash
./snake
```
---

## 🕹️ Controles

* Setas Direcionais (Cima, Baixo, Esquerda, Direita): Mover a cobra.
* Enter: Reiniciar o jogo após o "Game Over".

---

## 📄 Licença

Este projeto está sob a Licença MIT.

---

Desenvolvido com dedicação por Enzo.
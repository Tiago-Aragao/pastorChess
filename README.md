# 🐺 Pastor vs. Lobo em C:
![Status do Projeto](https://img.shields.io/badge/status-em%20desenvolvimento-yellow)
![Linguagem](https://img.shields.io/badge/linguagem-C-blue)

## 🎮 O Jogo
O projeto gera uma matriz quadrada onde os elementos são distribuídos aleatoriamente. A cada rodada, os personagens se movem e as interações de "conflito" são resolvidas automaticamente.

### 👥 Personagens e Regras
| Personagem | Ícone | Ação Principal |
| :--- | :---: | :--- |
| **Lobo** | `L` | Mata a Ovelha (Ganha 1 ponto para o time) |
| **Pastor** | `P` | Salva a Ovelha (Ganha 1 ponto para o time)|
| **Ovelha** | `O` | Tenta sobreviver no mapa |
| **Obstaculo** | `#` | Apenas ocupa espaço no mapa sem se mecher |

### ⚔️ Lógica de Interação
* **Lobo + Ovelha:** O lobo elimina a ovelha. +1 ponto para os Lobos.
* **Pastor + Ovelha:** O pastor resgata a ovelha. +1 ponto para os Pastores.
* **Pastor + Lobo:** O pastor elimina o lobo do mapa. (Implementação futura)

### 🔧 Implementações:
* [x] Geração procedural do mapa e entidades.
* [x] Motor de movimento para ovelhas (Detecção de colisão).
* [x] Motor de caça e pontuação para Lobos.
* [ ] Motor de salvamento e pontuação para Pastores.
* [ ] Implementação de IA (Distância de Manhattan) e refinamento de UI.
* [ ] Pastor eliminar Lobo.

Clone o repositório e/ou execute o programa:
   ```bash
   # Clone o repositório
   git clone https://github.com/Tiago-Aragao/pastorChess.git
   # Compile os módulos
   gcc main.c funcoes_sistema.c funcoes_uteis.c -o simulação.exe
   # Execute
   ./simulação.exe
   ```

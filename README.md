# 🐺 Pastor vs. Lobo em C:
![Status do Projeto](https://img.shields.io/badge/status-em%20desenvolvimento-yellow)
![Linguagem](https://img.shields.io/badge/linguagem-C-blue)

## 🎮 O Jogo
O projeto gera uma matriz quadrada (20x20 futuramente será a escolha do jogador) onde os elementos são distribuídos aleatoriamente. A cada rodada, os personagens se movem e as interações de "conflito" são resolvidas automaticamente.

### 👥 Personagens e Regras
| Personagem | Ícone | Ação Principal |
| :--- | :---: | :--- |
| **Lobo** | `L` | Mata a Ovelha (Ganha 1 ponto para o time) |
| **Pastor** | `P` | Salva a Ovelha (Ganha 1 ponto para o time) ou Elimina o Lobo |
| **Ovelha** | `O` | Tenta sobreviver no mapa |
| **Obstaculo** | `#` | Apenas ocupa espaço no mapa sem se mecher |

### ⚔️ Lógica de Interação
* **Lobo + Ovelha:** O lobo elimina a ovelha. +1 ponto para os Lobos.
* **Pastor + Ovelha:** O pastor resgata a ovelha. +1 ponto para os Pastores.
* **Pastor + Lobo:** O pastor elimina o lobo do mapa.

### 🔧 Implementações Futuras
* [ ] Movimento não aleatório (inteligencia de distancia _provavelmente código manhattan_)
* [ ] Pastor ter pontos de vida onde ele perde um ponto sempre que elimina um lobo (_tentativa de quebrar o meta game de caça aos lobos caso ele venha a existir_)
* [ ] O usuario poder escolher o tamanho da matriz e/ou número de elementos como obstaculos, lobos, ovelhas e pastores
* [ ] Poderes para cada personagem: Ovelha se multiplicar em contato com outra, lobo se multiplicar em caso de contato com outro/ velocidade de movimento aumentada, pastor curar outro pastor em contato com outro
* [ ] Implementar novos personagens com funções unicas: Cachorro

1. Clone o repositório:
   ```bash
   git clone [https://github.com/Tiago-Aragao/pastorChess.git](https://github.com/Tiago-Aragao/pastorChess.git)

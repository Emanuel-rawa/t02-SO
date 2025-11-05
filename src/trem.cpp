#include "trem.h"
#include <QtCore>

QMutex Trem::regioes[7];

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Função a ser executada após executar trem->START
void Trem::run() {
    while (true) {
        switch (ID) {
        case 1:
            // exemplo de região crítica
            if (x == 300 && y == 30)
                regioes[0].lock();
            if (x == 310 && y == 150)
                regioes[0].unlock();
            // movimentação normal
            break;
            // repita para trens 2 a 6 com suas coordenadas e regiões
        }
        emit updateGUI(ID, x, y);
        msleep(velocidade);
    }
}

//Setter de velocidade
void Trem::setVelocidade(int v) {
    velocidade = 200 - v; // slider: 0 = parado, 200 = rápido
}





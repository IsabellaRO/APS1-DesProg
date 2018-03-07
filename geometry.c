#include <math.h>
#include <stdio.h>

#include "geometry.h"

//p = coordenadas do robô
//vetor de pontos poly = coordenadas dos cantos
//n = tamanho de poly
// 1 = robô (p) está na sala
//0 = não está

int verify(point p, point a, point b){
    float m = (float) (a.y - b.y) / (a.x - b.x);
    if(a.y >= b.y){
        if(a.y == p.y && a.x == p.x){
            return 1; //azul
        }
        else if(b.x == p.x && b.y == p.y){
            return 0; //vermelha
        }
        else if((p.y - a.y) == m * (p.x - a.x)){ //Confere se está em cima da parede
            float j = m * (p.x - a.x);
            printf ("pt2: %f", j);
            return 2; //preta
        }
        else{
            return 0; //vermelha
        }
    }
    if(b.y >= a.y){
        if(b.y == p.y && b.x == p.x){
            return 1; //azul
        }
        else if(a.x == p.x && a.y == p.y){
            return 0; //vermelha
        }
        else if((p.y - a.y) == m * (p.x - a.x)){ //Confere se está em cima da parede
            float j = m * (p.x - a.x);
            float k = (p.y - a.y);
            printf ("pt2: %f, %f", j, k);
            return 2; //preta
        }
        else{
            return 0; //vermelha
        }
    }

    else{
    return 3; }
}

int inside(point p, point poly[], int n){
    return 0;
}

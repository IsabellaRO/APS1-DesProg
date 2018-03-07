#include <math.h>
#include <stdio.h>
#include "geometry.h"

//p = coordenadas do robô
//vetor de pontos poly = coordenadas dos cantos
//n = tamanho de poly
// 1 = robô (p) está na sala
//0 = não está

int verify(point p, point a, point b)
{
    float m = (float)(a.y - b.y) / (a.x - b.x);
    if (a.y >= b.y)
    {
        if (a.y == p.y && a.x == p.x)
        {
            printf("na ponta, dentro\n");
            return 1; //azul
        }
        else if (b.x == p.x && b.y == p.y)
        {
            printf("na ponta, fora\n");
            return 0; //vermelha
        }
        else if (((p.y - a.y) == m * (p.x - a.x)) && p.y < a.y && p.y > b.y)
        { //Confere se está em cima da parede
            float j = m * (p.x - a.x);
            printf("em cima\n");
            return 2; //preta
        }
        else
        {
            return 0; //vermelha
        }
    }
    if (b.y >= a.y)
    {
        // if(b.y == p.y && b.x == p.x){
        //     if (a.x > b.x){
        //         if ()
        //     }
        //     else{
        //     }
        // }
        if (a.x == p.x && a.y == p.y)
        {
            return 0; //vermelha
        }
        else if (((p.y - a.y) == m * (p.x - a.x)) && p.y < b.y && p.y > a.y)
        { //Confere se está em cima da parede e intervalo em y
            float j = m * (p.x - a.x);
            float k = (p.y - a.y);
            printf("pt2: %f, %f\n", j, k);
            return 2; //preta
        }

        else if (((p.y - a.y) == m * (p.x - a.x)) && p.y == b.y && p.x == b.x)
        { //Confere se está em cima da parede e ponto b
            float j = m * (p.x - a.x);
            float k = (p.y - a.y);
            printf("pt2: %f, %f\n", j, k);
            return 2; //preta
        }

        // else if(((p.y - a.y) == m * (p.x - a.x)) && p.y == a.y && p.x == a.x){ //Confere se está em cima da parede e ponto b
        //     float j = m * (p.x - a.x);
        //     float k = (p.y - a.y);
        //     printf ("pt2: %f, %f\n", j, k);
        //     return 2; //preta
        // }

        else if (p.y < b.y && p.y > a.y)
        { //Checando se p está no intervalo em y

            if (p.y = b.y)
            { // O ponto está no mesmo y mas x diferente do ponto b
                if (p.x > b.x && p.x > a.x) //calcular o ponto da reta usando a eq.
                {
                    return 0;
                }
                else
                {
                    printf("sss");
                    return 1;
                }
            }
            else
            {
                return 0; // O ponto está no mesmo y mas x diferente do ponto a
            }
        }

        else
        {
            return 0; //vermelha
        }
    }

    else
    {
        return 0;
    }
}

int inside(point p, point poly[], int n)
{
    return 0;
}

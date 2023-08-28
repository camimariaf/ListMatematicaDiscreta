/*Escrever um programa para encontrar a solução única de três congruências usando
o Teorema Chinês do Resto. (Lembre-se de verificar se os módulos são coprimos).*/

#include <stdio.h>

int modinverso(int a, int m)
{
    int m_i = m, t, q; //m_i m inicial
    int x_i = 0, x1 = 1; // x_1 x inicial

    if (m == 1)
        return 0;

    while (a > 1) {
        //q é o quociente da divisão a / m
        q = a / m;
        t = m;

        //m é o resto da divisão a / m
        m = a % m;
        a = t;
        t = x_i;

        // Atualiza x_i e x1
        x_i = x1 - q * x_i;
        x1 = t;
    }

    // Se x1 for negativo, adiciona m até ficar positivo
    if (x1 < 0)
        x1 += m_i;

    return x1;
}

int main() {

    int a1, a2, a3;
    int m1, m2, m3;
    int M1, M2, M3;
    int y1, y2, y3;
    int x;

    printf("Segundo o sistema de congruencia x ≡ a1 (mod m1);\n");
    printf("Digite os valores para a1 e m1:\n ");
    scanf("%d %d",&a1, &m1);
    printf("Digite os valores para a2 e m2:\n ");
    scanf("%d %d",&a2, &m2);
    printf("Digite os valores para a3 e m3:\n ");
    scanf("%d %d",&a3, &m3);


    // Calcula M1, M2, M3 e x
    M1 = m2 * m3;
    M2 = m1 * m3;
    M3 = m1 * m2;
    x = (a1 * M1 * modinverso(M1, m1) + a2 * M2 * modinverso(M2, m2) + a3 * M3 * modinverso(M3, m3)) % (m1 * m2 * m3);

    // Calcula y1, y2, y3
    y1 = x % m1;
    y2 = x % m2;
    y3 = x % m3;

    // Imprime a solução
    printf("x = %d (mod %d)\n", y1, m1);
    printf("x = %d (mod %d)\n", y2, m2);
    printf("x = %d (mod %d)\n", y3, m3);
    printf("x = %d e a solucao unica das congruencias.\n", x);

    return 0;
}
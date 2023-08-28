/*Generalize o programa da questão anterior para funcionar com n congruências ao
invés de somente 3, onde n será dado pelo usuário.*/

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
    int n;
    printf("Digite o numero de congruencias: ");
    scanf("%d", &n);

    int a[n], m[n], M[n], y[n];
    int x = 0;

    for (int i = 0; i < n; i++) {
        printf("Digite os valores para a%d e m%d: ", i + 1, i + 1);
        scanf("%d %d", &a[i], &m[i]);
    }

    // Calcula M
    int prodM = 1;
    for (int i = 0; i < n; i++) {
        prodM *= m[i];
    }

    for (int i = 0; i < n; i++) {
        M[i] = prodM / m[i];
        y[i] = M[i] * modinverso(M[i], m[i]);
        x += a[i] * y[i];
    }

    x %= prodM;

    // Imprime as soluções
    for (int i = 0; i < n; i++) {
        printf("x = %d (mod %d)\n", y[i], m[i]);
    }
    printf("x = %d e a solucao unica das congruencias.\n", x);

    return 0;
}
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string ConcatERemove(char *s, char *t, int k)
{
    int tam_s = strlen(s), tam_t = strlen(t);
    int movimentos = 0; //Contador para comparar com k.
    int op; //Para salvar processamento vamos determinar o valor de op

    if(tam_s >= tam_t) //O maior numero de operacoes que podemos vir a fazer é igual ao tamanho do maior vetor.
    {
        op = tam_s;
        for(int i = 0; i < op; i++) //O if dentro do for muda dependendo do tamanho do vetor.
        {
            printf("Comparando s -> t  |  %c -> %c \n", s[op - 1 - i], t[op - 1 - i]);
            if(s[op - 1 - i] != t[op - 1 - i]) //&& s[op - 1 + i] != '\0') //&& t[op - 1 + i] != '\0'
            {
                s[op - 1 - i] = '\0';
                movimentos++; //Apenas se removermos um caracter que um movimento será contado.
            }
        }
    }
    else
    {
        op = tam_t;
        for(int i = 0; i < op; i++) //O if dentro do for muda dependendo do tamanho do vetor.
        {
            printf("Comparando s -> t  |  %c -> %c \n", s[op - 1 - i], t[op - 1 - i]);
            if(s[op - 1 - i] != t[op - 1 - i] && s[op - 1 + i] != '\0') //&& t[op - 1 + i] != '\0'
            {
                s[op - 1 - i] = '\0';
                movimentos++; //Apenas se removermos um caracter que um movimento será contado.
            }
        }
    }

    if(movimentos > k) //Salva processamento caso só a operação remover já estoure nosso k.
    {
        return "nao";
    }
    tam_s = strlen(s); //Apos a remoção, a string s terá um novo tamanho.
    op = abs(tam_s - tam_t); //Otimiza o for, a diferença entre os vetores é o máximo de operações que irá ocorrer.

    for(int i = 0; i < op; i++)
    {
        if(s[tam_s + i] != t[tam_s + i] && t[tam_s + i] != '\0')
        {
            s[tam_s + i] = t[tam_s + i];
            printf("Novo string s:  %s\n", s);
            movimentos++;
        }
    }

    if(movimentos > k) //Checa se o numero de operações é possível.
    {
        printf("movimentos: %i\n", movimentos);
        return "nao";
    }

    printf("movimentos usados: %i\n", movimentos);
    return "sim";
}

int main()
{
    char s[101], t[101]; //O último caractere é de final "\0". Então para que realmente possamos ter 100 caracteres disponiveis o indice usado é 101.
    int k;

    //Deve-se checar os dois juntos, senão pode causar overflow.
    do{
    printf("Escreva a string desejada para s, ela deve conter pelo menos um caractere e no maximo 100 caracteres\n");
    scanf("%s", &s);

    printf("Escreva a string desejada para t, ela deve conter pelo menos um caractere e no maximo 100 caracteres\n");
    scanf("%s", &t);

    }while(strlen(s) < 1 || strlen(s) > 100 || strlen(t) < 1 || strlen(t) > 100);

    //Limpa os vetores da string para mais fácil comparação.
    int tam_s = strlen(s), tam_t = strlen(t);
    for(int i = 0; i < 100 - tam_s; i++)
    {
        s[tam_s + i] = '\0';
    }
    for(int i = 0; i < 100 - tam_t; i++)
    {
        t[tam_t + i] = '\0';
    }

    do{
        printf("Em quantas operacoes?\n");
        scanf("%i", &k);
    }while(k < 1 || k > 100);
    printf("\n");

    cout << ConcatERemove(s, t, k) << endl;

    return 0;
}

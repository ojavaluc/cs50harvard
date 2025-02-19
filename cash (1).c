#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Pontuação das letras
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Função para calcular a pontuação de uma palavra
int compute_score(string word);

int main(void)
{
    // Solicita a entrada dos jogadores
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calcula a pontuação das palavras
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determina o vencedor
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Mantém a pontuação
    int score = 0;

    // Calcula a pontuação para cada caractere
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}


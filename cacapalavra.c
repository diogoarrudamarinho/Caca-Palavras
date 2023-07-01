#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Player{

    char nome[50];
    int pontos;

}player;

void gerarPuzzle(char puzzle[10][10]){

    int seed;

    printf("Digite a seed: ");
    scanf("%d", &seed);
    
    srand(seed);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            char character = (char)(rand() % 26) + 'A';
            puzzle[i][j] = character;
        }   
    }
}

void imprimirPuzzle(char puzzle[10][10]){

    printf("\nCaça Palavras:\n");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            printf("%c  ", puzzle[i][j]);
         
        printf("\n");
    }
    printf("\n");
}

player lerPlayer(){

    player p;

    fflush(stdin);

    printf("Digite o nome do Jogador: ");
    fgets(p.nome, 50, stdin);
    
    
    p.nome[strcspn(p.nome, "\n")] = 0; /* Função para tirar o '\n' do final da string */

    p.pontos = 0;

    return p;
}

int verificaHorizontal(char puzzle[10][10], char palavra[], player* p){

    int indicePalavra = 0;
    int indiceFinal = strlen(palavra) - 2;
    int found = 0;
    int endPalavra = indiceFinal;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (puzzle[i][j] == palavra[indicePalavra])
            {
                indicePalavra = 1;

                for (int k = j+1; k < (strlen(palavra) + j); k++, indicePalavra++)
                {
                    if (palavra[indicePalavra] != '\n')
                    {
                        if(k == 10 || puzzle[i][k] != palavra[indicePalavra])
                        {
                            indicePalavra = 0;
                            break;
                        }

                    }else 
                    {
                        printf("Palavra encontrada na HORIZONTAL %d %d\n", i, j);
                        p->pontos++;
                        indicePalavra = 0;
                        found = 1;
                        break;
                    }
                }

            } 
            
            else if (puzzle[i][j] == palavra[endPalavra])
            {
                endPalavra--; 

                for (int k = j+1; k < (strlen(palavra) + j); k++, endPalavra--)
                {
                    if (endPalavra >= 0)
                    {
                        if(k == 10 || puzzle[i][k] != palavra[endPalavra])
                        {
                            endPalavra = indiceFinal;
                            break;
                        }

                    }else 
                    {
                        printf("Palavra encontrada DE TRAS PARA FRENTE na HORIZONTAL %d %d\n", i, j);
                        p->pontos++;
                        endPalavra = indiceFinal;
                        found = 1;
                        break;
                    }
                }
            }
        }
    }

    return found;
}

int verificaVertical(char puzzle[10][10], char palavra[], player* p){

    int indicePalavra = 0;
    int indiceFinal = strlen(palavra) - 2;
    int found = 0;
    int endPalavra = indiceFinal;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (puzzle[i][j] == palavra[indicePalavra])
            {
                indicePalavra = 1;

                for (int k = i+1; k < (strlen(palavra) + i); k++, indicePalavra++)
                {
                    if (palavra[indicePalavra] != '\n')
                    {
                        if(k == 10 || puzzle[k][j] != palavra[indicePalavra])
                        {
                            indicePalavra = 0;
                            break;
                        }

                    }else 
                    {
                        printf("Palavra encontrada na VERTICAL %d %d\n", i, j);
                        p->pontos++;
                        indicePalavra = 0;
                        found = 1;
                        break;
                    }
                } 
            }
            
            else if (puzzle[i][j] == palavra[endPalavra])
            {
                endPalavra--; 

                for (int k = i+1; k < (strlen(palavra) + i); k++, endPalavra--)
                {
                    if (endPalavra >= 0)
                    {
                        if(k == 10 || puzzle[k][j] != palavra[endPalavra])
                        {
                            endPalavra = indiceFinal;
                            break;
                        }

                    }else 
                    {
                        printf("Palavra encontrada DE TRAS PARA FRENTE na VERTICAL %d %d\n", i, j);
                        p->pontos++;
                        endPalavra = indiceFinal;
                        found = 1;
                        break;
                    }
                }
            }  
        }   
    }

    return found;
}

int verificaDiagonal(char puzzle[10][10], char palavra[], player* p){

    int indicePalavra = 0;
    int indiceFinal = strlen(palavra) - 2;
    int found = 0;
    int endPalavra = indiceFinal;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (puzzle[i][j] == palavra[indicePalavra])
            {
                indicePalavra = 1;

                for (int k = i+1, l = j+1; (k < (strlen(palavra) + i)) && (l < (strlen(palavra) + j)); k++, l++, indicePalavra++)
                {
                    if (palavra[indicePalavra] != '\n')
                    {
                        if( (k == 10 || l == 10) || (puzzle[k][l] != palavra[indicePalavra]) )
                        {
                            indicePalavra = 0;
                            break;
                        }

                    }else 
                    {
                        printf("Palavra encontrada na DIAGONAL %d %d\n", i, j);
                        p->pontos++;
                        indicePalavra = 0;
                        found = 1;
                        break;
                    }
                } 
            }else if (puzzle[i][j] == palavra[endPalavra])
            {
                endPalavra--; 

                for (int k = i+1, l = j+1; (k < (strlen(palavra) + i)) && (l < (strlen(palavra) + j)); k++, l++, endPalavra--)
                {
                    if (endPalavra >= 0)
                    {
                        if( (k == 10 || l == 10) || puzzle[k][l] != palavra[endPalavra])
                        {
                            endPalavra = indiceFinal;
                            break;
                        }

                    }else 
                    {
                        printf("Palavra encontrada DE TRAS PARA FRENTE na DIAGONAL %d %d\n", i, j);
                        p->pontos++;
                        endPalavra = indiceFinal;
                        found = 1;
                        break;
                    }
                }
            }  
        }   
    }

    return found;
}

int verificaPalavra(char puzzle[10][10], char palavra[], player* p){

    int foundHorizontal = verificaHorizontal(puzzle, palavra, p);
    int foundVertical = verificaVertical(puzzle, palavra, p);
    int foundDiagonal = verificaDiagonal(puzzle, palavra, p);

    return (foundHorizontal || foundVertical || foundDiagonal); 
}

void lerJogadas(char puzzle[10][10], int qtdJogadores, player p[]){

    int loop = 1;
    char palavra[11];

    do
    {
        for (int i = 0; i < qtdJogadores; i++)
        {
            fflush(stdin);
            printf("\n%s, digite uma palavra: ", p[i].nome);
            fgets(palavra, 11, stdin);

            if ( (i == 0) && (palavra[0] == '.') )
            {
                loop = 0;
                break;
            }else
            {
                if (!verificaPalavra(puzzle, palavra, &p[i]))
                {
                    printf("Palavra não encontrada!\n");
                    p[i].pontos--;
                }
            }
        }
        
    } while (loop);
}

void imprimeGanhadores(player p[], int qtdJogadores){

    int qtdEmpates = 0;
    int indicesEmpate[qtdJogadores];
    int maior = p[0].pontos;

    indicesEmpate[qtdEmpates++] = 0;

    for (int i = 1; i < qtdJogadores; i++)
    {
        if (p[i].pontos > maior)
        {
            maior = p[i].pontos;
            qtdEmpates = 0;
            indicesEmpate[qtdEmpates++] = i;
        }
        else if (p[i].pontos == maior)
        {
            indicesEmpate[qtdEmpates++] = i;
        }
    }

    printf("\nVencedor(es): ");
    for (int i = 0; i < qtdEmpates; i++)
    {
        int indice = indicesEmpate[i];

        if (i == qtdEmpates - 1)
            printf("%s", p[indice].nome);
        else     
            printf("%s, ", p[indice].nome);
    }
}

int main(){

    char puzzle[10][10];

    gerarPuzzle(puzzle);
    imprimirPuzzle(puzzle);

    int qtdJogadores;

    printf("Digite a quantidade de jogadores: ");
    scanf("%d", &qtdJogadores);

    player players[qtdJogadores];

    for (int i = 0; i < qtdJogadores; i++)
        players[i] = lerPlayer();    

    lerJogadas(puzzle, qtdJogadores, players);

    imprimeGanhadores(players, qtdJogadores);
    
    return 0;
}
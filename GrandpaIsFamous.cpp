#include <bits/stdc++.h>
// Felipe Ferreira Alves - 2021020653
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int main(){
    int rank,qtd;
    int **players;
    int *vetor;
    int x =0;
    while (1)
    {
        scanf("%d %d", &rank,&qtd);
        x = 0;
        if (rank ==0 && qtd ==0){
            break;
        }

        players = (int **) malloc(rank*sizeof(int*)); // Alocando as linhas (qtd de ranking)

        for(int i=0;i<rank;i++){ // Alocando a quantidade de jogadores por ranking
            players[i] = (int *) malloc (qtd *sizeof(int));
        }

        for(int i=0;i<rank;i++){ // Populando a matriz
            for(int j=0;j<qtd;j++){
                scanf("%d",&players[i][j]);
            }
        }

        vetor = (int * ) malloc ((rank*qtd) * sizeof(int));

        for(int i=0;i<rank;i++){ // passa a matriz para um vetor
            for(int j=0;j<qtd;j++){
                vetor[x] = players[i][j];
                x++;
            }
        }

        int tam = (qtd*rank);
        qsort(vetor, rank * qtd, sizeof(int), compare);

        // Fazer agora uma matriz [tam][2], sendo o [x][0] para guardar o numero e o [x][1] para guardar as x que repetiu

        int repete[tam][2];
        int ocorrencia = 1; //Ocorrencias do numero
        int linha = 0; //controla a linha da matriz repete

        for(int i=0;i<tam;i++){
            if (vetor[i] == vetor[i+1]){
                ocorrencia++;
            } else{ 
                repete[linha][0] = vetor[i]; // qual numero
                repete[linha][1] = ocorrencia; // vezes que repetiu
                ocorrencia = 1;
                linha++;
            }
        }

        int maior =0;
        int segMaior =0;

        for(int i=0;i<linha;i++){ // achar o maior
            if (repete[i][1] > maior){
                maior = repete[i][1];
            }
        }

        for(int i=0;i<linha;i++){ // achar o segundo maior
            if (repete[i][1] > segMaior && repete[i][1] < maior){
                segMaior = repete[i][1];
            }
        }


        for(int i=0;i<linha;i++){ // printa a lista
            if (repete[i][1] == segMaior){
                printf("%d ",repete[i][0]);
            }
        }
        printf("\n");
    }
    
    
    return 0;
}
#include <stdio.h>
#define TAM 10
int root(int atual, int vetor[TAM]){
	if(vetor[atual] == atual)
		return atual;
	else
		vetor[atual] = vetor[vetor[atual]];
		return root(vetor[atual], vetor);
}
void connect(int atual, int target, int vetor[TAM], int altura[TAM]){
	int i = root(atual, vetor), j = root(target, vetor);
	if(altura[i] < altura[j]){
		vetor[i] = j;
		altura[j] += altura[i];
	}
	else{
		vetor[j] = i;
		altura[i] += altura[j];
	}
}
int isConnected(int A, int B, int vetor[TAM]){
	if(root(A, vetor) == root(B, vetor)){
		return 1;
	}
	else{
		return 0;
	}
}
void printArray(int vetor[TAM]){
	for(int i = 0; i < TAM; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}
int main() {
  int vetor[TAM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int altura[TAM] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  connect(4, 3, vetor, altura);
  connect(3, 8, vetor, altura);
  connect(6, 5, vetor, altura);
  connect(9, 4, vetor, altura);
  connect(2, 1, vetor, altura);
  connect(5, 0, vetor, altura);
  connect(7, 2, vetor, altura);
  connect(6, 1, vetor, altura);
  connect(7, 3, vetor, altura);
  printArray(vetor);
  printArray(altura);
  for(int i = 0; i < TAM; i++){
	  for(int j = 0; j < TAM; j++){
		  printf("Is %d connected with %d ? %d\n", i, j, isConnected(i, j, vetor));
	  }
  }
}
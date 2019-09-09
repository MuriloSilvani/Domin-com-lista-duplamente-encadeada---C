#include <stdio.h>
#include <stdlib.h>

typedef struct pecaDomino{
	int valores[2];
	pecaDomino *proxima, *anterior;
}pecaDomino;

void mostrarPecas(pecaDomino *listaQueVaiSerMostrada);

pecaDomino *inicializarLista();

pecaDomino *inserirPeca(pecaDomino *listaQueRecebePeca, int valor1, int valor2);

/////////////////////////////////////////////////////////////////////////////// 

int main(){
	
	pecaDomino *monte = inicializarLista();
	
	
	while(true){
		int valor1, valor2;
		printf("valor 1 e 2:\n");
		scanf("%i %i", &valor1, &valor2);
		
		monte = inserirPeca(monte, valor1, valor2);
		
		mostrarPecas(monte);
	}

	
	return 0;
};

/////////////////////////////////////////////////////////////////////////////// 


pecaDomino *inicializarLista(){
	return NULL;
};

pecaDomino *inserirPeca(pecaDomino *listaQueRecebePeca, int valor1, int valor2){
	pecaDomino *novaPeca = (pecaDomino*) malloc(sizeof(pecaDomino));
	novaPeca->valores[0] = valor1;
	novaPeca->valores[1] = valor2;
	
	if(listaQueRecebePeca == NULL){
		novaPeca->proxima = NULL;
		novaPeca->anterior = NULL;
		printf("RECEBEU EM LISTA VAZIA\n");
		return novaPeca;
	}else{
		novaPeca->proxima = listaQueRecebePeca;
		novaPeca->anterior = NULL;
		listaQueRecebePeca->proxima = novaPeca;
		printf("RECEBEU NORMAL\n");
		return novaPeca;
	};
	return listaQueRecebePeca;
};

void mostrarPecas(pecaDomino *listaQueVaiSerMostrada){
	if(listaQueVaiSerMostrada == NULL){
		printf("A lista nao contem itens\n");
		return;
	};
	
	for(int i = 0; listaQueVaiSerMostrada->proxima != NULL; i++){
		printf("[%i|%i]\n", listaQueVaiSerMostrada->valores[0], listaQueVaiSerMostrada->valores[1]);
		listaQueVaiSerMostrada = listaQueVaiSerMostrada->proxima;
	};
};









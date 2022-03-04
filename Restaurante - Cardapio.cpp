#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
 	bool is_finalizar(){
 		char finalizar;
 		system("color 5");
 		printf("[f] - finalizar pedido ou [a] - alterar pedido \n");
 		scanf(" %c", &finalizar);
		if(finalizar=='f'){
			return false;
		}else{
			return true;
	
		} 
	 }
 	
 	void listar_ingredientes(char ingredientes[10][50], int menu_ingredientes[10][10], int index){
 		
		printf("------------- \n");
		printf("  %s \n",ingredientes[menu_ingredientes[index][0]]);
		printf("  %s \n",ingredientes[menu_ingredientes[index][1]]);	
		printf("  %s \n\n\n",ingredientes[menu_ingredientes[index][2]]);
 	
	 }
	 
	void listar_pratos(char menu[10][50]){
		
		printf("[%d] - %s \n",0,menu[0]);
		printf("[%d] - %s \n",1,menu[1]);
		printf("[%d] - %s \n\n\n\n",2,menu[2]);
	}
 	
 	int selecionar_cardapio(char menu[10][50]){
		int menu_selecao;
		scanf(" %d", &menu_selecao);
		switch(menu_selecao){
			case 0:
			case 1:
			case 2:
				printf("seu pedido foi incluido \n");
				printf("[%d] - %s \n",menu_selecao,menu[menu_selecao]);
				
				FILE *f;
				f=fopen("pedido.txt", "w+");
				fprintf(f, menu[menu_selecao]);
				fputs("", f);
				fclose(f);
				
				return menu_selecao;	
				break;
										
			default:		
				printf("opcao invalida, escolha uma das opcoes > 0, 1 ou 2 \n");
				//validar_menu = true;
		}
	}
 
 int main() {
 	
 	char finalizar;
 	bool validar_menu = true;
	bool continuar = true;
 	char menu_selecao = 'x';
 	char cardapio_pedido;
 	
 	char menu[10][50]={
		{"strogonoff = 10,00$"},
	 	{"feijoada =  15,00$"},
	 	{"lasanha = 9,90$"}
	};	
 	char ingredientes[10][50]={
		{"arroz"},
		{"frango"},
		{"catchup"},
		{"feijao"},
		{"carne"},
		{"farofa"},
		{"massa"},
		{"molho"},
		{"queijo"}
	};
 	int menu_ingredientes[10][10];
 	menu_ingredientes[0][0]=0;
	menu_ingredientes[0][1]=1;
	menu_ingredientes[0][2]=2;
	menu_ingredientes[1][0]=3;
	menu_ingredientes[1][1]=4;
	menu_ingredientes[1][2]=5;
	menu_ingredientes[2][0]=6;
	menu_ingredientes[2][1]=7;
	menu_ingredientes[2][2]=8;
	
	printf("======================= Ola, seja bem-vindo(a) ao nosso restaurante! realize seu pedido aqui ===========================\n\n");
	system("color 9");
	printf("[c] - ver cardapio completo\n\n");
	printf("[p] - selecione um prato\n\n");
	printf("[e] - excluir um pedido\n\n");
	printf("============================================== selecione uma opcao: ==================================================== \n"); 
	scanf(" %c", &cardapio_pedido);

		
	while(continuar==true) {
		
		if (cardapio_pedido=='c'){
			
				printf("%s \n",menu[0]);
				listar_ingredientes(ingredientes, menu_ingredientes, 0);
				
				printf("%s \n",menu[1]);
				listar_ingredientes(ingredientes, menu_ingredientes, 1);
				
				printf("%s \n",menu[2]);
				listar_ingredientes(ingredientes, menu_ingredientes, 2);
				
				printf("selecione um prato\n\n");
				
				cardapio_pedido = 'p';
				
		}else if(cardapio_pedido=='p'){
		
				continuar = false;
				listar_pratos(menu);
				menu_selecao = selecionar_cardapio(menu);
				continuar = is_finalizar();

		}else if(cardapio_pedido=='e'){
			
				if(remove("pedido.txt")==0){
					system("color 4");
					printf("seu pedido foi excluido com sucesso!");
				
				} else{
						system("color 6");
					printf("o pedido nao pode ser excluido, por favor comunique nosso garcom");
				}
				return 0;
		}
					
		else{
			printf("opcao invalida, escolha uma das opcoes > c ou p \n");
			scanf(" %c", &cardapio_pedido);
		}
	
	}
	
	
	return 0;
				
}

 

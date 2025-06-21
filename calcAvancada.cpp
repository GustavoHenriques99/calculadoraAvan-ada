#include <stdio.h>
#include <string.h>
#include <ctype.h>

void converterTemp(int escolha){

    int escOperacao;
    float temp;
    float convercao;

    printf("\n\n===== CONVERCAO DE TEMPERATURA ====\n");
    printf("Opcao 1 - Converter de Celsius para Fahrenheit \nOpcao 2 - Converter de Fahrenheit para Celsius\n\n: ");

    scanf("%d", &escOperacao);

    if(escOperacao == 1){
        printf("Entre com a temperatura em Celsius: ");
        scanf("%f", &temp);

        //C para F
        convercao = (temp * 1.8) + 32;

        printf("%.2f", convercao);
    }else if (escOperacao == 2){
        printf("Entre com a temperatura em Fahrenheit: ");
        scanf("%f", &temp);

        //F para C
        convercao = (temp - 32) / 1.8;

        printf("%.2f", convercao);
    }
}

void areaFigura (int escolha){
	
    char letra[2];
    float b;
    float a;
    float pi = 3.141592653; 
    float area;
    float raio;

        printf("\n\n===== CALCULAR AREA GEOMETRICA =====\n");
        printf("A - Triangulo (base x altura / 2) \nB - Retangulo (base x altura) \nC - Circulo (pi x raio^2)\n\n: "); 
            
        scanf("%s", letra);
    
        if (strcmp(letra, "a") == 0 || strcmp(letra, "A") == 0){

            printf("\n--TRIANGULO");
            printf("\nBase:");
            scanf("%f", &b);

            printf("Altura: ");
            scanf("%f", &a);

            area = ((b * a) / 2);

            printf("\n\nArea do triangualo: %.3f", area);
        } else if (strcmp(letra, "b") == 0 || strcmp(letra, "B") == 0){
                
            printf("\n--RETANGULO");
            printf("\nBase:");
            scanf("%f", &b);

            printf("Altura: ");
            scanf("%f", &a);

            area = ((b * a));

            printf("\n\nArea do Retangulo: %.3f", area);

        } else if(strcmp(letra, "c") == 0 || strcmp(letra, "C") == 0){
                
            printf("\n--Circulo");
            printf("\nRaio: ");
            scanf("%f", &raio);
                
            area = (pi * (raio * raio));

            printf("\n\nArea do Circulo: %.3f", area);
        }
    }


void contPalavra(int escolha){

    char frase[999];
    int comSemEspaco;
    int quant = 0;

    printf("\n\n===== CONTA TAMANHO DA FRASE =====\n");
    printf("Opcao 1 - Frase com espaco\nOpcao 2 - Frase sem espaco \n\n:"); 
        
    scanf("%d", &comSemEspaco);

    getchar();
    // Contando frase com espaco
    if(comSemEspaco == 1){
            
        printf("\nFrase: ");
        fgets(frase, 999, stdin);

        for(int i = 0; i < strlen(frase); i++){
            if(frase[i] != '\n'){
                quant++;
            }
        }

        printf("\n\nQuantidade de caracteres: %d", quant);
    }

    // Contando frase desconsiderando o espaco
    if (comSemEspaco == 2){
        printf("\nFrase: ");
        fgets(frase, sizeof(frase), stdin);

        for(int i = 0; i < strlen(frase); i++){
            if(frase[i] != ' ' && frase[i] != '\n'){
                quant++;
            }
        }
            printf("\n\nQuantidade de palavras sem espaco: %d", quant);
    }
}


void verificaPalindromo(int escolha){
    char texto[999];
    char newTexto[999];
    int cont = 0;
    int palindromo = 1;

        printf("\n\n===== VERIFICAR PALINDROMO =====\n");
        printf("Digite um texto: ");
        getchar(); 
        fgets(texto, 999, stdin);
        texto[strlen(texto) - 1] = '\0';


        for (int i = 0; i < strlen(texto); i++){
            if(texto[i] != ' '){
                newTexto[cont] = tolower(texto[i]); // deixando minusculo
                cont++;
            }
        } 
        newTexto[cont] = '\0'; // Finaliza a nova string

        for (int i = 0; i < strlen(newTexto)/2; i++) {
            if (newTexto[i] != newTexto[cont - i - 1]) {
                palindromo = 0;
            }
        }

        if(palindromo == 1){
            printf("\nO texto informado e um palindromo.\n");
        } else {
            printf("\nO texto informado nao e um palindromo.\n");
            }
    }

int main(){
    int numb;

    do {
        printf("\n\n----------------\n1 - Converter Temperatura (Celsius - Fahrenheit)   \n2 - Calcular area de figura geometricas \n3 - Contar o tamanho de uma frase \n4 - verificar se um texto e palindromo \n0 - Sair \n\n: ");
    
        scanf("%d", &numb);

        if (numb < 0 || numb > 4) {
        printf("Opcao invalida. Tente novamente.\n");
        
   		}
   		
    	switch (numb){
    		case 1:
    			converterTemp(numb);
    			break;
   			case 2:
    			areaFigura(numb);
    			break;
    		case 3:
    			contPalavra(numb);
    			break;
   			case 4:
    			verificaPalindromo(numb);
    			break;	
    	}
	}while(numb !=0);    
  	
	return 0;
}

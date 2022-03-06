#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
long long int inverso(long long int a, long long int m) 
{ 
    a = a%m; 
    for (int x=1; x<m; x++) 
    {
       if ((a*x) % m == 1) 

          return x; 
    }
} 
long long int primo(long long int n)
{
	int k, cont=0;
	for(k=1; k<=sqrt(n); k++)
	{
		if(n%k==0)
		{
			cont++;
			
		}
	}
	if(cont>1||n<2)
	{
		return 0;

	}
	else 
	{
		return 1;
	}
}
long long int mdc(long long int a, long long int b)
{
	if (b == 0)
    {
        return a;
    }
    else 
    {
        return mdc(b, a%b);
    }
}

int code_decode(long long int M, long long int n, long long int e)
{
   long long int c=1;
    while(e>0)
    {
        //com base no peq. teo. de fermat, fazemos a exponenciação modular
        if(e % 2 ==1)
        {
            c=(c * M)%n;
        }
        M=(M*M)%n;
        e=e/2;
    }
    return c;
  
}

int main()
{
    long long int escolha, p, q, fi, n, e, d, i;
  
  	char mensagem[1000], alfabeto[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
      
    num_invalido:
    printf("Olá, esse é um programa para codificar e descodificar mensagens utilizando criptografia RSA\nEscolha uma das opções\n1:Gerar Chave publica e privada\n2:criptografar\n3:descriptografar\n");
    scanf("%lld", &escolha);
    if(escolha==1)
    {   
        primo_invalido:
        printf("Digite 2 numeros primos:\n");
        scanf("%lld%lld", &p, &q);//2 primeiras chaves privadas
        if(!(primo(q)) || !(primo(p)))
        {  
            printf("Um dos numeros nao eh primo.\n\n");
            goto primo_invalido;
        }
        n=p*q;//Primeira chave publica
        fi=(p-1)*(q-1);//so pra conta (anderson)
        expoente_invalido:
        printf("Valor de φ: %lld\nDigite um valor para o expoente(entre 1 e %lld e mdc de φ expoente eh=1)\n", fi, fi);
        scanf("%lld", &e);
        if(mdc(e, fi)==1)
        {   
            printf("expoente valido\nchaves feitas com sucesso\n");
        }
        else
        {
            printf("Expoente invalido, digite outro\n\n");
            goto expoente_invalido;
        }
        // "e" eh a segunda chave publica
        d=inverso(e, fi); //ultima chave privada
        printf("Chaves pu viblicas (%lld %lld)\nChaves privadas (%lld %lld %lld)\n", n, e, p, q, d);
        escolhaerrada:
        printf("Escolha o proximo passo.\n1: Fechar o programa\n2: Codificar a mensagem\n3: decodificar mensagem\n");
        scanf("%lld", &escolha);
        if(escolha==1)
        {
            goto final;
        }
        else if(escolha==2)
        {
            goto p2;
        }
        else if(escolha==3)
        {
            goto p3;
        }
        else
        {
            goto escolhaerrada;
        }
        
    }
    else if(escolha==2)
    {   
        long long int vetor[100], aux;
        p2:
				printf("insira as chaves publicas(na ordem gerada)\n");
        scanf("%lld%lld", &n, &e);
        char lixo;
        scanf("%c", &lixo);
        printf("Digite uma mensagem para ser criptografada.\n");
        scanf("%[^\n]", mensagem);
      	for(i=0; i<strlen(mensagem);i++)
        {
          mensagem[i]=toupper(mensagem[i]);
          for(aux = 0; aux<27; aux++)
          {
            if(mensagem[i]==alfabeto[aux])
            {
                vetor[i]=aux;
                printf("%d ", code_decode(vetor[i], n, e));
            }
          }
          
        }

        printf("\n");
        escolhaerrada2:
        printf("Escolha o proximo passo.\n1: Fechar o programa\n2: decodificar mensagem.\n");
        scanf("%lld", &escolha);
         if(escolha==1)
        {
            goto final;
        }
        else if(escolha==2)
        {
            goto p3;
        }
        else
        {
            goto escolhaerrada2;
        }
        

        
    }
    else if(escolha==3)
    {
		long long int vetor[100], aux;
        p3:
		printf("insira as 3 chaves privadas (na ordem gerada)\n");
        scanf("%lld%lld%lld", &p, &q, &d);
        n=p*q;
        char lixo;
        scanf("%c", &lixo);
        printf("Digite uma mensagem para ser descriptografada.\n");
      	for(i=0; i<strlen(mensagem);i++)
        {
          scanf("%lld", &vetor[i]);
          vetor[i]=code_decode(vetor[i], n, d);
          for(aux = 0; aux<27; aux++)
          {
            if(vetor[i]==aux)
            {
                
                printf("%c", alfabeto[aux]);
            }
            
          }

        }
        printf("\n");
        goto final;
        

    }
    else
    {
        printf("Escolha invalida\n\n");
        goto num_invalido;
    }
    final:
    return 0;

}

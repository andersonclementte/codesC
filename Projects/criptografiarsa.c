#include <stdio.h>
#include <math.h>
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

int main()
{
    long long int escolha, p, q, fi, n, e, d, i;
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
        printf("Valor de fi: %lld\nDigite um valor para o expoente(entre 1 e %lld e mdc de fi expoente eh=1)\n", fi, fi);
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
        printf("Chaves publicas (%lld %lld)\nChaves privadas (%lld %lld %lld)\n", n, e, p, q, d);

    }
    else if(escolha==2)
    {

    }
    else if(escolha==3)
    {

    }
    else
    {
        printf("Escolha invalida\n\n");
        goto num_invalido;
    }
}

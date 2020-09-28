<h1 align="center">Desenrolamento de Laço (Loop Unrolling)</h1>

Técnica de ILP (Instruction Level Paralelism -> Paralelismo em Nível de Instrução) que busca alcançar maiores velocidades de execução de software.

## Sumário
  * [ILP]()
  * [Loop Unrolling]()
    * [Aplicação]()
    * [For]()
    * [While]()
    * [Lista Encadeada]()
  * [Por Que Funciona?]()
  * [Conclusão]()

## ILP

Pararerlismo em nível de instrução é a ideia de parelelizar instruções, ou seja, executar processos simultaneamente no processador. Existem diversas técnicas de ILP, porém aqui será dado o foco para o loop unrolling.

## Loop Unrolling

O loop unrolling é uma das várias técnicas de ILP que visa maior velocidade de execução de código e redução de consumo, através do desenrolamento de iterações. Matematicamente, podemos dizer que uma iteração M pode ser desenrolada N vezes, ou seja, também pode se dizer que é uma iteração M/N. Além disso pode ser aplicada:
  * Estaticamente: onde o programador implementa a técnica pessoalmente ou "na unha" como chamam.

  * Dinamicamente: de maneira automatizada, utilizando compiladores JIT (operam em tempo de execução). Nesse caso, o cenário ideal para aplicação, é quando temos um array que tem um tamanho desconhecido antes da compilação ou que pode ser definido/alterado durante execução.

Já que é nas iterações que esse método atua, é possível utilizar em for, while e lista encadeada. Será detalhado a seguir em pseudocódigo, como é possível converter as iterações convencionais para loop unrolling.

### For

Aqui teremos um exemplo de como funciona a conversão de um for convencional para um fatorado usando a técnica abordada:

```
//For convencional

for(i=0;i<1000;i++){
  a[i]=0;
}
```

```
//For com loop unrolling aplicado

for(i=0;i<1000;i+=10){
  a[i] = 0;
  a[i+1] = 0;
  a[i+2] = 0;
  a[i+3] = 0;
  a[i+4] = 0;
  a[i+5] = 0;
  a[i+6] = 0;
  a[i+7] = 0;
  a[i+8] = 0;
  a[i+9] = 0;
}
```

### While

Não é muito diferente do for, muda a sintaxe, porém, a lógica permanece a mesma:

```
//While convencional

i=0;

while(i<1000){
  a[i]=0;

  i++;
}
```

```
//While com loop unrolling aplicado

i=0;

for(i<1000){
  a[i] = 0;
  a[i+1] = 0;
  a[i+2] = 0;
  a[i+3] = 0;
  a[i+4] = 0;
  a[i+5] = 0;
  a[i+6] = 0;
  a[i+7] = 0;
  a[i+8] = 0;
  a[i+9] = 0;

  i+=10;
}
```

### Lista Encadeada

Em uma lista encadeada, percorremos os nós pelo ponteiros que apontam para o próximo nó, [artigo base]() cita uma solução onde é criado dois fluxos de iteração, ambos partindo das extremidades da lista. Porém, para isso acontecer, é preciso alterar a estrutura de dados do nó, para armazenar além da chave e do próximo, incluir o anterior também (é esse que faz com que seja possível vir do final para o início), de forma que passe a ser uma lista dupalmente encadeada.

```
//lista encadeada convencional

count = 0;

node f = first;

while(f != NULL){
  f = f->next;

  count++;
}
```

```
//lista encadeada com loop unrolling aplicado

count = 0;

node f = first;
node l = last;

while((f != l) || (f->next != l)){
  f = f->next;
  l = l->prev;

  count+=2;
}

if(f == l) {
  count--;
}
```

## Por que funciona?

## Conclusão


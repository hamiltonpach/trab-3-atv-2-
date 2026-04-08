#include <stdio.h>
#include <stdlib.h>

// Estrutura do documento
struct Documento {
    int id;
    int paginas;
    int prioridade;
    struct Documento *prox;
};

// Estrutura da fila
struct Fila {
    struct Documento *inicio;
};

// Inicializa fila
void inicializar(struct Fila *f) {
    f->inicio = NULL;
}

// Inserção com prioridade (ordenada)
void enfileirar(struct Fila *f, int id, int paginas, int prioridade) {
    struct Documento *novo = (struct Documento*) malloc(sizeof(struct Documento));
    if(novo == NULL) {
        printf("Erro de memoria!\n");
        exit(1);
    }

    novo->id = id;
    novo->paginas = paginas;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    // Inserção no início (fila vazia ou maior prioridade)
    if(f->inicio == NULL || prioridade < f->inicio->prioridade) {
        novo->prox = f->inicio;
        f->inicio = novo;
    } else {
        struct Documento *atual = f->inicio;

        // Percorre até encontrar posição correta
        while(atual->prox != NULL &&
              atual->prox->prioridade <= prioridade) {
            atual = atual->prox;
        }

        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

// Remove da fila
struct Documento* desenfileirar(struct Fila *f) {
    if(f->inicio == NULL) return NULL;

    struct Documento *temp = f->inicio;
    f->inicio = temp->prox;

    return temp;
}

int main() {
    struct Fila fila;
    inicializar(&fila);

    int n, id, paginas, prioridade;

    printf("Digite a quantidade de documentos: ");
    scanf("%d", &n);

    // Entrada de dados
    for(int i = 0; i < n; i++) {
        printf("\nDocumento %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &id);

        printf("Numero de paginas: ");
        scanf("%d", &paginas);

        printf("Prioridade (menor = maior prioridade): ");
        scanf("%d", &prioridade);

        enfileirar(&fila, id, paginas, prioridade);
    }

    // Simulação de impressão
    struct Documento *doc;

    printf("\n=== Ordem de Impressao ===\n");

    while((doc = desenfileirar(&fila)) != NULL) {
        printf("ID: %d | Paginas: %d | Prioridade: %d\n",
               doc->id, doc->paginas, doc->prioridade);

        free(doc);
    }

    return 0;
}
# trab-3-atv-2-
Esse código implementa uma fila dinâmica com prioridade para simular um sistema de impressão. Cada documento é representado por uma estrutura que contém id, número de páginas, prioridade e um ponteiro para o próximo elemento.
Diferente de uma fila comum, a inserção aqui é feita de forma ordenada pela prioridade. A função enfileirar verifica a posição correta para inserir o novo documento: se a fila estiver vazia ou o novo documento tiver maior prioridade (valor menor), ele é inserido no início; caso contrário, o programa percorre a fila até encontrar a posição adequada, mantendo a ordem.
A função desenfileirar remove sempre o primeiro elemento da fila, que será o documento com maior prioridade no momento.
No programa principal, o usuário informa a quantidade de documentos e insere os dados de cada um. Em seguida, o programa simula a impressão, removendo os documentos da fila na ordem correta de prioridade e exibindo suas informações.
Por fim, cada documento removido tem sua memória liberada, garantindo o uso adequado da alocação dinâmica.

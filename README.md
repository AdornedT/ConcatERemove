# ConcatERemove

Recomenda-se ver o código para a explicação de cada parte pertinente, tudo foi comentado para melhor entendimento.

Algo importante mencionar, quando se cria um vetor todas a posições tem um valor aleatório na memória. Isso acontece pois a posição alocada para ele não é limpada, para melhor comparação é importante fazer está limpeza.

A solução está bem otimizada, pois ela tenta chacar quantas posições realmente necessitam ser comparadas para toda iteração. Então strings pequenas são processadas mais rápidamente.

Alguns prints de debug foram mantidos para melhor visualização do que o programa está fazendo a cada passo.

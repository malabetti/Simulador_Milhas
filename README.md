# Simulador_Milhas
As empresas aéreas criaram, há muito tempo, as milhas aéreas. Elas são uma espécie de
pontuação para fazer com que os clientes continuem utilizando os serviços da cia aérea e de
seus parceiros. Servem como uma espécie de recompensa: quanto mais você utiliza os serviços
da cia aérea e seus parceiros, mais milhas (pontos) você acumula e pode utilizar de diversas
formas, trocando, por exemplo, por brindes, viagens, etc.
Uma das opções que você tem ao acumular milhas aéreas é conseguir comprar produtos
e receber parte dos valores investidos depois de um tempo diminuindo, assim, o valor final do
produto. Vamos entender como funcionaria essa estratégia de compra:

1. Você compra de lojas que estão dando N pontos por real gasto e acumula pontos;
• Ex: você compra um relógio de R$ 999 e ganha 10 pontos a cada real
totalizando 999 * 10 = 9.999 pontos acumulados;

2. Você consegue transferir esses pontos para uma cia aérea transformando-os em
milhas aéreas, muitas vezes com bônus de 20 à 130%;
• Se você transferir seus 9.999 pontos para uma cia aérea com bônus de:
• 30%: você terá 9.999 + 30% = 12.998,7 milhas aéreas;
• 80%: você terá 9.999 + 80% = 17.998,2 milhas aéreas;
• 130%: você terá 9.999 + 130% = 22.997,7 milhas aéreas;
• E assim por diante.

3. Após isso, você pode vender suas milhas aéreas recebendo de R$ 17 à R$ 29 a cada
mil milhas (milheiro):
• Obs. 1: A divisão por mil nos cálculos a seguir se faz necessária porque as
vendas são feitas em pacotes de mil milhas (milheiros);
• Obs. 2: Note que os valores recebidos pela venda variam de R$ 17 à R$ 29,
então coloquei alguns exemplos com valores variados entre R$ 17 e R$ 29;
• Assim, se você vender:
• 12.998,7 milhas por R$ 24 cada milheiro, você terá um retorno
financeiro de R$ (12.998,7 / 1000) * 24 = 311,97
• 17.998,2 milhas por R$ 21 cada milheiro, você terá um retorno
financeiro de R$ (17.998,2 / 1000) * 21 = 377,96
• 22.997,7 milhas por R$ 29 cada milheiro, você terá um retorno
financeiro de R$ (22.997,7 / 1000) * 29 = 666,93

4. Por fim, aquele relógio que você comprou por R$ 999 pode sair, no final, por:
• R$ 999 – 311,97 = 687,03, ou;
• R$ 999 – 377,96 = 621,04, ou ainda;
• R$ 999 – 666,93 = 332,07.
• Tudo depende dos valores, pontuações, bonificações e valores conseguidos
na venda das milhas.

-- Faça um sistema em C que consiste em um menu com os seguintes itens: --

-> 1. Fazer simulação
• O usuário entra com os dados necessários para simular por quanto um dado produto
sairia utilizando a estratégia apresentada anteriormente, e o sistema realiza os
cálculos da simulação
• Ao final da simulação, o sistema pergunta se o usuário desejar salvar aquela
simulação e armazena em arquivo a simulação caso o usuário opte por salvá-la para
posterior consulta

-> 2. Visualizar simulações salvas
• Este item lê todo o conteúdo do arquivo, i.e. as simulações salvas, e exibe para o
usuário, para fins de consulta

-> 3. Sair

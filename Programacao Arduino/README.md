Há dois arquivos com a programação do arduino emissor(Master) e do arduino receptor(Servo).

No arduino emissor:

- Há a leitura de distância através de dados de um sensor ultrassônico.
- Há a sinalização de 3 regiões correspondentes à distância, através dos led's azul(região 3), amarelo(região 2) e vemelho(região 3).
- É tirada a média dos valores de distância.
- É enviada a informação de distância convertida de float para string a um segundo arduino via comunicação serial.

No arduino receptor:

- Há o recebimento da informação de string com um limitante para não ser armazenado lixo.
- É utilizada a biblioteca LiquidCrystal para configurar um display LCD que mostrará os valores recebidos de distância.

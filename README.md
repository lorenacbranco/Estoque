# Projeto Sistema de Hamburgueria

## Desenvolvedores
<https://github.com/leticiauchoa>

<https://github.com/lorenacbranco>

<https://github.com/Duda-mecb>
_______________________________________________________________________________________________________________________________________________________________
## Sobre o projeto
O projeto foi estruturado em C++ seguindo os princípios da Programação Orientada a Objetos (POO), garantindo uma organização modular e de fácil compreensão. Cada elemento do sistema foi modelado como uma classe, permitindo uma representação mais intuitiva e próxima do mundo real. Além disso, a POO possibilitou a reutilização de código, reduzindo redundâncias e tornando o desenvolvimento mais eficiente. 
_______________________________________________________________________________________________________________________________________________________________
## Objetivo
Nosso objetivo foi desenvolver um sistema para controle de pedidos e faturamento de uma hamburgueria, proporcionando uma gestão eficiente dos produtos, ingredientes e estoque. O sistema deve permitir o registro e acompanhamento dos pedidos, calculando o faturamento com base nas vendas realizadas.

______________________________________________________________________________________________________________________________________________________________

## Instruções de uso


- Fazer download do arquivo "controlNovo.db", localizado na pasta "mav" e abrir pelo SQLiteStudio;
- Copiar o path do banco de dados no seu computador;
- Fazer download do repositório na biblioteca no computador (git);
- Abrir o QtCreator -> 'Abrir Projeto' -> selecionar o arquivo "mav.pro";
- Abrir o arquivo "conecta.h";
- Editar a linha 13 do código para colocar o seu path do SQLite;
- Run.

_______________________________________________________________________________________________________________________________________________________________
## Ferramentas e Bibliotecas utilizadas
- QT Creator:

-> *Bibliotecas de Interface Gráfica (QtWidgets)*

**QApplication** → Controla o loop de eventos da aplicação.

**QWidget** → Base para janelas e componentes da UI.

**QPushButton** → Botões interativos na interface.

**QTextEdit** → Área de texto para exibir o cardápio e pedidos.

**QVBoxLayout** → Layout vertical para organizar os widgets.

**QMessageBox** → Exibe mensagens de erro e confirmação.

**QInputDialog** → Exibe caixas de entrada para pedidos.


-> *Bibliotecas de Banco de Dados (QtSql)*

**QSqlQuery** → Para executar comandos SQL (SELECT, INSERT, etc.).

**QSqlError** → Para capturar erros do banco de dados.

**QVariant** → Para manipular dados genéricos vindos do banco.

- Sqlite

- Bibliotecas Essenciais do C++

**iostream** → Entrada e saída de dados (depuração).

**string** → Manipulação de textos (nomes de produtos, erros, etc.)

__________________________________________________________________________________________________________________________________________________
## Prints da tela

![Inicio do programa](https://lh3.googleusercontent.com/drive-storage/AJQWtBMUKtC_0uiQAO5WfmgVGd4RiIwosjvc810_HokLnNGmubrkzkYd5kD19vFj2feFxU8bFFRDlwIlyA0pUaxOlwOMsEqtRvOS_-gORbCwSiVnNgc=w1349-h641)
![Mostrar cardápio](https://lh3.googleusercontent.com/drive-storage/AJQWtBONLVqLqV9ZuH2iPLeRW3uVjc6t1mYp_Lg1U2T-QPLw2OdrYVL6L1GE_addwQWgmnCbykq-eWcPHH5pFTrTha_wIWlVbClAjmhnHtfbRFIUvhg=w1349-h641)
![Fazer pedido](https://lh3.googleusercontent.com/drive-storage/AJQWtBNUWvzwu-aqztIy5He0SBRgyzyMiBWVAtHObcEbXkdGrBFCu79UEJ3IBDD3EMItDMP95WdnI1GtImX8zZr-E7BjAD0Rig92n8518p_KGcj2Jik=w1349-h641)
![Histórico de pedidos](https://lh3.googleusercontent.com/drive-storage/AJQWtBMlwJ1t45VkcHbqoaMyZwsdPsrS6eZ9NS_qlcz02rBtYhgd8gjdNRQCH3uTmju79GfRJEugcdRWDTCe0iQ4NFFLY6cCOq1d5DgebqqQvNjwsk0=w1349-h641 )
![Limpar histórico de pedidos](https://lh3.googleusercontent.com/drive-storage/AJQWtBMtFFVCEHHIJKUbBrNa9MjIALDEeswOI0m-KfIZgh41YIAvsx9KRYp9dEiwI3ZLCeAsHK7en5ypeGdxByiSWt1YPU-bWOL00JMSQnmOylA9Ra4=w1349-h641)





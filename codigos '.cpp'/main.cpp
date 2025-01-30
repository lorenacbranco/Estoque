#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QLabel>
#include "conecta.h"

class MenuWindow : public QWidget {
    Q_OBJECT

public:
    MenuWindow(QWidget *parent = nullptr) : QWidget(parent) {
        conexao.abrir();

        QVBoxLayout *layout = new QVBoxLayout(this);

        botaoCardapio = new QPushButton("Mostrar Cardápio", this);
        botaoPedido = new QPushButton("Fazer Pedido", this);
        botaoPedidos = new QPushButton("Mostrar Pedidos", this);
        botaoLimparPedidos = new QPushButton("Limpar Histórico de Pedidos", this);
        botaoSair = new QPushButton("Sair", this);
        textEditCardapio = new QTextEdit(this);
        textEditPedidos = new QTextEdit(this);
        textEditPedidos->setReadOnly(true);
        labelDinheiroGanho = new QLabel("Dinheiro Ganho: R$ 0,00", this);

        layout->addWidget(botaoCardapio);
        layout->addWidget(botaoPedido);
        layout->addWidget(botaoPedidos);
        layout->addWidget(botaoLimparPedidos);
        layout->addWidget(botaoSair);
        layout->addWidget(textEditCardapio);
        layout->addWidget(textEditPedidos);
        layout->addWidget(labelDinheiroGanho);

        connect(botaoCardapio, &QPushButton::clicked, this, &MenuWindow::mostrarCardapio);
        connect(botaoPedido, &QPushButton::clicked, this, &MenuWindow::fazerPedido);
        connect(botaoPedidos, &QPushButton::clicked, this, &MenuWindow::mostrarPedidos);
        connect(botaoLimparPedidos, &QPushButton::clicked, this, &MenuWindow::limparPedidos);

        connect(botaoSair, &QPushButton::clicked, this, &MenuWindow::sair);
    }

    ~MenuWindow() {
        conexao.fechar();
    }

private slots:
    void mostrarCardapio() {
        textEditCardapio->clear();
        QSqlQuery query(conexao.bancoDeDados);
        if (query.exec("SELECT id, nome, preco, tipo FROM produtos WHERE disponibilidade = 1")) {
            textEditCardapio->append("====== CARDÁPIO ======");
            while (query.next()) {
                int id = query.value("id").toInt();
                QString nome = query.value("nome").toString();
                double preco = query.value("preco").toDouble();
                QString tipo = query.value("tipo").toString();
                textEditCardapio->append(QString("%1 - %2 (%3) - R$ %4").arg(id).arg(nome).arg(tipo).arg(preco));
            }
        } else {
            QMessageBox::critical(this, "Erro", "Erro ao carregar cardápio: " + query.lastError().text());
        }
    }

    void fazerPedido() {
        bool ok;
        int produtoId = QInputDialog::getInt(this, "Pedido", "Digite o ID do produto que deseja pedir:", 1, 1, 1000000, 1, &ok);
        if (!ok) return;

        int quantidade = QInputDialog::getInt(this, "Pedido", "Digite a quantidade:", 1, 1, 1000, 1, &ok);
        if (!ok) return;

        QSqlQuery query(conexao.bancoDeDados);
        query.prepare("SELECT nome, preco FROM produtos WHERE id = :id AND disponibilidade = 1");
        query.bindValue(":id", produtoId);

        if (!query.exec() || !query.next()) {
            QMessageBox::critical(this, "Erro", "Produto não encontrado ou indisponível!");
            return;
        }

        QString nomeProduto = query.value("nome").toString();
        double preco = query.value("preco").toDouble();
        double total = preco * quantidade;

        QSqlQuery insertPedido(conexao.bancoDeDados);
        insertPedido.prepare("INSERT INTO pedidos (total) VALUES (:total)");
        insertPedido.bindValue(":total", total);
        if (!insertPedido.exec()) {
            QMessageBox::critical(this, "Erro", "Erro ao registrar pedido: " + insertPedido.lastError().text());
            return;
        }

        int pedidoId = insertPedido.lastInsertId().toInt();

        QSqlQuery insertItem(conexao.bancoDeDados);
        insertItem.prepare("INSERT INTO itens_pedido (pedido_id, produto_id, quantidade, subtotal) VALUES (:pedido_id, :produto_id, :quantidade, :subtotal)");
        insertItem.bindValue(":pedido_id", pedidoId);
        insertItem.bindValue(":produto_id", produtoId);
        insertItem.bindValue(":quantidade", quantidade);
        insertItem.bindValue(":subtotal", total);
        insertItem.exec();

        mostrarPedidos();
    }

    void mostrarPedidos() {
        textEditPedidos->clear();
        QSqlQuery query(conexao.bancoDeDados);
        if (query.exec("SELECT produtos.nome, itens_pedido.subtotal FROM itens_pedido JOIN produtos ON itens_pedido.produto_id = produtos.id")) {
            double totalGanho = 0;
            while (query.next()) {
                QString nome = query.value("nome").toString();
                double subtotal = query.value("subtotal").toDouble();
                totalGanho += subtotal;
                textEditPedidos->append(QString("%1 - R$ %2").arg(nome).arg(subtotal));
            }
            labelDinheiroGanho->setText(QString("Dinheiro Ganho: R$ %1").arg(totalGanho));
        } else {
            QMessageBox::critical(this, "Erro", "Erro ao carregar pedidos: " + query.lastError().text());
        }
    }

    void limparPedidos() {
        QSqlQuery query(conexao.bancoDeDados);
        query.exec("DELETE FROM itens_pedido");
        query.exec("DELETE FROM pedidos");
        textEditPedidos->clear();
        labelDinheiroGanho->setText("Dinheiro Ganho: R$ 0,00");
        QMessageBox::information(this, "Limpar Pedidos", "Histórico de pedidos apagado com sucesso!");
    }

    void sair() {
        QApplication::quit();
    }

private:
    QPushButton *botaoCardapio;
    QPushButton *botaoPedido;
    QPushButton *botaoPedidos;
    QPushButton *botaoLimparPedidos;
    QPushButton *botaoSair;
    QTextEdit *textEditCardapio;
    QTextEdit *textEditPedidos;
    QLabel *labelDinheiroGanho;

    Conexao conexao;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MenuWindow window;
    window.show();
    return app.exec();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTreeWidget>

#include "dbstorage.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DBStorage::instance()->openDB();
    DBStorage::instance()->init();

    DBStorage::instance()->setSettings("key1", "vaaa");
    DBStorage::instance()->setSettings("key1", "vaaa123");
    qDebug() << DBStorage::instance()->getSettings("key1");
    qDebug() << DBStorage::instance()->getSettings("key2");

//    DBStorage::instance()->addPayment("818af8b3a50a5b6758360d11a44533f596af76feb9b4e57557220a8536c38165",
//                                      "818af8b3a50a5b6758360d11a44533f596af76feb9b4e57557220a8536c38165",
//                                      "1CKZ3fJrojYauQHUZiuSKeuvw1AwBVUwHX",
//                                      "19BWPGPJM9KAG6r8vRsLH9e6w495dx3C5W,1",
//                                      "0.0006650",
//                                      "66502",
//                                      533227,
//                                      true,
//                                      1532329669,
//                                      "7");
    DBStorage::instance()->addMessage("1234", "3454", "abcd", 1, 4000, true, true, true, "asdfdf", 1);
    DBStorage::instance()->addMessage("1234", "3454", "abcd", 1, 1500, true, true, true, "asdfdf", 1);
    qDebug() << "answer " << DBStorage::instance()->getMessagesForUserAndDestNum("1234", "3454", 5000, 20).size();
    qDebug() << "answer " << DBStorage::instance()->getMessagesCountForUserAndDest("1234", "3454", 3000);
    qDebug() << DBStorage::instance()->getUserId("user1");
    qDebug() << DBStorage::instance()->getUserId("user2");
    qDebug() << DBStorage::instance()->getUserId("user3");
    qDebug() << DBStorage::instance()->getUserId("user1");
    qDebug() << DBStorage::instance()->getUserId("user5");
    qDebug() << DBStorage::instance()->getUserId("user6");

    DBStorage::instance()->addMessage("user6", "user7", "Hello!", 8458864, 1, true, true, true, "jkfjkjttrjkgfjkgfjk", 445);
    DBStorage::instance()->addMessage("user7", "user1", "Hello1!", 84583864, 1, true, true, true, "dfjkjkgfjkgfjkgfjkjk", 445);
    DBStorage::instance()->addMessage("user7", "user1", "Hello1!", 84583864, 2, true, true, true, "dfjkjkgfjkgfjkgfjkjk", 445);
    DBStorage::instance()->addMessage("user7", "user1", "Hello1!", 84583864, 3, true, true, true, "dfjkjkgfjkgfjkgfjkjk", 445);
    DBStorage::instance()->addMessage("user7", "user1", "Hello1!", 84583864, 4, true, true, true, "dfjkjkgfjkgfjkgfjkjk", 445);
    DBStorage::instance()->addMessage("user7", "user1", "Hello1!", 84583864, 5, true, true, true, "dfjkjkgfjkgfjkgfjkjk", 445);
    DBStorage::instance()->addMessage("user7", "user1", "Hello1!", 84583864, 6, true, true, false, "dfjkjkgfjkgfjkgfjkjk", 445);
    DBStorage::instance()->addMessage("user7", "user1", "Hello1!", 84583864, 7, true, true, false, "dfjkjkgfjkgfjkgfjkjk", 445);

    qDebug() << "size" << DBStorage::instance()->getMessagesForUserAndDestNum("user7", "user1", 10, 1000).size();

    std::list<Message> msgs = DBStorage::instance()->getMessagesForUser("user7", 1, 3);
    qDebug() << "count " << msgs.size();

    qDebug() << DBStorage::instance()->getMessageMaxCounter("user7");
    qDebug() << DBStorage::instance()->getMessageMaxConfirmedCounter("user7");
    qDebug() << DBStorage::instance()->getMessageMaxConfirmedCounter("userururut");

    qDebug() << DBStorage::instance()->getUsersList();

    DBStorage::instance()->setUserPublicKey("user7", "dfkgflgfkltrioidfkldfklgfgf");
    qDebug() << DBStorage::instance()->getUserPublicKey("user7");
    qDebug() << DBStorage::instance()->getUserPublicKey("user1");
    qDebug() << DBStorage::instance()->getUserPublicKey("userrrrr");
    qint64 id = DBStorage::instance()->findFirstNotConfirmedMessage("user7");
    qDebug() << id;
    DBStorage::instance()->updateMessage(id, 4444, true);
    qDebug() << DBStorage::instance()->findFirstNotConfirmedMessage("user7");


    qDebug() << DBStorage::instance()->getLastReadCounterForUserContact("userrgjkg", "fjkgfjk");
    qDebug() << DBStorage::instance()->getLastReadCounterForUserContact("user7", "user1");
    DBStorage::instance()->setLastReadCounterForUserContact("user7", "user1", 244);
    qDebug() << DBStorage::instance()->getLastReadCounterForUserContact("user7", "user1");


    qDebug() << DBStorage::instance()->getLastReadCountersForUser("user7").size();
//    QList<QStringList> r = DBStorage::instance()->getPayments();
//    foreach(const QStringList &l, r) {
//        QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
//        for (int c = 0; c < 10; c++)
//            item->setText(c, l.value(c));
//    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

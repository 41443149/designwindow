#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QIcon>
#include <QPixmap>
#include <QStyle>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void newFile();
    void openImage();
    void closeFile();
    void saveFile();
    void saveAsFile();
    void exitApp();

    void undoSlot();
    void cutSlot();
    void copySlot();
    void pasteSlot();
    void selectAllSlot();
    void rotateImageSlot();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    QIcon loadActionIcon(const QString &resourcePath, QStyle::StandardPixmap fallback);

    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QPixmap currentPixmap;

    QAction *newAction;
    QAction *openImageAction;
    QAction *closeAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;

    QAction *undoAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *selectAllAction;

    QAction *rotateAction;
};

#endif // MAINWINDOW_H
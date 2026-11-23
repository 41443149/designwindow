#include "mainwindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QStatusBar>
#include <QFile>
#include <QTextStream>
#include <QTransform>
#include <QImageReader>
#include <QTextCursor>
#include <QBuffer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("MainWindow");
    resize(800, 600);

    // 1. 設定 CentralWidget、Layout 與 textEdit
    centralWidget = new QWidget(this);
    centralWidget->setObjectName("centralWidget");

    horizontalLayout = new QHBoxLayout(centralWidget);
    horizontalLayout->setObjectName("horizontalLayout");

    textEdit = new QTextEdit(centralWidget);
    textEdit->setObjectName("textEdit");
    textEdit->setPlainText("This is a test\n這是一個測試");
    horizontalLayout->addWidget(textEdit);

    setCentralWidget(centralWidget);

    // 2. 初始化 Actions、Menus 與 ToolBars
    createActions();
    createMenus();
    createToolBars();

    statusBar()->showMessage("就緒");
}

MainWindow::~MainWindow()
{
}

QIcon MainWindow::loadActionIcon(const QString &resourcePath, QStyle::StandardPixmap fallback)
{
    if (QFile::exists(resourcePath)) {
        QIcon icon;
        icon.addFile(resourcePath, QSize(), QIcon::Normal, QIcon::Off);
        return icon;
    }
    return style()->standardIcon(fallback);
}

void MainWindow::createActions()
{
    // --- File / 檔案 (&F) ---
    newAction = new QAction(loadActionIcon(":/images/new.png", QStyle::SP_FileIcon), tr("新增(&N)"), this);
    newAction->setShortcut(QKeySequence::New); // Ctrl+N
    newAction->setStatusTip(tr("新增(N)"));
    connect(newAction, &QAction::triggered, this, &MainWindow::newFile);

    // 'Open Image' 同時出現在 File Menu 與 Toolbar，兩者執行相同功能
    openImageAction = new QAction(loadActionIcon(":/images/open.png", QStyle::SP_DialogOpenButton), tr("Open Image(&O)"), this);
    openImageAction->setShortcut(QKeySequence::Open); // Ctrl+O
    openImageAction->setStatusTip(tr("開啟圖片(O)"));
    connect(openImageAction, &QAction::triggered, this, &MainWindow::openImage);

    closeAction = new QAction(loadActionIcon(":/images/editor.png", QStyle::SP_BrowserStop), tr("關閉(&C)"), this);
    closeAction->setShortcut(QKeySequence::Close); // Ctrl+W
    closeAction->setStatusTip(tr("關閉(C)"));
    connect(closeAction, &QAction::triggered, this, &MainWindow::closeFile);

    // Save 加入 Ctrl+S 快捷鍵
    saveAction = new QAction(loadActionIcon(":/images/save.png", QStyle::SP_DialogSaveButton), tr("儲存(&S)"), this);
    saveAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S)); // Ctrl+S
    saveAction->setStatusTip(tr("儲存(S) (Ctrl+S)"));
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);

    saveAsAction = new QAction(loadActionIcon(":/images/asave.png", QStyle::SP_DriveFDIcon), tr("另存(&A)"), this);
    saveAsAction->setShortcut(QKeySequence::SaveAs); // Ctrl+Shift+S
    saveAsAction->setStatusTip(tr("另存(A)"));
    connect(saveAsAction, &QAction::triggered, this, &MainWindow::saveAsFile);

    exitAction = new QAction(style()->standardIcon(QStyle::SP_DialogCloseButton), tr("退出(&X)"), this);
    exitAction->setShortcut(QKeySequence::Quit); // Ctrl+Q
    exitAction->setStatusTip(tr("退出(X)"));
    connect(exitAction, &QAction::triggered, this, &MainWindow::exitApp);

    // --- Edit / 編輯 (&E) ---
    undoAction = new QAction(loadActionIcon(":/images/undo.png", QStyle::SP_ArrowBack), tr("還原(&U)"), this);
    undoAction->setShortcut(QKeySequence::Undo); // Ctrl+Z
    undoAction->setStatusTip(tr("還原(U)"));
    connect(undoAction, &QAction::triggered, this, &MainWindow::undoSlot);

    cutAction = new QAction(loadActionIcon(":/images/cut.png", QStyle::SP_DirLinkIcon), tr("剪下(&T)"), this);
    cutAction->setShortcut(QKeySequence::Cut); // Ctrl+X
    cutAction->setStatusTip(tr("剪下(T)"));
    connect(cutAction, &QAction::triggered, this, &MainWindow::cutSlot);

    copyAction = new QAction(loadActionIcon(":/images/copy.png", QStyle::SP_FileDialogContentsView), tr("複製(&C)"), this);
    copyAction->setShortcut(QKeySequence::Copy); // Ctrl+C
    copyAction->setStatusTip(tr("複製(C)"));
    connect(copyAction, &QAction::triggered, this, &MainWindow::copySlot);

    pasteAction = new QAction(loadActionIcon(":/images/paste.png", QStyle::SP_DirHomeIcon), tr("貼上(&P)"), this);
    pasteAction->setShortcut(QKeySequence::Paste); // Ctrl+V
    pasteAction->setStatusTip(tr("貼上(P)"));
    connect(pasteAction, &QAction::triggered, this, &MainWindow::pasteSlot);

    selectAllAction = new QAction(loadActionIcon(":/images/find.png", QStyle::SP_DesktopIcon), tr("全選(&A)"), this);
    selectAllAction->setShortcut(QKeySequence::SelectAll); // Ctrl+A
    selectAllAction->setStatusTip(tr("全選(A)"));
    connect(selectAllAction, &QAction::triggered, this, &MainWindow::selectAllSlot);

    // --- Image / 影像 (&I) ---
    rotateAction = new QAction(style()->standardIcon(QStyle::SP_BrowserReload), tr("旋轉 90°(&R)"), this);
    rotateAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R)); // Ctrl+R
    rotateAction->setStatusTip(tr("順時針旋轉圖片 90 度"));
    connect(rotateAction, &QAction::triggered, this, &MainWindow::rotateImageSlot);
}

void MainWindow::createMenus()
{
    // File / 檔案選單
    QMenu *fileMenu = menuBar()->addMenu(tr("&File / 檔案(&F)"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openImageAction); // 'Open Image' 位於 File Menu
    fileMenu->addAction(closeAction);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    // Edit / 編輯選單
    QMenu *editMenu = menuBar()->addMenu(tr("&Edit / 編輯(&E)"));
    editMenu->addAction(undoAction);
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(selectAllAction);

    // Image / 影像選單
    QMenu *imageMenu = menuBar()->addMenu(tr("&Image / 影像(&I)"));
    imageMenu->addAction(rotateAction);
}

void MainWindow::createToolBars()
{
    // 第一組工具列：新增、Open Image、儲存、另存
    QToolBar *fileToolBar = addToolBar(tr("檔案工具列"));
    fileToolBar->setObjectName("filetoolBar");
    fileToolBar->setMovable(false);
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openImageAction); // 與 File Menu 共用同一個 Action
    fileToolBar->addAction(saveAction);
    fileToolBar->addAction(saveAsAction);

    // 第二組工具列：還原、剪下、複製、貼上
    QToolBar *editToolBar = addToolBar(tr("編輯工具列"));
    editToolBar->setObjectName("edittoolBar");
    editToolBar->setMovable(false);
    editToolBar->addAction(undoAction);
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
}

void MainWindow::newFile()
{
    currentPixmap = QPixmap();
    textEdit->clear();
    statusBar()->showMessage(tr("已建立新檔案"));
}

void MainWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open Image"),
        "",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.gif)")
        );

    if (!fileName.isEmpty()) {
        QPixmap pixmap;
        if (pixmap.load(fileName)) {
            currentPixmap = pixmap;
            QPixmap scaled = currentPixmap.scaled(480, 320, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            QByteArray byteArray;
            QBuffer buffer(&byteArray);
            buffer.open(QIODevice::WriteOnly);
            scaled.save(&buffer, "PNG");

            textEdit->clear();
            textEdit->insertHtml(QString("<p>已載入圖片：%1</p><img src=\"data:image/png;base64,%2\" />")
                                     .arg(fileName.toHtmlEscaped(), QString::fromLatin1(byteArray.toBase64())));
            statusBar()->showMessage(tr("已開啟圖片: %1").arg(fileName));
        } else {
            QMessageBox::warning(this, tr("錯誤"), tr("無法載入該圖片檔案！"));
        }
    }
}

void MainWindow::closeFile()
{
    currentPixmap = QPixmap();
    textEdit->clear();
    statusBar()->showMessage(tr("已關閉內容"));
}

void MainWindow::saveFile()
{
    saveAsFile();
}

void MainWindow::saveAsFile()
{
    if (!currentPixmap.isNull()) {
        QString fileName = QFileDialog::getSaveFileName(
            this,
            tr("儲存圖片"),
            "output.png",
            tr("PNG Image (*.png);;JPEG Image (*.jpg);;Bitmap (*.bmp);;Text File (*.txt)")
            );

        if (!fileName.isEmpty()) {
            if (fileName.endsWith(".txt", Qt::CaseInsensitive)) {
                QFile file(fileName);
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&file);
                    out << textEdit->toPlainText();
                    statusBar()->showMessage(tr("已儲存文字至: %1").arg(fileName));
                }
            } else if (currentPixmap.save(fileName)) {
                statusBar()->showMessage(tr("已儲存圖片至: %1").arg(fileName));
            } else {
                QMessageBox::warning(this, tr("錯誤"), tr("儲存失敗！"));
            }
        }
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("儲存檔案"),
        "output.txt",
        tr("Text File (*.txt);;All Files (*)")
        );

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << textEdit->toPlainText();
            statusBar()->showMessage(tr("已儲存至: %1").arg(fileName));
        } else {
            QMessageBox::warning(this, tr("錯誤"), tr("儲存檔案失敗！"));
        }
    }
}

void MainWindow::exitApp()
{
    close();
}

void MainWindow::undoSlot()
{
    textEdit->undo();
    statusBar()->showMessage(tr("還原"), 2000);
}

void MainWindow::cutSlot()
{
    textEdit->cut();
    statusBar()->showMessage(tr("剪下"), 2000);
}

void MainWindow::copySlot()
{
    textEdit->copy();
    statusBar()->showMessage(tr("複製"), 2000);
}

void MainWindow::pasteSlot()
{
    textEdit->paste();
    statusBar()->showMessage(tr("貼上"), 2000);
}

void MainWindow::selectAllSlot()
{
    textEdit->selectAll();
    statusBar()->showMessage(tr("全選"), 2000);
}

void MainWindow::rotateImageSlot()
{
    if (currentPixmap.isNull()) {
        statusBar()->showMessage(tr("請先透過 Open Image 開啟圖片再旋轉"), 3000);
        return;
    }

    QTransform transform;
    transform.rotate(90);
    currentPixmap = currentPixmap.transformed(transform, Qt::SmoothTransformation);

    QPixmap scaled = currentPixmap.scaled(480, 320, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    scaled.save(&buffer, "PNG");

    textEdit->clear();
    textEdit->insertHtml(QString("<p>已順時針旋轉 90°</p><img src=\"data:image/png;base64,%1\" />")
                             .arg(QString::fromLatin1(byteArray.toBase64())));
    statusBar()->showMessage(tr("已順時針旋轉 90 度"), 3000);
}

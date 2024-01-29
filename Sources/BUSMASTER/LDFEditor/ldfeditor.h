#ifndef BUSMASTER_LDFEDITOR_LDFEDITOR_H_
#define BUSMASTER_LDFEDITOR_LDFEDITOR_H_

#include <LDFElementView.h>
#include <LDFNetworkView.h>
#include <LDFPropertyView.h>
#include <QSplitter.h>
#include <qevent.h>
#include <ui_LDFEditor.h>

#include <QMenubar>
#include <QtWidgets/QMainWindow>

class LDFEditor : public QMainWindow {
  Q_OBJECT
 private:
  Ui::LDFEditor ui;
  QString m_strCurrentLDFFilePath;

  QAction* recentFileActs[5];
  LDFCommonTableWidget* m_pWarningTable;

 private:
  int ConnectMenuActions(void);
  int UpdatedRecentFileList();
  int OpenLDFFile(QString strFile);
  int OnFileLoad(QString strFile);
  int CloseCurrentLDFFile();
  int CheckForSaving();
  void setTitle();
  void SetupWarningPane();
  void AddWarningsOfNewFile(double dVers);
  int ValidateForSaving();
  int nValidateForCluster(std::list<ParsingResults>& ouErrors,
                          std::list<ParsingResults>& ouWarnings);

 public:
  LDFEditor(std::string omstrLdfPath, QWidget* parent = 0);
  ~LDFEditor();

 public:
  void closeEvent(QCloseEvent* event);

 public slots:
  int onActionFileOpen(void);
  int onActionFileSave(void);
  int onActionFileSaveAs(void);
  int onActionAbout(void);
  int onActionHelp(void);
  int onActionLIN1_3(void);
  int onActionLIN2_0(void);
  int onActionLIN2_1(void);
  int onActionHex(void);
  int onActionOpenRecentFile();
  int onActionPreviewFile();
  void OnitemElementViewSelected();
  void OnitemNetworkViewSelected();
  void OnDocumentModified();
  int onFileExit();
};

#endif  // BUSMASTER_LDFEDITOR_LDFEDITOR_H_
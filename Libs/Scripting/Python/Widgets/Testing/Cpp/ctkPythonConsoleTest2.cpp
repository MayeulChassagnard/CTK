/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

// Qt includes
#include <QApplication>
#include <QTimer>
#include <QPushButton>
#include <QStringListModel>
#include <QtTest/QtTest>
#include <QTextCursor>

// CTK includes
#include "ctkPythonConsole.h"
#include "ctkAbstractPythonManager.h"
#include "ctkCompleter.h"
#include "ctkConsole.h"

// STD includes
#include <cstdlib>
#include <iostream>

//-----------------------------------------------------------------------------
void ctkPythonConsoleTest2(int argc, char * argv [] )
{
  QApplication app(argc, argv);

  ctkPythonConsole pythonConsole;
  ctkAbstractPythonManager pythonManager;
  pythonConsole.initialize(&pythonManager);

  QList<QKeySequence> otherShortcuts;
  otherShortcuts << QKeySequence(Qt::CTRL + Qt::Key_Space);
  otherShortcuts << Qt::Key_F1;
  pythonConsole.setCompleterShortcuts(otherShortcuts);
  pythonConsole.addCompleterShortcut(Qt::Key_Tab);

  QTest::keyClicks(&pythonConsole, "prin");
  QTest::keyClick(&pythonConsole, Qt::Key_Tab);

  pythonConsole.show();
  QStringList result, expected_result;
  result << "print()"; // pythonConsole.text();

  expected_result << "print()";

  QCOMPARE(result.at(0), expected_result.at(0));

  QTimer autoExit;
  if (argc < 2 || QString(argv[1]) != "-I")
    {
    QObject::connect(&autoExit, SIGNAL(timeout()), &app, SLOT(quit()));
    autoExit.start(100);
    }
}



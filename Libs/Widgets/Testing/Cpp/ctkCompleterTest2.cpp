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
#include <QLineEdit>
#include <QStringListModel>
#include <QTimer>
#include <QtTest/QtTest>

// CTK includes
#include "ctkCompleter.h"

//-----------------------------------------------------------------------------
void ctkCompleterTest2(int argc, char * argv[] )
{
  QApplication app(argc, argv);

  QLineEdit lineEdit;
  QTest::keyClicks(&lineEdit, "prin");
  QTest::keyClick(&lineEdit, Qt::Key_Tab);
  lineEdit.show();

  QStringList result;
  result << "print()";

  QCOMPARE(lineEdit.text(), result.at(0));


  if (argc < 2 || QString(argv[1]) != "-I" )
    {
    QTimer::singleShot(200, &app, SLOT(quit()));
    }
}

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

#ifndef __ctkThumbnailWidget_h
#define __ctkThumbnailWidget_h

// Qt includes 
#include <QWidget>
#include <QModelIndex>

#include "ctkWidgetsExport.h"

class ctkThumbnailWidgetPrivate;

class CTK_WIDGETS_EXPORT ctkThumbnailWidget : public QWidget
{
  Q_OBJECT
  /// If the text is empty, the space allocated for the text is hidden
  /// Empty by default
  Q_PROPERTY(QString text READ text WRITE setText)
  /// Position of the text relative to the pixmap.
  /// Qt::AlignTop | Qt::AlignHCenter by default.
  /// For now, if the alignment is HCenter|VCenter, no text is shown.
  Q_PROPERTY(Qt::Alignment textPosition READ textPosition WRITE setTextPosition)
  Q_PROPERTY(QPixmap pixmap READ pixmap WRITE setPixmap)
  /// Qt::FastTransformation by default
  Q_PROPERTY(Qt::TransformationMode transformationMode READ transformationMode WRITE setTransformationMode)
  /// Not selected by default
  Q_PROPERTY(bool selected READ isSelected WRITE setSelected)
  /// Palette highlight color by default
  Q_PROPERTY(QColor selectedColor READ selectedColor WRITE setSelectedColor)
public:
  typedef QWidget Superclass;
  explicit ctkThumbnailWidget(QWidget* parent=0);
  virtual ~ctkThumbnailWidget();

  void setText(const QString& text);
  QString text()const;

  void setTextPosition(const Qt::Alignment& alignment);
  Qt::Alignment textPosition()const;

  void setPixmap(const QPixmap& pixmap);
  const QPixmap* pixmap()const;

  Qt::TransformationMode transformationMode()const;
  void setTransformationMode(Qt::TransformationMode mode);

  void setSelected(bool selected);
  bool isSelected()const;

  void setSelectedColor(const QColor& color);
  QColor selectedColor()const;

  virtual QSize minimumSizeHint()const;
  virtual QSize sizeHint()const;
  virtual int heightForWidth(int width)const;

protected:
  QScopedPointer<ctkThumbnailWidgetPrivate> d_ptr;

  virtual void paintEvent(QPaintEvent* event);
  virtual void mousePressEvent(QMouseEvent* event);
  virtual void mouseDoubleClickEvent(QMouseEvent* event);

  virtual void resizeEvent(QResizeEvent* event);

private:
  Q_DECLARE_PRIVATE(ctkThumbnailWidget);
  Q_DISABLE_COPY(ctkThumbnailWidget);

signals:
  void selected(const ctkThumbnailWidget& widget);
  void doubleClicked(const ctkThumbnailWidget& widget);
};

#endif

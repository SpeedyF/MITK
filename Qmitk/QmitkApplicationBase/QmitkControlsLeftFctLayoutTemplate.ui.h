/*=========================================================================

  Program:   Medical Imaging & Interaction Toolkit
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/ for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, preserving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/


void QmitkControlsLeftFctLayoutTemplate::init()
{
    //MainSplitter->setResizeMode(MainParent,QSplitter::FollowSizeHint);
    //MainSplitter->setResizeMode(ControlParent,QSplitter::FollowSizeHint);
}


void QmitkControlsLeftFctLayoutTemplate::setControlSizeHint(QSize * size)
{
    QValueList<int> sizes;
    int w=10; //MainSplitter->width(); hierin stehen absurde werte. Deshalb funktioniert auch der auto-resize wahrscheinlich nicht!!
    sizes.append(size->width());
    sizes.append(width()-size->width()-w);
    MainSplitter->setSizes(sizes);
}

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

#include "mitkPointOperation.h"

//##ModelId=3F0189F003A2
mitk::PointOperation::PointOperation(OperationType operationType, Point3D point, int index, bool selected, PointSpecificationType type)
: mitk::Operation(operationType), m_Point(point), m_Index(index), m_Selected(selected), m_Type(type)
{}

//##ModelId=3F0189F003B2
mitk::PointOperation::~PointOperation()
{
}

//##ModelId=3F0189F003B4
mitk::Point3D mitk::PointOperation::GetPoint()
{
	return m_Point;
}

//##ModelId=3F0189F003B5
int mitk::PointOperation::GetIndex()
{
	return m_Index;
}

bool mitk::PointOperation::GetSelected()
{
  return m_Selected;
}

mitk::PointSpecificationType mitk::PointOperation::GetPointType()
{
  return m_Type;
}

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

#ifndef MITKLookupTablePROPERTY_H_HEADER_INCLUDED_C10EEAA8
#define MITKLookupTablePROPERTY_H_HEADER_INCLUDED_C10EEAA8

#include "mitkCommon.h"
#include "mitkBaseProperty.h"
#include "mitkLookupTable.h"

namespace mitk {

//##ModelId=3ED953070392
//##Documentation
//## @brief Property for LookupTable data
//## @ingroup DataTree
class LookupTableProperty : public BaseProperty
{

protected:
    //##ModelId=3ED953090113
    mitk::LookupTable m_LookupTable;

public:
    mitkClassMacro(LookupTableProperty, BaseProperty);

    //##ModelId=3ED953090121
    LookupTableProperty(const mitk::LookupTable &lut);

    //##ModelId=3EF198D9012D
//    LookupTableProperty(const mitk::LookupTable& aLookupTable);

    //##ModelId=3ED953090122
    virtual ~LookupTableProperty();

    //##ModelId=3ED953090124
    virtual bool operator==(const BaseProperty& property) const;

    //##ModelId=3ED953090133
    mitk::LookupTable & GetLookupTable() ;

    //##ModelId=3ED953090135
    void SetLookupTable(const mitk::LookupTable & aLookupTable);
};

} // namespace mitk



#endif /* MITKLookupTablePROPERTY_H_HEADER_INCLUDED_C10EEAA8 */

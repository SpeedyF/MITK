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

#ifndef BASECONTROLLER_H_HEADER_INCLUDED_C1E745A3
#define BASECONTROLLER_H_HEADER_INCLUDED_C1E745A3

#include "mitkCommon.h"
#include "mitkStepper.h"
#include "mitkStateMachine.h"
#include <itkObjectFactory.h>

namespace mitk {

class BaseRenderer;

//##ModelId=3DF8F7EA01DA
//##Documentation
//## @brief Baseclass for renderer slice-/camera-control
//## @ingroup NavigationControl
//## Tells the render (subclass of BaseRenderer) which slice (subclass
//## SliceNavigationController) or from which direction (subclass
//## CameraController) it has to render. Contains two Stepper for stepping
//## through the slices or through different camera views (e.g., for the
//## creation of a movie around the data), respectively, and through time, if
//## there is 3D+t data.
//## @note not yet implemented
class BaseController : public StateMachine
{
public:
  /** Standard class typedefs. */
  //##ModelId=3E6D5DD301B0
  mitkClassMacro(BaseController, StateMachine);

  /** Method for creation through the object factory. */
  //itkNewMacro(Self);
  BaseController(const char * type = NULL);

  //##ModelId=3DF8F5CA03D8
  //##Documentation
  //## @brief Get the Stepper through the slices
  mitk::Stepper* GetSlice();

  //##ModelId=3DF8F61101E3
  //##Documentation
  //## @brief Get the Stepper through the time
  mitk::Stepper* GetTime();

protected:
  //BaseController();

  //##ModelId=3E3AE32B0070
  virtual ~BaseController();

  //##ModelId=3DF8C0140176
  //## @brief Stepper through the time
  Stepper::Pointer m_Time;
  //##ModelId=3E189CAA0265
  //## @brief Stepper through the slices
  Stepper::Pointer m_Slice;
  
  unsigned long m_LastUpdateTime;
};

} // namespace mitk

#endif /* BASECONTROLLER_H_HEADER_INCLUDED_C1E745A3 */

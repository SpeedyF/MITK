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

#ifndef TRANSITION_H_HEADER_INCLUDED_C19AE06B
#define TRANSITION_H_HEADER_INCLUDED_C19AE06B

#include "mitkCommon.h"
#include <string>
#include <vector>


namespace mitk {
class State;
class Action;

//##ModelId=3E5A399E033E
//##Documentation
//## @brief Connection of two states
//## @ingroup Interaction
//## A transition connects two states. 
//## Also a Action is stored, that has to be executed after the statechange
class Transition
{
  public:
  //##ModelId=3E5A3A77006F
	Transition(std::string name, int nextStateId, int eventId);

  void AddAction( Action* action );

  //##ModelId=3E5A3BAE03B5
  std::string GetName() const;

  //##ModelId=3E5A3BCE00E0
	mitk::State* GetNextState() const;

  //##ModelId=3E68CB99014B
	int GetNextStateId() const;

  //##
  int GetEventId() const;

  //##
  int GetActionCount() const;

  //##
  std::vector<Action*>::iterator GetActionBeginIterator() const;

  //##
  const std::vector<Action*>::iterator GetActionEndIterator() const;

  //##ModelId=3E5A3C1D0289
  bool IsEvent(int eventId) const;

  //##ModelId=3E6370080067
  void SetNextState(State* state);

  private:
  //##ModelId=3E5A39C102B2
	std::string m_Name;

  //##ModelId=3E5A3A060366
  State* m_NextState;

  //##ModelId=3E5A3A280007
  int m_NextStateId;

  //##ModelId=3E5A3A3C0331
  int m_EventId;

  //##ModelId=3E5A3A55017F
  mutable std::vector<Action*> m_Actions;

};

} // namespace mitk



#endif /* TRANSITION_H_HEADER_INCLUDED_C19AE06B */

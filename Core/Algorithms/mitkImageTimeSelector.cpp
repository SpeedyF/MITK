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

#include "mitkImageTimeSelector.h"

//##ModelId=3E1B1975031E
mitk::ImageTimeSelector::ImageTimeSelector() : m_TimeNr(0), m_ChannelNr(0)
{
}


//##ModelId=3E1B1975033C
mitk::ImageTimeSelector::~ImageTimeSelector()
{
}

//##ModelId=3E3BD0CC0232
void mitk::ImageTimeSelector::GenerateOutputInformation()
{
	mitk::Image::ConstPointer input  = this->GetInput();
	mitk::Image::Pointer output = this->GetOutput();

	itkDebugMacro(<<"GenerateOutputInformation()");

  int dim=(input->GetDimension()<3?input->GetDimension():3);
	output->Initialize(input->GetPixelType(), dim, input->GetDimensions());

  // initialize geometry
  output->SetGeometry(dynamic_cast<Geometry3D*>(input->GetSlicedGeometry(m_TimeNr)->Clone().GetPointer()));
  output->SetPropertyList(input->GetPropertyList()->Clone());  
}

//##ModelId=3E3BD0CE0194
void mitk::ImageTimeSelector::GenerateData()
{
  const Image::RegionType& requestedRegion = GetOutput()->GetRequestedRegion();

  //do we really need a complete volume at a time?
  if(requestedRegion.GetSize(2)>1)
  	SetVolumeItem(GetVolumeData(m_TimeNr, m_ChannelNr), 0);
  else
  //no, so take just a slice!
    SetSliceItem(GetSliceData(requestedRegion.GetIndex(2), m_TimeNr, m_ChannelNr), requestedRegion.GetIndex(2), 0);
}

void mitk::ImageTimeSelector::GenerateInputRequestedRegion()
{
  Superclass::GenerateInputRequestedRegion();

  mitk::ImageToImageFilter::InputImagePointer input =
    const_cast< mitk::ImageToImageFilter::InputImageType * > ( this->GetInput() );
  mitk::Image::Pointer output = this->GetOutput();

  Image::RegionType requestedRegion;
  requestedRegion = output->GetRequestedRegion();
  requestedRegion.SetIndex(3, m_TimeNr);
  requestedRegion.SetIndex(4, m_ChannelNr);
  requestedRegion.SetSize(3, 1);
  requestedRegion.SetSize(4, 1);

  input->SetRequestedRegion( & requestedRegion );
}

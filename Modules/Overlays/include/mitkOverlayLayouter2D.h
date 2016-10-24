/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#ifndef OVERLAYLAYOUTER2D_H
#define OVERLAYLAYOUTER2D_H

#include "MitkOverlaysExports.h"
#include "mitkAbstractAnnotationRenderer.h"

namespace mitk {

class BaseRenderer;

/** \brief The OverlayLayouter2D updates and manages Overlays and the respective Layouters. */
/** An Instance of the OverlayLayouter2D can be registered to several BaseRenderer instances in order to
 * call the update method of each Overlay during the rendering phase of the renderer.
 * See \ref OverlaysPage for more info.
*/
class MITKOVERLAYS_EXPORT OverlayLayouter2D : public AbstractAnnotationRenderer {

public:

  /** \brief virtual destructor in order to derive from this class */
  virtual ~OverlayLayouter2D();

  const std::string GetID() const;

  static OverlayLayouter2D *GetAnnotationRenderer(const std::string& rendererID);

  static const std::string ANNOTATIONRENDERER_ID;

private:

  OverlayLayouter2D(const std::string& rendererID);

  /** \brief copy constructor */
  OverlayLayouter2D( const OverlayLayouter2D &);

  /** \brief assignment operator */
  OverlayLayouter2D &operator=(const OverlayLayouter2D &);

};

} // namespace mitk

#endif // OVERLAYLAYOUTER2D_H



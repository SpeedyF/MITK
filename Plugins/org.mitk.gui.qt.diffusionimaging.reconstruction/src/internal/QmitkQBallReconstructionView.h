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

#ifndef _QMITKQBALLRECONSTRUCTIONVIEW_H_INCLUDED
#define _QMITKQBALLRECONSTRUCTIONVIEW_H_INCLUDED

#include <QmitkAbstractView.h>
#include <mitkILifecycleAwarePart.h>

#include <string>

#include "ui_QmitkQBallReconstructionViewControls.h"

#include <berryIPartListener.h>
#include <berryISelectionListener.h>
#include <berryIStructuredSelection.h>

#include <mitkImage.h>
#include <mitkDiffusionPropertyHelper.h>
#include <itkVectorImage.h>

typedef short DiffusionPixelType;

struct QbrSelListener;

struct QbrShellSelection;

/*!
 * \ingroup org_mitk_gui_qt_qballreconstruction_internal
 *
 * \brief QmitkQBallReconstructionView
 *
 * Document your class here.
 */
class QmitkQBallReconstructionView : public QmitkAbstractView, public mitk::ILifecycleAwarePart
{

  friend struct QbrSelListener;

  friend struct QbrShellSelection;

  typedef mitk::DiffusionPropertyHelper::GradientDirectionType            GradientDirectionType;
  typedef mitk::DiffusionPropertyHelper::GradientDirectionsContainerType  GradientDirectionContainerType;
  typedef mitk::DiffusionPropertyHelper::BValueMapType                    BValueMapType;
  typedef itk::VectorImage< DiffusionPixelType, 3 >                       ITKDiffusionImageType;

  // this is needed for all Qt objects that should have a MOC object (everything that derives from QObject)
  Q_OBJECT

  public:

  static const std::string VIEW_ID;

  QmitkQBallReconstructionView();
  virtual ~QmitkQBallReconstructionView();

  virtual void CreateQtPartControl(QWidget *parent) override;

  /// \brief Creation of the connections of main and control widget
  virtual void CreateConnections();

  ///
  /// Sets the focus to an internal widget.
  ///
  virtual void SetFocus() override;

  /// \brief Called when the view gets activated
  virtual void Activated() override;

  /// \brief Called when the view gets deactivated
  virtual void Deactivated() override;

  /// \brief Called when the view becomes visible
  virtual void Visible() override;

  /// \brief Called when the view becomes hidden
  virtual void Hidden() override;

  static const int nrconvkernels;

protected slots:

  void ReconstructStandard();
  void MethodChoosen(int method);
  void Reconstruct(int method, int normalization);

  void NumericalQBallReconstruction(mitk::DataStorage::SetOfObjects::Pointer inImages, int normalization);
  void AnalyticalQBallReconstruction(mitk::DataStorage::SetOfObjects::Pointer inImages, int normalization);
  void MultiQBallReconstruction(mitk::DataStorage::SetOfObjects::Pointer inImages);


  /**
   * @brief PreviewThreshold Generates a preview of the values that are cut off by the thresholds
   * @param threshold
   */
  void PreviewThreshold(int threshold);

protected:

  /// \brief called by QmitkAbstractView when DataManager's selection has changed
  virtual void OnSelectionChanged(berry::IWorkbenchPart::Pointer part, const QList<mitk::DataNode::Pointer>& nodes) override;

  Ui::QmitkQBallReconstructionViewControls* m_Controls;

  template<int L>
  void TemplatedAnalyticalQBallReconstruction(mitk::DataNode* dataNodePointer, float lambda, int normalization);

  template<int L>
  void TemplatedMultiQBallReconstruction(float lambda, mitk::DataNode*);

  void SetDefaultNodeProperties(mitk::DataNode::Pointer node, std::string name);

  //void Create

  QScopedPointer<berry::ISelectionListener> m_SelListener;
  berry::IStructuredSelection::ConstPointer m_CurrentSelection;

  mitk::DataStorage::SetOfObjects::Pointer m_DiffusionImages;

private:

  std::map< const mitk::DataNode *, QbrShellSelection * > m_ShellSelectorMap;
  void GenerateShellSelectionUI(mitk::DataStorage::SetOfObjects::Pointer set);
};




#endif // _QMITKQBALLRECONSTRUCTIONVIEW_H_INCLUDED

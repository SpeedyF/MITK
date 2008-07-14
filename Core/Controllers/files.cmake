SET(CPP_FILES
  mitkBaseController.cpp
  mitkCameraController.cpp
  mitkCameraRotationController.cpp
  mitkFocusManager.cpp
  mitkLimitedLinearUndo.cpp
  mitkMovieGenerator.cpp
  mitkMultiStepper.cpp
  mitkOperationEvent.cpp
  mitkProgressBar.cpp
  mitkRenderingManager.cpp
  mitkSegmentationInterpolationController.cpp
  mitkSliceNavigationController.cpp
  mitkSlicesCoordinator.cpp
  mitkSlicesRotator.cpp
  mitkSlicesSwiveller.cpp
  mitkStatusBar.cpp
  mitkStepper.cpp
  mitkTestManager.cpp
  mitkToolManager.cpp
  mitkUndoController.cpp
  mitkUndoModel.cpp
  mitkVerboseLimitedLinearUndo.cpp
  mitkVtkInteractorCameraController.cpp
  mitkVtkLayerController.cpp
  # VtkQRenderWindowInteractor.cpp
)
IF(WIN32)
  SET(CPP_FILES ${CPP_FILES} mitkMovieGeneratorWin32.cpp)
ENDIF(WIN32)




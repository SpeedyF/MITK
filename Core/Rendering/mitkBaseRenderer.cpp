#include "BaseRenderer.h"

//##ModelId=3D6A1791038B
void mitk::BaseRenderer::SetData(mitk::DataTreeIterator* iterator)
{
	m_DataTreeIterator = iterator;
	Modified();
}

//##ModelId=3E3314720003
void mitk::BaseRenderer::SetWindowId(void *id)
{
}

//##ModelId=3E330C4D0395
const MapperSlotId mitk::BaseRenderer::defaultMapper = 1;

//##ModelId=3E33162C00D0
void mitk::BaseRenderer::Paint()
{
}

//##ModelId=3E331632031E
void mitk::BaseRenderer::Initialize()
{
}

//##ModelId=3E33163703D9
void mitk::BaseRenderer::Resize(int w, int h)
{
}

//##ModelId=3E33163A0261
void mitk::BaseRenderer::InitRenderer(mitk::RenderWindow* renderwindow)
{
    m_RenderWindow = renderwindow;
}

//##ModelId=3E3799250397
void mitk::BaseRenderer::InitSize(int w, int h)
{
}

//##ModelId=3E3D2F120050
mitk::BaseRenderer::BaseRenderer() : m_DataTreeIterator(NULL), m_RenderWindow(NULL)
{
    m_DisplayGeometry = mitk::DisplayGeometry::New();
}


//##ModelId=3E3D2F12008C
mitk::BaseRenderer::~BaseRenderer()
{
}


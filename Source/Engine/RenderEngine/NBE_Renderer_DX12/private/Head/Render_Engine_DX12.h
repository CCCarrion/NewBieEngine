#ifndef __Render_Engine_DX12_h__
#define __Render_Engine_DX12_h__

#include "Config/Config.h"
#include "Engine/RenderEngine/Interface/NBE_Interface_Renderer.h"

NBE_NS_Render_START

class Render_Engine_DX12 : public Render_Engine_Interface
{
public :
    Render_Engine_DX12();
    virtual ~Render_Engine_DX12();

    const NBE_WString & GetRendererName() override;
};


NBE_NS_Render_END



#endif
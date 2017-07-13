#include "../public/NBE_Renderer_DX12.h"
#include "Head/Render_Engine_DX12.h"

NBE_NS_Render_START

Render_Engine_DX12* g_pRenderEngine;
NBE_CREATE_UPtr_IMPLEMENT_FUNC_NAME(Render_Engine_Interface, Render_Engine_DX12)
{
    if (g_pRenderEngine == nullptr)
    {
         uptr = NBE_MakeUniquePtr(Render_Engine_DX12)();
         g_pRenderEngine = (Render_Engine_DX12*)uptr.get();
    }
    else
    {
        uptr = Render_Engine_Interface_UPtr(g_pRenderEngine);
    }
}

NBE_NS_Render_END
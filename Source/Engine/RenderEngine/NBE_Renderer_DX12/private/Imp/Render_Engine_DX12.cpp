#include "../Head/Render_Engine_DX12.h"





NBE_NS_Render_START

Render_Engine_DX12::Render_Engine_DX12()
{

}


Render_Engine_DX12::~Render_Engine_DX12()
{

}

const NBE_WString  & Render_Engine_DX12::GetRendererName()
{
    static NBE_WString const name(L"D3D12");
    return name;
}

NBE_NS_Render_END
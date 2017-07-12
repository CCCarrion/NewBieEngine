#ifndef __GPU_MemoryManager_DX12_h__
#define __GPU_MemoryManager_DX12_h__

#include "Config/Config.h"
#include "Engine/RenderEngine/Interface/NBE_Interface_Renderer.h"

NBE_NS_Render_START

class GPU_Resource_DX12 :public GPU_Resource_Interface
{
public:
    GPU_Resource_DX12();
    ~GPU_Resource_DX12() override;
    type_NBE_ERR Create() override;
};


class GPU_MemoryManager_DX12 : public GPU_MemoryManager_Interface
{
public :
    GPU_MemoryManager_DX12();
    ~GPU_MemoryManager_DX12() override;


private:

};

NBE_NS_Render_END
#endif
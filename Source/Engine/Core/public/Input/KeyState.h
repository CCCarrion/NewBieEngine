#ifndef __KeyState_h__
#define __KeyState_h__

#include "Engine/Tools/Config/Config.h"
#include "Engine/xPlatform/Interface/NBE_Device_Input.h"

namespace NBE::Core
{
    using NBE_NS_OS;

    struct InputState
    {
        enum InputType
        {
            _Unknown = -1,
            _KeyCode = 0,
            _MouseButton,
            _MouseMove,

            _TypeCount
        };

        InputType type;

        union 
        {

        };
    }; 
}
#endif 
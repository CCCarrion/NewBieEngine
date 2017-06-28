#ifndef __NBE_Interface_OS_h__
#define __NBE_Interface_OS_h__

#include <Engine/Tools/Config/Config.h>
#include <Engine/Tools/Util/public/Smartpointer.h>

#pragma region LIB_IMPLEMENT(NBE_OS_IMP)

#undef NBE_API
#if defined(LIB_BUILD) && defined(NBE_OS_IMP)
#define NBE_API DLLEXPORT
#else
#define NBE_API DLLIMPORT
#endif

#pragma endregion

NBE_NS_OS_START

        class  OS_APP_Interface
        {
        public:
            virtual ~OS_APP_Interface() = 0 {};
            virtual type_NBE_ERR CreateApp(const NBE_Engine_Config&) = 0;
			virtual type_NBE_ERR ShowCanvas() = 0;
            virtual void Tick() = 0;


        private:

        };
NBE_Ptr_Typedef(OS_APP_Interface)

NBE_NS_OS_END
#endif 
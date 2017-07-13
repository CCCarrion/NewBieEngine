#ifndef __Assert_h__
#define __Assert_h__

#include "Debugger.h"

//__VA_ARGS__ ?
#define NBE_ASSERT ( isFalse, ...) \
		if (!(bool)(isFalse)) { \
			NBE_Logger("\nAssertion failed in " #__FILE__ " @ " #__LINE__ "\n"); \
			NBE_Logger("\'" #isFalse "\' is false"); \
			NBE_Logger(...); \
		}

#endif

#ifndef  __NBE_Macro_Windows_h__
#define  __NBE_Macro_Windows_h__

//OS's Program Entry
#define OS_APP_ENTRY(func)  void main()		\
							{				\
								func();		\
							}

//Os's Program Interface Attribute
#define DLLIMPORT __declspec(dllimport)
#define DLLEXPORT __declspec(dllexport)



#endif //  __NBE_Macro_Windows_h__

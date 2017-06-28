#ifndef __SmartPointer_h__
#define __SmartPointer_h__


//maybe will rewrite to fit our project
//now here we use std ptr

#include <memory>
template<class T>
using NBE_SharedPtr = std::shared_ptr<T>;
template<class T>
using NBE_WeakPtr = std::weak_ptr<T>;
template<class T>
using NBE_UniquePtr = std::unique_ptr<T>;

#define NBE_MakeSharedPtr std::make_shared;

//Easy TypeDef for SmartPointer
#define NBE_Ptr_Typedef(TypeName)                       \
typedef NBE_UniquePtr<##TypeName##> TypeName##_UPtr;    \
typedef NBE_SharedPtr<##TypeName##> TypeName##_SPtr;    \
typedef NBE_WeakPtr<##TypeName##> TypeName##_WPtr;
#endif

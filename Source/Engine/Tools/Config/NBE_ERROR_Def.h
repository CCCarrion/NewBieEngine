#ifndef __NBE_ERROR_Def_h__
#define __NBE_ERROR_Def_h__

//Error Code Type
typedef  long long type_NBE_ERR;


//No Error Flag
#define NBE_OK 0LL;

//OS Error
#define NBE_ERROR_OS_BASE_VALUE (1LL<<32)
//Windows Error
#define NBE_ERROR_WINDOWS_BASE_VALUE NBE_ERROR_OS_BASE_VALUE | (0LL<<24)

//Render Error
#define NBE_ERROR_RENDER_BASE_VALUE (2LL<<32)
//DX12 Error 
#define NBE_ERROR_DX12_BASE_VALUE  NBE_ERROR_RENDER_BASE_VALUE | (0LL<<24)
#define NBE_ERROR_DX12_NOT_SURPPORT NBE_ERROR_DX12_BASE_VALUE+1


//Err Handle 

#define NBE_CHECK_SUCCEED(a) (a==0)
#define NBE_CHECK_FAILED(a) !NBE_CHECK_SUCCEED(a)

inline void ThrowIfFailed(type_NBE_ERR err)
{
    if (NBE_CHECK_FAILED(err))
    {
        //todo:  log or  do  something

    }
}
#endif
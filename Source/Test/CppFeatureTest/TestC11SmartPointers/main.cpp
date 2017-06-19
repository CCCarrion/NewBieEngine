

#include <memory>
template<class T,class ..._Types>
inline std::shared_ptr<T> alias_make(_Types &&... args)
{
	return std::make_shared<T>(_STD forward<_Types>(args)...);
}

void main()
{
	std::shared_ptr<int> pInt = alias_make<int>(110);
	getchar();
}
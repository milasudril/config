#ifdef __WAND__
target[name[value.h] type[include]]
#endif

#ifndef CONFIG_VALUE_H
#define CONFIG_VALUE_H

#include "parameter.h"
#include <type_traits>

namespace Config
	{
	template<class T>
	class ValueConverter;
		
	template<class T>
	struct Value final:public Parameter
		{
		constexpr Value(const char_t* label_,uint32_t id_
			,uint32_t group_,Mode type_,const ValueConverter<T>* conv):
			Parameter(label_,sizeof(*this),id_,group_,type_,type<T>(),sizeof(T))
			,converter(conv)
			{}

		const ValueConverter<T>* converter;
		
		private:
			template<class U>
			static constexpr TypeData type()
				{
				return std::is_floating_point<U>::value?TypeData::FLOAT : is_unsigned<U>();
				}
			
			template<class U>
			static constexpr TypeData is_unsigned()
				{
				return std::is_unsigned<U>::value?TypeData::INT_UNSIGNED:TypeData::INT;
				}
		};
	};

#endif

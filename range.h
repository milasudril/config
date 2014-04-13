#ifdef __WAND__
target[name[range.h] type[include]]
#endif

#ifndef CONFIG_RANGE_H
#define CONFIG_RANGE_H

#include "parameter.h"
#include <type_traits>

namespace Config
	{
	template<class T>
	class ValueConverter;
		
	template<class T>
	struct Range final:public Parameter
		{
		constexpr Range(const char_t* label_,uint32_t id_
			,uint32_t group_,Mode type_,uint32_t offset
			,const ValueConverter<T>* conv
			,T val_min_,T val_max_):
			Parameter(label_,sizeof(*this),id_,group_,type_,type<T>(),sizeof(T)
				,offset)
			,converter(conv),val_min(val_min_),val_max(val_max_)
			{}

		const ValueConverter<T>* converter;
		T val_min;
		T val_max;
		
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

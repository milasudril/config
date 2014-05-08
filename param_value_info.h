#ifdef __WAND__
target[name[param_value_info.h] type[include]]
#endif

#ifndef CONFIG_PARAM_VALUE_INFO_H
#define CONFIG_PARAM_VALUE_INFO_H

#include "paraminfo.h"

namespace Herbs
	{
	template<class T>
	class ValueMap;
	}

namespace Config
	{		
	template<class T>
	struct ParamValueInfo:public Paraminfo
		{
		ParamValueInfo(const char_t* name,uint32_t id
			,T& value,Herbs::ValueMap<T>& val_map):
			Paraminfo(name,Paraminfo::TypeId<T>::value,id)
				,m_value(value),m_val_map(val_map){}
				
		T& m_value;
		Herbs::ValueMap<T>& m_val_map;				
		};
	}
	
#endif

#ifdef __WAND__
target[name[param_group_info.h] type[include]]
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
		ParamValueInfo(const char_t* name,uint16_t id
			,T& value,Herbs::ValueMap<T>& val_map):
			ParamobjInfo(name,Paraminfo::IdType<T>::value,id)
				,m_value(value),m_val_map(val_map){}
				
		T& m_value;
		ValueMap<T>& val_map;				
		}
	}
	
#endif
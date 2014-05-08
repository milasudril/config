#ifdef __WAND__
target[name[param_numeric_info.h] type[include]]
#endif

#ifndef CONFIG_PARAM_NUMERIC_INFO_H
#define CONFIG_PARAM_NUMERIC_INFO_H

#include "param_value_info.h"

namespace Config
	{
	template<class T>
	struct ParamNumericInfo:public ParamValueInfo<T>
		{
		enum class UpdateMethod:uint32_t
			{
			 NORMAL
			,CONTINOUS
			};
			
		ParamNumericInfo(const char_t* name,uint32_t id
			,T& value,Herbs::ValueMap<T>& val_map,UpdateMethod pref_update_method):
			ParamValueInfo<T>(name,id,value,val_map)
			,m_pref_update_method(pref_update_method)
			{}		
		
		UpdateMethod m_pref_update_method;
		};
	}

#endif

#ifdef __WAND__
target[name[param_valueraw_info.h] type[include]]
#endif

#ifndef CONFIG_PARAMVALUERAW_INFO_H
#define CONFIG_PARAMVALUERAW_INFO_H

#include "param_value_info.h"

namespace Config
	{		
	template<class T>
	struct ParamValuerawInfo:public ParamValueInfo<T>
		{	
		ParamValuerawInfo(const char_t* name,Paraminfo::Type type,uint32_t id,T& value
			,typename ParamValueInfo<T>::UpdateMethod update_method):
			ParamValueInfo<T>(name,type,id,value,update_method)
				{}
		};
	}
	
#endif

#ifdef __WAND__
target[name[param_value_info.h] type[include]]
#endif

#ifndef CONFIG_PARAM_VALUE_INFO_H
#define CONFIG_PARAM_VALUE_INFO_H

#include "paraminfo.h"

namespace Config
	{		
	template<class T>
	struct ParamValueInfo:public Paraminfo
		{
		enum class UpdateMethod:uint32_t
			{
			 NORMAL
			,CONTINOUS
			};
		
		ParamValueInfo(const char_t* name,Paraminfo::Type type,uint32_t id,T& value
			,UpdateMethod update_method):
			Paraminfo(name,type,id)
				,m_value(value),m_update_method(update_method){}
				
		T& m_value;
		UpdateMethod m_update_method;
		};
	}
	
#endif

#ifdef __WAND__
target[name[param_intannotated_info.h] type[include]]
#endif

#ifndef CONFIG_PARAM_INTANNOTATED_INFO_H
#define CONFIG_PARAM_INTANNOTATED_INFO_H

#include "param_value_info.h"

namespace Config
	{
	template<class T>
	struct ParamIntannotatedInfo:public ParamValueInfo<T>
		{
		ParamIntannotatedInfo(const char_t* name,Paraminfo::Type type,uint32_t id
			,uint32_t& value,const char_t* const* labels):
			ParamValueInfo<T>(name,type,id)
				,m_labels(labels){}
				

		const char_t* const* m_labels;
		};
	}
	
#endif
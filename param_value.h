#ifdef __WAND__
target[name[param_value.h] type[include]]
#endif

#ifndef CONFIG_PARAM_VALUE_H
#define CONFIG_PARAM_VALUE_H

#include "paramobj.h"

namespace Herbs
	{
	template<class T>
	class ValueMap;
	}

namespace Config
	{
	template<class T>
	class ParamValue:public ParamObj
		{
		public:
			struct Baseinfo
				{
				ParamObj::Baseinfo baseinfo;
				T* value_ptr;
				ValueMap<T>* val_map;
				};	
			
			ParamValue(const Herbs::String& name,const ParamObj& group,uint16_t id
				,T& value,ValueMap<T>& val_map):
				ParamObj(name,group,id),m_value(value),m_val_map(val_map)
				{}
			
			virtual void valueUpdate(const void* ptr_val_new)
				{
				m_value=*((const T*)ptr_val_new);
				}

		private:
			T& m_value;
			ValueMap<T>& m_val_map;
		};
	}
	
#endif

#ifdef __WAND__
target[name[param_value.h] type[include]]
#endif

#ifndef CONFIG_PARAM_VALUE_H
#define CONFIG_PARAM_VALUE_H

#include "paramobj.h"
#include "param_value_info.h"

namespace Herbs
	{
	template<class T>
	class ValueMap;
	}

namespace Config
	{
	template<class T>
	class ParamValue:public Paramobj
		{
		public:
			ParamGroup(const Paraminfo& info,const Paramobj& group):
				Paramobj(info,group)
				,m_value( ((const ParamValueInfo&)info).m_value )
				,m_val_map( ((const ParamValueInfo&)info).m_val_map )
				{}
			
			virtual void valueUpdate(const void* ptr_val_new)
				{m_value=*((const T*)ptr_val_new);}
			
			virtual void controlCreate(UIProvider& ui)
				{ui.create(*this);}
			
			Herbs::ValueMap<T>& valueMapGet()
				{return m_val_map;}

		private:
			T& m_value;
			Herbs::ValueMap<T>& m_val_map;
		};
	}
	
#endif

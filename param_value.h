#ifdef __WAND__
target[name[param_value.h] type[include]]
#endif

#ifndef CONFIG_PARAM_VALUE_H
#define CONFIG_PARAM_VALUE_H

#include "paramobj.h"
#include "param_value_info.h"
#include "uiprovider.h"

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
			ParamValue(const Paraminfo& info,Paramobj* group):
				Paramobj(info,group)
				,m_value( ((const ParamValueInfo<T>&)info).m_value )
				,m_val_map( ((const ParamValueInfo<T>&)info).m_val_map )
				{}
			
			T& valueGet()
				{return m_value;}
			
			Herbs::ValueMap<T>& valueMapGet()
				{return m_val_map;}

		private:
			T& m_value;
			Herbs::ValueMap<T>& m_val_map;
		};
	}
	
#endif

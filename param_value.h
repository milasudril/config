#ifdef __WAND__
target[name[param_value.h] type[include]]
#endif

#ifndef CONFIG_PARAM_VALUE_H
#define CONFIG_PARAM_VALUE_H

#include "paramobj.h"
#include "param_value_info.h"

namespace Config
	{
	template<class T>
	class ParamValue:public Paramobj
		{
		public:		
			ParamValue(const Paraminfo& info,ParamGroup* group):
				Paramobj(info,group)
				,m_value( ((const ParamValueInfo<T>&)info).m_value )
				,m_update_method( ((const ParamValueInfo<T>&)info).m_update_method )
				{}
			
			T& valueGet()
				{return *m_value;}
				
			typename ParamValueInfo<T>::UpdateMethod updateMethodGet() const
				{return m_update_method;}

		private:
			T* m_value;
			typename ParamValueInfo<T>::UpdateMethod m_update_method;
		};
	}
	
#endif
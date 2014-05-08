#ifdef __WAND__
target[name[param_numeric.h] type[include]]
#endif

#ifndef CONFIG_PARAM_NUMERIC_H
#define CONFIG_PARAM_NUMERIC_H

#include "param_value.h"
#include "param_numeric_info.h"

namespace Config
	{
	template<class T>
	class ParamNumeric:public ParamValue<T>
		{
		public:
			static Paramobj* create(const Paraminfo& info,Paramobj* group)
				{return new ParamNumeric(info,group);}
			
			ParamNumeric(const Paraminfo& info,Paramobj* group):
				ParamValue<T>(info,group)
				,m_update_method( ((const ParamNumericInfo<T>&)info).m_pref_update_method )
				{}
			
			typename ParamNumericInfo<T>::UpdateMethod updateMethodGet() const
				{return m_update_method;}
			
			virtual void controlCreate(UIProvider& ui)
				{ui.create(*this);}
				
		private:
			typename ParamNumericInfo<T>::UpdateMethod m_update_method;
		};
	}

#endif
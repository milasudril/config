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
			ParamNumeric(const Paraminfo& info,const Paramobj& group):
				ParamValue<T>(info,group)
				,m_update_method( ((const ParamNumericInfo&)info).m_pref_update_method )
				{}
			
			ParamNumericInfo::UpdateMethod updateMethodGet() const
				{return m_update_method;}
			
			virtual void controlCreate(UIProvider& ui)
				{ui.create(*this);}
				
		private:
			ParamNumericInfo::UpdateMethod m_update_method;
		};
	}

#endif
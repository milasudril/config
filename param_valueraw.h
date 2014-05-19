#ifdef __WAND__
target[name[param_valueraw.h] type[include]]
#endif

#ifndef CONFIG_PARAMVALUERAW_H
#define CONFIG_PARAMVALUERAW_H

#include "param_value.h"

namespace Config
	{
	template<class T>
	class ParamValueraw:public ParamValue<T>
		{
		public:
			static Paramobj* create(const Paraminfo& info,ParamGroup* group)
				{return new ParamValueraw(info,group);}
		
			ParamValueraw(const Paraminfo& info,ParamGroup* group):
				ParamValue<T>(info,group)
				{}
				
			void controlCreate(UIProvider& ui)
				{ui.create(*this);}
		};
		
		

	}
	
#endif

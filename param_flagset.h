#ifdef __WAND__
target[name[param_flagset.h] type[include]]
#endif

#ifndef CONFIG_PARAM_FLAGSET_H
#define CONFIG_PARAM_FLAGSET_H

#include "param_intannotated.h"

namespace Config
	{
	template<class T>
	class ParamFlagset:public ParamIntannotated<T>
		{
		public:
			static Paramobj* create(const Paraminfo& info,ParamGroup* group)
				{return new ParamFlagset(info,group);}
		
			ParamFlagset(const Paraminfo& info,ParamGroup* group):
				ParamIntannotated<T>(info,group){}
				
			void controlCreate(UIProvider& ui)
				{ui.create(*this);}
		};
	}
	
#endif

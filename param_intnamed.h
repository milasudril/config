#ifdef __WAND__
target[name[param_intnamed.h] type[include]]
#endif

#ifndef CONFIG_PARAM_INTNAMED_H
#define CONFIG_PARAM_INTNAMED_H

#include "param_intannotated.h"

namespace Config
	{
	template<class T>
	class ParamIntnamed:public ParamIntannotated<T>
		{
		public:
			static Paramobj* create(const Paraminfo& info,Paramobj* group)
				{return new ParamIntnamed(info,group);}
		
			ParamIntnamed(const Paraminfo& info,Paramobj* group):
				ParamIntannotated<T>(info,group){}
				
			void controlCreate(UIProvider& ui)
				{ui.create(*this);}
		};
	}
	
#endif
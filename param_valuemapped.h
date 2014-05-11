#ifdef __WAND__
target[name[param_valuemapped.h] type[include]]
#endif

#ifndef CONFIG_PARAM_VALUEMAPPED_H
#define CONFIG_PARAM_VALUEMAPPED_H

#include "param_value.h"
#include "param_valuemapped_info.h"
#include "uiprovider.h"

namespace Config
	{
	template<class T>
	class ParamValuemapped:public ParamValue<T>
		{
		public:
			static Paramobj* create(const Paraminfo& info,ParamGroup* group)
				{return new ParamValuemapped(info,group);}
		
			ParamValuemapped(const Paraminfo& info,ParamGroup* group):
				ParamValue<T>(info,group)
				,m_val_map( ((const ParamValuemappedInfo<T>&)info).m_val_map )
				{}
			
			MathExt::ValueMap<T>& valueMapGet()
				{return m_val_map;}
				
			void controlCreate(UIProvider& ui)
				{ui.create(*this);}

		private:
			MathExt::ValueMap<T>& m_val_map;
		};
	}
	
#endif

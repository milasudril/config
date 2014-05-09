#ifdef __WAND__
target[name[paramset_impl.h] type[include]]
dependency[paramset_impl.o]
#endif

#ifndef CONFIG_PARAMSET_IMPL_H
#define CONFIG_PARAMSET_IMPL_H

#include "paramset.h"
#include <herbs/array/array.h>

namespace Config
	{
	struct Paraminfo;
	class Paramobj;
	
	class ParamsetImpl:public Paramset
		{
		public:
			ParamsetImpl(const Paraminfo* const* params);
			~ParamsetImpl();
			void uiCreate(UIProvider& ui) const;
		
		private:
			Herbs::Array<Paramobj*> m_params;
		};
	}

#endif


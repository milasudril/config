#ifdef __WAND__
target[name[paramset_impl.h] type[include]]
dependency[paramset_impl.o]
#endif

#ifndef CONFIG_PARAMSET_IMPL_H
#define CONFIG_PARAMSET_IMPL_H

#include "paramset.h"
#include <map>

namespace Config
	{
	struct Paraminfo;
	class Paramobj;
	
	class ParamsetImpl:public Paramset
		{
		public:
			ParamsetImpl(const Paraminfo* const* params);
			Paramobj& paramFromIdGet(uint32_t param_id);
		
		private:
			std::map<uint32_t,Paramobj*> parameters;
		};
	}

#endif


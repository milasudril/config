#ifdef __WAND__
target[name[paramset_impl.h] type[include]]
dependency[paramset_impl.o]
#endif

#ifndef CONFIG_PARAMSET_H
#define CONFIG_PARAMSET_H

#include <map>

namespace Config
	{
	struct Paraminfo;
	class Paramobj;
	
	class ParamsetImpl:public Paramset
		{
		public:
			ParamSet(const Paraminfo* const* params);
			ParamObj& paramFromIdGet(uint16_t param_id);
		
		private:
			std::map<uint16_t,ParamObj*> parameters;
		};
	}

#endif


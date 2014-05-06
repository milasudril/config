#ifdef __WAND__
target[name[paramset.h] type[include]]
#endif

#ifndef CONFIG_PARAMSET_H
#define CONFIG_PARAMSET_H

#include <map>

namespace Config
	{
	struct ParamInfo;
	class ParamObj;
	
	class Paramset
		{
		public:
			virtual const ParamObj& paramFromIdGet(uint16_t param_id)=0;
		};
	}

#endif


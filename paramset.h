#ifdef __WAND__
target[name[paramset.h] type[include]]
#endif

#ifndef CONFIG_PARAMSET_H
#define CONFIG_PARAMSET_H

#include "paramobj.h"
#include <map>

namespace Config
	{
	class ParamSet
		{
		public:
			ParamObj& paramFromIdGet(uint16_t param_id);
		
		private:
			std::map<uint16_t,ParamObj*> parameters;
		};
	}

#endif


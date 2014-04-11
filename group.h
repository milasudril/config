#ifdef __WAND__
target[name[group.h] type[include]]
#endif

#ifndef CONFIG_GROUP_H
#define CONFIG_GROUP_H

#include "parameterinfo.h"

namespace Config
	{
	struct Group:public ParameterInfo
		{
		};
	};

#endif

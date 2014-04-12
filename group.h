#ifdef __WAND__
target[name[group.h] type[include]]
#endif

#ifndef CONFIG_GROUP_H
#define CONFIG_GROUP_H

#include "parameterinfo.h"

namespace Config
	{
	struct Group final:public ParameterInfo
		{
		constexpr Group(const char_t* label_,uint32_t id_,uint32_t group_):
			ParameterInfo(label_,sizeof(*this),id_,group_,Type::GROUP)
			{}
		};
	};

#endif

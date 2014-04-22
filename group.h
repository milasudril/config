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
		constexpr Group(const char_t* label_,uint32_t id_,uint32_t level_):
			ParameterInfo(label_,sizeof(*this),id_,Type::GROUP),level(level_)
			{}
		uint32_t level;
		};
	};

#endif

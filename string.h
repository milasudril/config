#ifdef __WAND__
target[name[string.h] type[include]]
#endif

#ifndef CONFIG_STRING_H
#define CONFIG_STRING_H

#include "parameter.h"

namespace Config
	{
	struct String final:public Parameter
		{
		constexpr String(const char_t* label_,uint32_t id_
			,uint32_t group_,Mode type_):
			Parameter(label_,sizeof(*this),id_,group_,type_,TypeData::STRING,0)
			{}		
		};
	};

#endif

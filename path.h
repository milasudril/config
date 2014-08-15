#ifdef __WAND__
target[name[path.h] type[include]]
#endif

#ifndef CONFIG_PATH_H
#define CONFIG_PATH_H

#include "parameter.h"

namespace Config
	{
	struct Path final:public Parameter
		{
		constexpr Path(const char_t* label_,uint32_t id_
			,uint32_t group_,Mode type_,uint32_t offset):
			Parameter(label_,sizeof(*this),id_,group_,type_,TypeData::PATH
				,sizeof(char_t),offset)
			{}
		};
	};

#endif

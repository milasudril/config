#ifdef __WAND__
target[name[datetime.h] type[include]]
#endif

#ifndef CONFIG_DATETIME_H
#define CONFIG_DATETIME_H

#include "parameter.h"

namespace Config
	{
	struct DateTime final:public Parameter
		{
		constexpr DateTime(const char_t* label_,uint32_t id_
			,uint32_t group_,Mode type_):
			Parameter(label_,sizeof(*this),id_,group_,type_,TypeData::DATETIME,0)
			{}		
		};
	};

#endif

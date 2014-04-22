#ifdef __WAND__
target[name[datetime.h] type[include]]
#endif

#ifndef CONFIG_DATETIME_H
#define CONFIG_DATETIME_H

#include "parameter.h"
#include <herbs/timet/timet.h>

namespace Config
	{
	struct DateTime final:public Parameter
		{
		constexpr DateTime(const char_t* label_,uint32_t id_
			,Mode type_,uint32_t offset):
			Parameter(label_,sizeof(*this),id_,type_,TypeData::DATETIME
				,sizeof(Herbs::Timestamp),offset)
			{}		
		};
	};

#endif

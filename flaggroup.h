#ifdef __WAND__
target[name[flaggroup.h] type[include]]
#endif

#ifndef CONFIG_FLAGGROUP_H
#define CONFIG_FLAGGROUP_H

#include "parameter.h"

namespace Config
	{
	struct FlagGroup final:public Parameter
		{
		constexpr FlagGroup(const char_t* label_,uint32_t id_
			,uint32_t group_,Mode type_,const char_t* const* list):
			Parameter(label_,sizeof(*this),id_,group_,type_,TypeData::FLAGGROUP,0)
			,item_list(list)
			{}

		const char_t* const* item_list;
		
		};
	};

#endif

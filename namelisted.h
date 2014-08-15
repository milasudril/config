#ifdef __WAND__
target[name[namelisted.h] type[include]]
#endif

#ifndef CONFIG_NAMELISTED_H
#define CONFIG_NAMELISTED_H

#include "parameter.h"

namespace Config
	{
	struct NameListed final:public Parameter
		{
		constexpr NameListed(const char_t* label_,uint32_t id_
			,uint32_t group_,Mode type_,uint32_t offset,const char_t* const* list):
			Parameter(label_,sizeof(*this),id_,group_,type_,TypeData::NAME_LISTED
				,sizeof(uint32_t),offset)
			,item_list(list)
			{}

		const char_t* const* item_list;
		
		};
	};

#endif

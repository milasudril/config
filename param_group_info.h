#ifdef __WAND__
target[name[param_group_info.h] type[include]]
#endif

#ifndef CONFIG_PARAM_GROUP_INFO_H
#define CONFIG_PARAM_GROUP_INFO_H

#include "paraminfo.h"

namespace Config
	{		
	struct ParamGroupInfo:public Paraminfo
		{
		ParamGroupInfo(const char_t* name,uint16_t id,uint16_t level):
			ParamobjInfo(name,Paraminfo::Type::GROUP,id),m_level(level){}

		uint16_t m_level;
		};
	}
	
#endif

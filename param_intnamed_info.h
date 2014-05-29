#ifdef __WAND__
target[name[param_intnamed_info.h] type[include]]
#endif

#ifndef CONFIG_PARAM_INTNAMED_INFO_H
#define CONFIG_PARAM_INTNAMED_INFO_H

#include "param_intannotated_info.h"

namespace Config
	{
	template<class T>
	struct ParamIntnamedInfo:public ParamIntannotatedInfo
		{
		static constexpr Paraminfo::Type typeId();
		};
		
	template<>
	constexpr Paraminfo::Type ParamIntnamedInfo<uint32_t>::typeId()
		{return Paraminfo::Type::INTNAMED32;}
	
	template<>
	constexpr Paraminfo::Type ParamIntnamedInfo<uint64_t>::typeId()
		{return Paraminfo::Type::INTNAMED64;}
	}
	
#endif

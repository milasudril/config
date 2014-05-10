#ifdef __WAND__
target[name[param_flagset_info.h] type[include]]
#endif

#ifndef CONFIG_PARAM_FLAGSET_INFO_H
#define CONFIG_PARAM_FLAGSET_INFO_H

#include "param_intannotated_info.h"

namespace Config
	{
	template<class T>
	struct ParamFlagsetInfo:public ParamIntannotatedInfo<T>
		{
		static constexpr Paraminfo::Type typeId();
		};
		
	template<>
	constexpr Paraminfo::Type ParamFlagsetInfo<uint32_t>::typeId()
		{return Paraminfo::Type::FLAGSET32;}
	
	template<>
	constexpr Paraminfo::Type ParamFlagsetInfo<uint64_t>::typeId()
		{return Paraminfo::Type::FLAGSET64;}
	}
	
#endif

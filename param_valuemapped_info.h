#ifdef __WAND__
target[name[param_valuemapped_info.h] type[include]]
#endif

#ifndef CONFIG_PARAM_VALUEMAPPED_INFO_H
#define CONFIG_PARAM_VALUEMAPPED_INFO_H

#include "paraminfo.h"

namespace Herbs
	{	
	class Timestamp;
	
	template<class T>
	class Stringbase;
	
	typedef Stringbase<char_t> String;
	
	class Path;
	}
	
namespace MathExt
	{
	template<class T>
	class ValueMap;
	}
	

namespace Config
	{		
	template<class T>
	struct ParamValuemappedInfo:public ParamValueInfo<T>
		{
		static constexpr Paraminfo::Type typeId();
		
		ParamValuemappedInfo(const char_t* name,uint32_t id
			,T& value
			,typename ParamValueInfo<T>::UpdateMethod update_method
			,MathExt::ValueMap<T>& val_map):
			ParamValueInfo<T>(name,typeId(),id,value,update_method)
				,m_val_map(val_map){}

		MathExt::ValueMap<T>& m_val_map;				
		};
	
	template<>
	constexpr Paraminfo::Type ParamValuemappedInfo<int32_t>::typeId()
		{return Paraminfo::Type::INT32;}
	
	template<>
	constexpr Paraminfo::Type ParamValuemappedInfo<int64_t>::typeId()
		{return Paraminfo::Type::INT64;}
		
	template<>
	constexpr Paraminfo::Type ParamValuemappedInfo<uint32_t>::typeId()
		{return Paraminfo::Type::UINT32;}
	
	template<>
	constexpr Paraminfo::Type ParamValuemappedInfo<uint64_t>::typeId()
		{return Paraminfo::Type::UINT64;}
	
	template<>
	constexpr Paraminfo::Type ParamValuemappedInfo<float>::typeId()
		{return Paraminfo::Type::FLOAT;}
		
	template<>
	constexpr Paraminfo::Type ParamValuemappedInfo<double>::typeId()
		{return Paraminfo::Type::DOUBLE;}
	
	template<>
	constexpr Paraminfo::Type ParamValuemappedInfo<Herbs::Timestamp>::typeId()
		{return Paraminfo::Type::TIMESTAMP;}
		
	template<>
	constexpr Paraminfo::Type ParamValuemappedInfo<Herbs::String>::typeId()
		{return Paraminfo::Type::STRING;}
		
	template<>
	constexpr Paraminfo::Type ParamValuemappedInfo<Herbs::Path>::typeId()
		{return Paraminfo::Type::PATH;}
	}
	
#endif

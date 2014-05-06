#ifdef __WAND__
target[type[include] name[interfacebuilder.h]
#endif

#ifndef CONFIG_INTERFACEBUILDER_H
#define CONFIG_INTERFACEBUILDER_H

#include "parameterinfo.h"
#include <cstddef>

namespace Herbs
	{
	template<class T>
	class Stringbase;
	
	typedef Stringbase<char_t> String;
	
	class Path;
	class Timestamp;
	}

namespace Config
	{
	class Group;
	template<class T> class Value;
	template<class T> class Range;
	class NameListed;
	class FlagGroup;
	class String;
	class Path;
	class DateTime;

	class InterfaceBuilder
		{
		public:
			virtual void create(const Group& group,uint32_t in_group)=0;
	
			virtual void create(const Value<int32_t>& value,uint32_t in_group,int32_t& x)=0;
			virtual void create(const Value<int64_t>& value,uint32_t in_group,int64_t& x)=0;
			virtual void create(const Range<int32_t>& range,uint32_t in_group,int32_t& x)=0;
			virtual void create(const Range<int64_t>& range,uint32_t in_group,int64_t& x)=0;
			virtual void create(const Value<uint32_t>& value,uint32_t in_group,uint32_t& x)=0;
			virtual void create(const Value<uint64_t>& value,uint32_t in_group,uint64_t& x)=0;
			virtual void create(const Range<uint32_t>& range,uint32_t in_group,uint32_t& x)=0;
			virtual void create(const Range<uint64_t>& range,uint32_t in_group,uint64_t& x)=0;
			
			virtual void create(const Value<float>& value,uint32_t in_group,float& x)=0;
			virtual void create(const Value<double>& value,uint32_t in_group,double& x)=0;
			virtual void create(const Range<float>& range,uint32_t in_group,float& x)=0;
			virtual void create(const Range<double>& range,uint32_t in_group,double& x)=0;
			
			virtual void create(const NameListed& namelist,uint32_t in_group,uint32_t& x)=0;
			virtual void create(const FlagGroup& group,uint32_t in_group,uint32_t& x)=0;
			
			virtual void create(const String& string,uint32_t in_group,Herbs::String& x)=0;
			virtual void create(const Path& path,uint32_t in_group,Herbs::Path& x)=0;
			
			virtual void create(const DateTime& date,uint32_t in_group,Herbs::Timestamp& x)=0;
		};
	}

#endif

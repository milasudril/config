#ifdef __WAND__
target[name[test_interface.h] type[include] ]
dependency[test_interface.o]
#endif

#ifndef CONFIG_TESTINTERFACE_H
#define CONFIG_TESTINTERFACE_H

#include "interfacebuilder.h"

namespace Config
	{
	class TestInterface:public InterfaceBuilder
		{
		public:
			void create(const Group& group,uint32_t in_group);
	
			void create(const Value<int32_t>& value,uint32_t in_group,int32_t& x);
			void create(const Value<int64_t>& value,uint32_t in_group,int64_t& x);
			void create(const Range<int32_t>& range,uint32_t in_group,int32_t& x);
			void create(const Range<int64_t>& range,uint32_t in_group,int64_t& x);
			void create(const Value<uint32_t>& value,uint32_t in_group,uint32_t& x);
			void create(const Value<uint64_t>& value,uint32_t in_group,uint64_t& x);
			void create(const Range<uint32_t>& range,uint32_t in_group,uint32_t& x);
			void create(const Range<uint64_t>& range,uint32_t in_group,uint64_t& x);
			
			void create(const Value<float>& value,uint32_t in_group,float& x);
			void create(const Value<double>& value,uint32_t in_group,double& x);
			void create(const Range<float>& range,uint32_t in_group,float& x);
			void create(const Range<double>& range,uint32_t in_group,double& x);
			
			void create(const NameListed& namelist,uint32_t in_group,uint32_t& x);
			void create(const FlagGroup& group,uint32_t in_group,uint32_t& x);
			
			void create(const String& string,uint32_t in_group,Herbs::String& x);
			void create(const Path& path,uint32_t in_group,Herbs::Path& x);
			
			void create(const DateTime& date,uint32_t in_group,Herbs::Timestamp& x);
		};
	}

#endif

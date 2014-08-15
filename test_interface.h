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
			void create(const Group& group,size_t level);
	
			void create(const Value<int32_t>& value,int32_t& x);
			void create(const Value<int64_t>& value,int64_t& x);
			void create(const Range<int32_t>& range,int32_t& x);
			void create(const Range<int64_t>& range,int64_t& x);
			void create(const Value<uint32_t>& value,uint32_t& x);
			void create(const Value<uint64_t>& value,uint64_t& x);
			void create(const Range<uint32_t>& range,uint32_t& x);
			void create(const Range<uint64_t>& range,uint64_t& x);
			
			void create(const Value<float>& value,float& x);
			void create(const Value<double>& value,double& x);
			void create(const Range<float>& value,float& x);
			void create(const Range<double>& value,double& x);
			
			void create(const NameListed& namelist,uint32_t& x);
			void create(const FlagGroup& group,uint32_t& x);
			
			void create(const String& string,Herbs::String& x);
			void create(const Path& path,Herbs::Path& x);
			
			void create(const DateTime& date,Herbs::Timestamp& x);
		};
	}

#endif

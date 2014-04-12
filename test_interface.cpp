#ifdef __WAND__
target[name[test_interface.o] type[object]]
#endif

#include "test_interface.h"
#include "group.h"
#include "value.h"
#include "range.h"
#include "namelisted.h"
#include "flaggroup.h"
#include "string.h"
#include "path.h"
#include "datetime.h"

#include <herbs/stringformat/stringformat.h>
#include <herbs/intformat/intformat.h>
#include <herbs/floatformat/floatformat.h>
#include <herbs/path/path.h>
#include <herbs/timet/timet.h>


#include <herbs/textconverter/textconverter.h>
#include <cstdio>

namespace
	{
	Herbs::Stringbase<char> toUTF8(const Herbs::String& str)
		{
		Herbs::TextConverter converter(ENCODING_LOCAL
			,Herbs::TextConverter::Encoding::UTF_8);
		size_t length_in=str.length();
		Herbs::Stringbase<char> ret(converter.lengthFactorGet()*length_in);
		size_t n_bytes=converter.convert(str.begin(),ret.begin(),length_in*sizeof(char_t));
		ret.lengthValidSet(n_bytes/sizeof(charsys_t));
		return ret;
		}
	
	void print(const Herbs::String& string){
		fputs(toUTF8(string).begin(),stdout);
		}

	}


void Config::TestInterface::create(const Group& group,size_t level)
	{
	print(Herbs::format(STR("Group: %0 \"%1\" (level %2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(group.id)
		,group.label
		,Herbs::IntFormat<size_t>(level)
		}));
	}

void Config::TestInterface::create(const Value<int32_t>& value,int32_t& x)
	{
	print(Herbs::format(STR("Value<int32_t>: %0 \"%1\" (%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(value.id)
		,value.label
		,Herbs::IntFormat<int32_t>(x)
		}));
	}

void Config::TestInterface::create(const Value<int64_t>& value,int64_t& x)
	{
	print(Herbs::format(STR("Value<int64_t>: %0 \"%1\" (%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(value.id)
		,value.label
		,Herbs::IntFormat<int64_t>(x)
		}));
	}

void Config::TestInterface::create(const Range<int32_t>& range,int32_t& x)
	{
	print(Herbs::format(STR("Range<int32_t>: %0 \"%1\" [%3,%4](%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(range.id)
		,range.label
		,Herbs::IntFormat<int32_t>(x)
		,Herbs::IntFormat<int32_t>(range.val_min)
		,Herbs::IntFormat<int32_t>(range.val_max)
		}));
	}

void Config::TestInterface::create(const Range<int64_t>& range,int64_t& x)
	{
	print(Herbs::format(STR("Range<int64_t>: %0 \"%1\" [%3,%4](%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(range.id)
		,range.label
		,Herbs::IntFormat<int64_t>(x)
		,Herbs::IntFormat<int64_t>(range.val_min)
		,Herbs::IntFormat<int64_t>(range.val_max)
		}));
	}

void Config::TestInterface::create(const Value<uint32_t>& value,uint32_t& x)
	{
	print(Herbs::format(STR("Value<uint32_t>: %0 \"%1\" (%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(value.id)
		,value.label
		,Herbs::IntFormat<uint32_t>(x)
		}));
	}

void Config::TestInterface::create(const Value<uint64_t>& value,uint64_t& x)
	{
	print(Herbs::format(STR("Value<uint64_t>: %0 \"%1\" (%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(value.id)
		,value.label
		,Herbs::IntFormat<uint64_t>(x)
		}));
	}

void Config::TestInterface::create(const Range<uint32_t>& range,uint32_t& x)
	{
	print(Herbs::format(STR("Range<uint32_t>: %0 \"%1\" [%3,%4](%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(range.id)
		,range.label
		,Herbs::IntFormat<uint32_t>(x)
		,Herbs::IntFormat<uint32_t>(range.val_min)
		,Herbs::IntFormat<uint32_t>(range.val_max)
		}));
	}
	
void Config::TestInterface::create(const Range<uint64_t>& range,uint64_t& x)
	{
	print(Herbs::format(STR("Range<uint64_t>: %0 \"%1\" [%3,%4](%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(range.id)
		,range.label
		,Herbs::IntFormat<uint64_t>(x)
		,Herbs::IntFormat<uint64_t>(range.val_min)
		,Herbs::IntFormat<uint64_t>(range.val_max)
		}));
	}


void Config::TestInterface::create(const Value<float>& value,float& x)
	{
	print(Herbs::format(STR("Value<float>: %0 \"%1\" (%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(value.id)
		,value.label
		,Herbs::FloatFormat<7>(x)
		}));
	}

void Config::TestInterface::create(const Value<double>& value,double& x)
	{
	print(Herbs::format(STR("Value<double>: %0 \"%1\" (%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(value.id)
		,value.label
		,Herbs::FloatFormat<15>(x)
		}));
	}

void Config::TestInterface::create(const Range<float>& range,float& x)
	{
	print(Herbs::format(STR("Range<float>: %0 \"%1\" [%3,%4](%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(range.id)
		,range.label
		,Herbs::FloatFormat<7>(x)
		,Herbs::FloatFormat<7>(range.val_min)
		,Herbs::FloatFormat<7>(range.val_max)
		}));
	}

void Config::TestInterface::create(const Range<double>& range,double& x)
	{
	print(Herbs::format(STR("Range<double>: %0 \"%1\" [%3,%4](%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(range.id)
		,range.label
		,Herbs::FloatFormat<15>(x)
		,Herbs::FloatFormat<15>(range.val_min)
		,Herbs::FloatFormat<15>(range.val_max)
		}));
	}

	
void Config::TestInterface::create(const NameListed& namelist,uint32_t& x)
	{
	print(Herbs::format(STR("NameListed: %0 \"%1\" (%2 \"%3\")\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(namelist.id)
		,namelist.label
		,Herbs::IntFormat<uint32_t>(x)
		,namelist.item_list[x]
		}));
	}


void Config::TestInterface::create(const FlagGroup& group,uint32_t& x)
	{
	print(Herbs::format(STR("FlagGroup: %0 \"%1\" (%2)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(group.id)
		,group.label
		,Herbs::IntFormat<uint32_t>(x,2)
		}));
	}

void Config::TestInterface::create(const String& string,Herbs::String& x)
	{
	print(Herbs::format(STR("String: %0 \"%1\" (\"%2\")\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(string.id)
		,string.label
		,x.begin()
		}));
	}

void Config::TestInterface::create(const Path& path,Herbs::Path& x)
	{
	print(Herbs::format(STR("path: %0 \"%1\" (\"%2\")\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(path.id)
		,path.label
		,Herbs::String(x).begin()
		}));
	}

void Config::TestInterface::create(const DateTime& date,Herbs::Timestamp& x)
	{
	print(Herbs::format(STR("path: %0 \"%1\" (%2-%3-%4 %5:%6:%7)\n")
		,
		{
		 Herbs::IntFormat<uint32_t>(date.id)
		,date.label
		,Herbs::IntFormat<uint32_t>( x.yearGet() )
		,Herbs::IntFormat<uint32_t>( x.monthGet() )
		,Herbs::IntFormat<uint32_t>( x.dayGet() )
		,Herbs::IntFormat<uint32_t>(x.hourGet())
		,Herbs::IntFormat<uint32_t>(x.minGet())
		,Herbs::IntFormat<uint32_t>(x.secGet())
		}));
	}


#ifdef __WAND__
target[name[test_params.o] type[object]]
#endif

#include "test_params.h"
#include "test_setup.h"
#include "group.h"

namespace
	{
	static const Config::Group lorem_ipsum
		{
		STR("Lorem Ipsum")
		,0
		,Config::ParameterInfo::ID_INVALID
		};
	
	static const Config::Group mollit
		{
		STR("Mollit Anim")
		,1
		,0
		};
	
	static const Config::ParameterInfo* params[]=
		{
		&lorem_ipsum
		,&mollit
		,nullptr
		};
	}

	
Config::TestParams::TestParams(TestSetup& obj):test(obj)
	{
	}

const Config::ParameterInfo* const* Config::TestParams::paramInfoGet() const
	{
	return params;
	}

void* Config::TestParams::paramAddressGet(uint32_t id) const
	{
	return nullptr;
	}

	
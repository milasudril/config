#ifdef __WAND__
target[name[test_params.o] type[object]]
#endif

#include "test_params.h"
#include "test_setup.h"
#include "group.h"
#include "value.h"

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
	
	static const Config::Value<int32_t> val_int32
		{
		STR("int32")
		,2
		,1
		,Config::Parameter::Mode::PARAM
		,offsetof(Config::TestSetup,val_int32)
		,nullptr
		};
	
	static const Config::Value<int64_t> val_int64
		{
		STR("int64")
		,3
		,0
		,Config::Parameter::Mode::PARAM
		,offsetof(Config::TestSetup,val_int64)
		,nullptr
		};
	
	static const Config::ParameterInfo* params[]=
		{
		&mollit
		,&lorem_ipsum
		,&val_int32
		,&val_int64
		,nullptr
		};
	}

	
Config::TestParams::TestParams(TestSetup& obj):test(obj)
	{
	}

Config::ParamCollector::SetupInfo Config::TestParams::setupinfoGet() const
	{
	return {params,sizeof(test),&test};
	}


	
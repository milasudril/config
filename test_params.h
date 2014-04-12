#ifdef __WAND__
target[name[test_params.h] type[include]]
dependency[test_params.o]
#endif

#ifndef CONFIG_TESTPARAMS_H
#define CONFIG_TESTPARAMS_H

#include "paramcollector.h"

namespace Config
	{
	class TestSetup;

	class TestParams:public ParamCollector
		{
		public:
			TestParams(TestSetup& obj);
			
			const ParameterInfo* const* paramInfoGet() const;
			void* paramAddressGet(uint32_t id) const;
			
			TestSetup& test;
		};
	}

#endif

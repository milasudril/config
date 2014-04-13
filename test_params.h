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
			SetupInfo setupinfoGet() const;
			
			TestSetup& test;
		};
	}

#endif

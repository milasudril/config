#ifdef __WAND__
target[name[config-test.exe] platform[;Windows] type[application]]
target[name[config-test] type[application]]
#endif

#include <herbs/main/main.h>
#include "test_interface.h"
#include "test_setup.h"
#include "test_params.h"
#include "paramcollector.h"
#include "interfacecreate.h"

int MAIN(int argc,char_t* argv[])
	{
	Config::TestInterface builder;
	Config::TestSetup setup;
	Config::TestParams params(setup);
	
	Config::interfaceCreate(params,builder);
	return 0;
	}

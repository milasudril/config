#ifdef __WAND__
target[name[config-test.exe] platform[;Windows] type[application]]
target[name[config-test] type[application]]
#endif

#include "test_interface.h"
#include "test_setup.h"
#include "test_params.h"
#include "paramcollector.h"
#include "interfacecreate.h"

#include <herbs/main/main.h>
#include <herbs/messageprinterstdio/messageprinterstdio.h>
#include <herbs/exception/exception.h>

int MAIN(int argc,charsys_t* argv[])
	{
	try
		{
		Config::TestInterface builder;
		Config::TestSetup setup;
		setup.val_int32=1;
		setup.val_int64=2;
		
		Config::TestParams params(setup);
		
		Config::interfaceCreate(params,builder);
		}
	catch(const Herbs::Exception& e)
		{
		Herbs::MessagePrinterStdio printer(Herbs::StreamSpec::STDOUT);
		e.print(printer);
		}
	return 0;
	}

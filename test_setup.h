#ifdef __WAND__
target[name[test_setup.h]type[include]]
#endif

#ifndef CONFIG_TESTSETUP_H
#define CONFIG_TESTSETUP_H

#include <herbs/path/path.h>
#include <herbs/timet/timet.h>

namespace Config
	{
	struct TestSetup
		{
		int32_t val_int32;
		int64_t val_int64;
		int32_t range_int32;
		int64_t range_int64;
		
		uint32_t val_uint32;
		uint64_t val_uint64;
		uint32_t range_uint32;
		uint64_t range_uint64;
		
		float val_float;
		double val_double;
		float range_float;
		double range_double;
		
		uint32_t val_ilabel;
		uint32_t val_flags;
		
		Herbs::String val_string;
		Herbs::Path val_path;
		Herbs::Timestamp val_date;
		};
	}

#endif

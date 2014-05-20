#ifdef __WAND__
target[name[paramset_descriptor.h] type[include]]
#endif

#ifndef CONFIG_PARAMSETDESCRIPTOR_H
#define CONFIG_PARAMSETDESCRIPTOR_H

#include <herbs/array/array.h>

namespace Config
	{
	class ParamsetDescirptor
		{
		public:
			virtual Herbs::Array<ParamsetDescriptor> paraminfoGet()=0;
		};
	}

#endif


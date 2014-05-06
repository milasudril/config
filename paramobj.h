#ifdef __WAND__
target[name[paramobj.h] type[include]]
#endif

#ifndef CONFIG_PARAMOBJ_H
#define CONFIG_PARAMOBJ_H

namespace Config
	{
	class ParamObj
		{
		public:
			virtual void valueUpdate(const void* ptr_val_new)=0;
		};
	}

#endif


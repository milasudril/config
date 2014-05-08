#ifdef __WAND__
target[name[uiprovider.h] type[include]]
#endif

#ifndef CONFIG_UIPROVIDER_H
#define CONFIG_UIPROVIDER_H

namespace Config
	{
	class ParamValueInt32;
	class ParamGroup;
	
	class UIProvider
		{
		public:
			virtual void create(ParamValueInt32& param)=0;
			virtual void create(ParamGroup& group)=0;
			
		};
	}

#endif

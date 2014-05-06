#ifdef __WAND__
target[name[uiprovider.h] type[include]]
#endif

#ifndef CONFIG_UIPROVIDER_H
#define CONFIG_UIPROVIDER_H

namespace Config
	{
	class ParamGroup;
	class UIProvider
		{
		public:
			virtual void create(const ParamGroup& group)=0;
		};
	}

#endif

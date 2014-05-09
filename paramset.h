#ifdef __WAND__
target[name[paramset.h] type[include]]
#endif

#ifndef CONFIG_PARAMSET_H
#define CONFIG_PARAMSET_H


namespace Config
	{
	class UIProvider;
	
	class Paramset
		{
		public:
			virtual void uiCreate(UIProvider& ui) const=0;
		};
	}

#endif


#ifdef __WAND__
target[name[paramset.h] type[include]]
dependency[paramset.o]
#endif

#ifndef CONFIG_PARAMSET_H
#define CONFIG_PARAMSET_H

#include <herbs/array/array.h>
#include <herbs/listpacked/listpacked.h>

namespace Config
	{
	struct Paraminfo;
	class Paramobj;
	class UIProvider;
	
	class Paramset
		{
		public:
			Paramset(const Herbs::ListPacked& params);
			~Paramset();
			void uiCreate(UIProvider& ui) const;
		
		private:
			Herbs::Array<Paramobj*> m_params;
		};
	}

#endif


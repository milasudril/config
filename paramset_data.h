#ifdef __WAND__
target[name[paramset_data.h] type[include]]
#endif

#ifndef CONFIG_PARAMSET_DATA_H
#define CONFIG_PARAMSET_DATA_H

#include "paramset.h"

namespace Config
	{
	class UIProvider;
	
	template<class T>
	class ParamsetData
		{
		public:
			ParamsetData():params(data){}
			
			const T& dataGet() const
				{return data;}
			
			T& dataGet() 
				{return data;}
				
			void uiCreate(UIProvider& provider)
				{
				params.uiCreate(provider);
				}
			
		private:
			T data;
			Paramset params;
		};
	}

#endif

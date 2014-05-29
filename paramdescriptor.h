#ifdef __WAND__
target[name[paramdescriptor.h] type[include]]
#endif

#ifndef CONFIG_PARAMDESCRIPTOR_H
#define CONFIG_PARAMDESCRIPTOR_H

#include <herbs/chartype/chartype.h>
#include <herbs/listpacked/listpacked.h>

namespace Config
	{
	class Paramdescriptor
		{
		public:
			virtual const char_t* titleGet()=0;
			virtual Herbs::ListPacked paraminfoGet()=0;			
		};
	}

#endif


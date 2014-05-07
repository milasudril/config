#ifdef __WAND__
target[name[paraminfo.h] type[include]]
#endif

#ifndef CONFIG_PARAMINFO_H
#define CONFIG_PARAMINFO_H

namespace Config
	{
	struct Paraminfo
		{
		const char_t* name;
		uint32_t type;
		uint16_t id;
		};
	}
				
#endif


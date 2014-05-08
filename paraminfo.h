#ifdef __WAND__
target[name[paraminfo.h] type[include]]
#endif

#ifndef CONFIG_PARAMINFO_H
#define CONFIG_PARAMINFO_H

#include <herbs/chartype/chartype.h>

namespace Config
	{
	struct Paraminfo
		{
		enum class Type:uint32_t
			{
			 GROUP
			,INT32
			,INT64
			,UINT32
			,UINT64
			,INT_NAMED
			,FLOAT
			,DOUBLE
			,TIMESTAMP
			,FLAGSET
			,STRING
			,PATH
			,ID_MAX
			};
		
		template<class T>
		class TypeId;
		
		Paraminfo(const char_t* name,Type type,uint32_t id):
			m_name(name),m_type(type),m_id(id){}
			
		const char_t* m_name;
		Type m_type;
		uint32_t m_id;
		};
	}
				
#endif


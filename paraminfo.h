#ifdef __WAND__
target[name[paraminfo.h] type[include]]
#endif

#ifndef CONFIG_PARAMINFO_H
#define CONFIG_PARAMINFO_H

namespace Config
	{
	struct Paraminfo
		{
		enum Type:class uint32_t
			{
			 INT32
			,INT64
			,FLOAT
			,DOUBLE
			,TIMESTAMP
			,GROUP
			,STRING
			,PATH
			,UINT32
			,UINT64
			};
		
		template<class T>
		class IdType;
		
		Paraminfo(const char_t* name,Type type,uint16_t id):
			m_name(name),m_type(type),m_id(id){}
			
		const char_t* m_name;
		uint32_t m_type;
		uint16_t m_id;
		};
	}
				
#endif


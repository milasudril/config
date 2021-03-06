#ifdef __WAND__
target[name[paramobj.h] type[include]]
dependency[paramobj.o]
#endif

#ifndef CONFIG_PARAMOBJ_H
#define CONFIG_PARAMOBJ_H

#include <herbs/string/string.h>

namespace Config
	{
	class UIProvider;
	class Paraminfo;
	class ParamGroup;

	class Paramobj
		{
		public:
			typedef Paramobj* (*Factory)(const Paraminfo& pi,ParamGroup* group);
			
			Paramobj(const Paraminfo& pi,ParamGroup* group);
			
			const Herbs::String& nameGet() const
				{return m_name;}
			
			ParamGroup* groupGet()
				{return m_group;}
			
			uint32_t idGet() const
				{return m_id;}

			virtual void controlCreate(UIProvider& ui)=0;
			virtual ~Paramobj(){}
			
		private:
			Herbs::String m_name;
			ParamGroup* m_group;
			uint32_t m_id;
		};
	}

#endif


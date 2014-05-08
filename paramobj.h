#ifdef __WAND__
target[name[paramobj.h] type[include]]
#endif

#ifndef CONFIG_PARAMOBJ_H
#define CONFIG_PARAMOBJ_H

#include <herbs/string/string.h>

namespace Config
	{
	class UIProvider;
	class Paraminfo;

	class Paramobj
		{
		public:
			typedef Paramobj* (*Factory)(const Paraminfo& pi,const Paramobj& group);
			
			Paramobj(const Paraminfo& pi,const Paramobj& group);
			
			const Herbs::String nameGet() const
				{return m_name;}
			
			const Paramobj& groupGet() const
				{return m_group;}
			
			uint16_t idGet() const
				{return m_id;}
			
			virtual void valueUpdate(const void* ptr_val_new)=0;
			virtual void controlCreate(UIProvider& ui)=0;
			
		private:
			Herbs::String m_name;
			const Paramobj& m_group;
			uint16_t m_id;
		};
	}

#endif


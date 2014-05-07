#ifdef __WAND__
target[name[paramobj.h] type[include]]
#endif

#ifndef CONFIG_PARAMOBJ_H
#define CONFIG_PARAMOBJ_H

#include <herbs/string/string.h>

namespace Config
	{
	class UIProvider;

	class Paramobj
		{
		public:			
			Paramobj(const Herbs::String& name,const Paramobj& group,uint16_t id);
			
			const Herbs::String nameGet() const
				{return m_name;}
			
			const ParamObj& groupGet() const
				{return m_group;}
			
			uint16_t idGet() const
				{return m_id;}
			
			virtual void valueUpdate(const void* ptr_val_new){};
			virtual void controlCreate(UIProvider& ui)=0;
			
		private:
			Herbs::String m_name;
			const Paramobj& m_group;
			uint16_t m_id;
		};
	}

#endif


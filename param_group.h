#ifdef __WAND__
target[name[param_group.h] type[include]]
dependency[param_group.o]
#endif

#ifndef CONFIG_PARAM_GROUP_H
#define CONFIG_PARAM_GROUP_H

#include "paramobj.h"
#include "param_group_info.h"

namespace Config
	{
	class ParamGroup:public Paramobj
		{
		public:
					
			ParamGroup(const Herbs::String& name,const Paramobj& group,uint16_t id
				,uint16_t level):
				Paramobj(name,group,id),m_level(level)
				{}
			
			void controlCreate(UIProvider& ui);

			uint16_t levelGet() const
				{return m_level;}
			
		private:
			uint16_t m_level;
		};
	}
	
#endif

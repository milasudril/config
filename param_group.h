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
			static Paramobj* create(const Paraminfo& info,ParamGroup* group);
			
			ParamGroup(const Paraminfo& info,ParamGroup* group):
				Paramobj(info,group)
				,m_level( ((const ParamGroupInfo&)info).m_level )
				{}
			
			void controlCreate(UIProvider& ui);

			uint32_t levelGet() const
				{return m_level;}
			
		private:
			uint32_t m_level;
		};
	}
	
#endif

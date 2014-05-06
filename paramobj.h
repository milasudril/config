#ifdef __WAND__
target[name[paramobj.h] type[include]]
#endif

#ifndef CONFIG_PARAMOBJ_H
#define CONFIG_PARAMOBJ_H

namespace Config
	{
	class ParamObj
		{
		public:
			ParamObj(const Herbs::String& name);
			virtual void valueUpdate(const void* ptr_val_new)=0;
			
		private:
			Herbs::String m_name;
		};
	}

#endif


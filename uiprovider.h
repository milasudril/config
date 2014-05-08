#ifdef __WAND__
target[name[uiprovider.h] type[include]]
#endif

#ifndef CONFIG_UIPROVIDER_H
#define CONFIG_UIPROVIDER_H

namespace Config
	{
	template<class T>
	class ParamNumeric;
	
	class ParamGroup;
	
	class UIProvider
		{
		public:
			virtual void create(ParamNumeric<int32_t>& param)=0;
			virtual void create(ParamNumeric<int64_t>& param)=0;
			virtual void create(ParamNumeric<uint32_t>& param)=0;
			virtual void create(ParamNumeric<uint64_t>& param)=0;
			virtual void create(ParamNumeric<float>& param)=0;
			virtual void create(ParamNumeric<double>& param)=0;
			virtual void create(ParamGroup& group)=0;
			
		};
	}

#endif

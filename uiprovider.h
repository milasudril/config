#ifdef __WAND__
target[name[uiprovider.h] type[include]]
#endif

#ifndef CONFIG_UIPROVIDER_H
#define CONFIG_UIPROVIDER_H

namespace Herbs
	{
	template<class T>
	class Stringbase;
	typedef Stringbase<char_t> String;
	
	class Path;
	class Timestamp;
	}

namespace Config
	{	
	template<class T>
	class ParamValuemapped;
	
	class ParamGroup;

	template<class T>
	class ParamIntnamed;
	
	template<class T>
	class ParamFlagset;
	
	class UIProvider
		{
		public:
			virtual void create(ParamGroup& group)=0;
			virtual void create(ParamValuemapped<int32_t>& param)=0;
			virtual void create(ParamValuemapped<int64_t>& param)=0;
			virtual void create(ParamValuemapped<uint32_t>& param)=0;
			virtual void create(ParamValuemapped<uint64_t>& param)=0;
			virtual void create(ParamIntnamed<uint32_t>& param)=0;
			virtual void create(ParamIntnamed<uint64_t>& param)=0;
			virtual void create(ParamValuemapped<float>& param)=0;
			virtual void create(ParamValuemapped<double>& param)=0;
			virtual void create(ParamValuemapped<Herbs::Timestamp>& param)=0;
			virtual void create(ParamFlagset<uint32_t>& param)=0;
			virtual void create(ParamFlagset<uint64_t>& param)=0;
			virtual void create(ParamValuemapped<Herbs::String>& param)=0;
			virtual void create(ParamValuemapped<Herbs::Path>& param)=0;
		};
	}

#endif


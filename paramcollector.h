#ifdef __WAND__
target[name[paramcollector.h] type[include]]
#endif

#ifndef CONFIG_PARAMCOLLECTOR_H
#define CONFIG_PARAMCOLLECTOR_H

namespace Config
	{
	struct ParameterInfo;
		
	class ParamCollector
		{
		public:
			/**Returns an array of pointers to ParameterInfo objects. The last
			 * pointer has to be nullptr.
			*/
			virtual const ParameterInfo* const* paramInfoGet() const=0;
			
			/*Returns the address of the parameter with the given id;
			*/
			virtual void* paramAddressGet(uint32_t id) const=0;
		};
	}

#endif

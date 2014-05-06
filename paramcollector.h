#ifdef __WAND__
target[name[paramcollector.h] type[include]]
#endif

#ifndef CONFIG_PARAMCOLLECTOR_H
#define CONFIG_PARAMCOLLECTOR_H

#include <cstddef>

namespace Config
	{
	struct ParameterInfo;
		
	class ParamCollector
		{
		public:
			struct SetupInfo
				{
				/**An array of pointers to ParameterInfo objects. The last
				* pointer has to be nullptr.
				*/
				const ParameterInfo* const* param_info;
				
				/**The size of the setup BLOB.
				 */
				size_t blob_size;
				
				/**The BLOB address.
				*/
				void* blob_address;
				};
			
			virtual SetupInfo setupinfoGet() const=0;
		};
	}

#endif

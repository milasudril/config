#ifdef __WAND__
target[name[parameterinfo.h] type[include]]
#endif

#ifndef CONFIG_PARAMETERINFO_H
#define CONFIG_PARAMETERINFO_H

#include <herbs/chartype/chartype.h>
#include <cstdint>

namespace Config
	{
	struct ParameterInfo
		{
		static const uint32_t ID_INVALID=0xffffffff;
		
		enum class Type:uint32_t
			{
			 GROUP            /**<A parameter group.*/
			,PARAM_INPUT      /**<A normal parameter.*/
			,STATUS_INDICATOR /**<Same as PARAM_INPUT expect no user interaction.*/
			};
			
		const char_t* label;
		uint32_t size; /**<The size of the entire object.*/
		uint32_t id;
		uint32_t group;
		Type type;
		
		constexpr ParameterInfo(const char_t* label_,uint32_t id_
			,uint32_t group_,Type type_):
			label(label_),size(sizeof(*this)),id(id_),group(group_),type(type_)
			{}
		};
	}

#endif

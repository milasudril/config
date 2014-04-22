#ifdef __WAND__
target[name[parameter.h] type[include]]
#endif

#ifndef CONFIG_PARAMETER_H
#define CONFIG_PARAMETER_H

#include "parameterinfo.h"

namespace Config
	{
	struct Parameter:public ParameterInfo
		{
		enum class TypeData:uint32_t
			{
			 INT                /**<Value is a signed integer.*/
			,INT_RANGE          /**<Value is an interval of integers.*/
			,INT_UNSIGNED       /**<Value is an unsigned integer.*/
			,INT_UNSIGNED_RANGE /**<Value is an interval of unsigned integers.*/
		
			,FLOAT              /**<Value is a floating point number.*/
			,FLOAT_RANGE        /**<Value is float interval.*/
			,FLOAT_RESERVED_1
			,FLOAT_RESERVED_2
			
			,NAME_LISTED  /**<Value is an unsigned integer refering to a string given by plug.*/
			,FLAGGROUP    /**<Value is a bit-field.*/
			,STRING       /**<Value is an arbitrary string.*/
			,PATH         /**<Value is a search path.*/
			,DATETIME     /**<Value is a timestampm.*/
			};
		
		enum class Mode:uint32_t
			{
			PARAM=Type::PARAM_INPUT
			,STATUS=Type::STATUS_INDICATOR
			};

		TypeData data_type;
		uint32_t data_size;
		uint32_t data_offset;
		
		constexpr Parameter(const char_t* label_,uint32_t size_,uint32_t id_
			,Mode mode,TypeData data_type_,uint32_t data_size_
			,uint32_t data_offset_):
			ParameterInfo(label_,size_,id_,typeGet(mode))
			,data_type(data_type_),data_size(data_size_),data_offset(data_offset_)
			{}

		private:
			static constexpr Type typeGet(Mode m)
				{
				return m==Mode::PARAM? Type::PARAM_INPUT : Type::STATUS_INDICATOR;
				}
		};
	};

#endif

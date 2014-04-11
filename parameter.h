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

		TypeData type_data;
		uint32_t size_data;
		
		constexpr Parameter(const char_t* label_,uint32_t id_
			,uint32_t group_,Mode mode,TypeData type_data_,uint32_t size_data_):
			ParameterInfo(label_,id_,group_,typeGet(mode)),type_data(type_data_)
			,size_data(size_data_)
			{}
		private:
			static constexpr Type typeGet(Mode m)
				{
				return m==Mode::PARAM? Type::PARAM_INPUT : Type::STATUS_INDICATOR;
				}
		};
	};

#endif

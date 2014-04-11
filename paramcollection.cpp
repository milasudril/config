#ifdef __WAND__
target[name[paramcollection.o] type[object]]
#endif

#include "value.h"
#include "range.h"
#include "paramcollector.h"
#include "interfacebuilder.h"

#include <herbs/stack/stack.h>
#include <herbs/exceptionmissing/exceptionmissing.h>
#include <set>
#include <map>

namespace Config
	{
	void paramsCollect(const ParamCollector& params_in,InterfaceBuilder& builder)
		{
	
	//	Create look-up for parameter ID:s
		std::map<uint32_t,const ParameterInfo*> pmap;	
		auto params=params_in.paramInfoGet();
		while(*params!=nullptr)
			{
			auto ip=pmap.insert({(*params)->id,*params});
			if(!ip.second)
				{
			//	Duplicated ID
				throw Herbs::ExceptionMissing(___FILE__,__LINE__);
				}
			++params;
			}
			
		std::set<uint32_t> groups_created;
		Herbs::Stack<const ParameterInfo*> param_stack(16);
		params=params_in.paramInfoGet();
		param_stack.push(*params);
		while(param_stack.depth())
			{
			auto param=param_stack.pop();
			auto ip=groups_created.find(param->group);
			if(ip==groups_created.end())
				{
				param_stack.push(pmap[param->group]);
				}
			else
				{
			//	builder.create(param->group);
				}
			}
		/*
			switch((*params)->type)
				{
				case ParameterInfo::Type::GROUP:
					break;
				case ParameterInfo::Type::PARAM_INPUT:
					break;
				case ParameterInfo::Type::STATUS_INDICATOR:
					break;
				}
			++params;
		*/
		}
	}

#ifdef __WAND__
target[name[interfacecreate.o] type[object]]
#endif

#include "interfacecreate.h"
#include "group.h"
#include "value.h"
#include "range.h"
#include "namelisted.h"
#include "flaggroup.h"
#include "string.h"
#include "path.h"
#include "datetime.h"
#include "paramcollector.h"
#include "interfacebuilder.h"

#include <herbs/stack/stack.h>
#include <herbs/exceptionmissing/exceptionmissing.h>
#include <set>
#include <map>

namespace
	{
	template<class T>
	const T& downcast(const Config::ParameterInfo& obj)
		{
		if(obj.size==sizeof(T))
			{return (const T&)obj;}
	//	Inconsistent type
		throw Herbs::ExceptionMissing(___FILE__,__LINE__);
		}
	
	void createDispatch(void* ptr_data
		,Config::InterfaceBuilder& builder
		,const Config::Parameter& param)
		{
		using namespace Config;
		
		switch(param.type_data)
			{
			case Parameter::TypeData::INT:
				switch(param.size_data)
					{
					case 4:
						builder.create(downcast<Value<int32_t> >(param)
							,*(int32_t*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Value<int64_t> >(param)
							,*(int64_t*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
			case Parameter::TypeData::INT_RANGE:
				switch(param.size_data)
					{
					case 4:
						builder.create(downcast<Range<int32_t> >(param) 
							,*(int32_t*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Range<int64_t> >(param)
							,*(int64_t*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
				
			case Parameter::TypeData::INT_UNSIGNED:
				switch(param.size_data)
					{
					case 4:
						builder.create(downcast<Value<uint32_t> >(param)
							,*(uint32_t*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Value<uint64_t> >(param)
							,*(uint64_t*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
			
			case Parameter::TypeData::INT_UNSIGNED_RANGE:
				switch(param.size_data)
					{
					case 4:
						builder.create(downcast<Range<uint32_t> >(param)
							,*(uint32_t*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Range<uint64_t> >(param)
							,*(uint64_t*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
			
			case Parameter::TypeData::FLOAT:
				switch(param.size_data)
					{
					case 4:
						builder.create(downcast<Value<float> >(param)
							,*(float*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Value<double> >(param)
							,*(double*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
			
			case Parameter::TypeData::FLOAT_RANGE:
				switch(param.size_data)
					{
					case 4:
						builder.create(downcast<Range<float> >(param)
							,*(float*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Range<double> >(param)
							,*(double*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
				
			case Parameter::TypeData::NAME_LISTED:
				builder.create(downcast<NameListed>(param),*(uint32_t*)ptr_data);
				break;
			
			case Parameter::TypeData::FLAGGROUP:
				builder.create(downcast<FlagGroup>(param),*(uint32_t*)ptr_data);
				break;
			
			case Parameter::TypeData::STRING:
				builder.create(downcast<String>(param),*(Herbs::String*)ptr_data);
				break;
			
			case Parameter::TypeData::PATH:
				builder.create(downcast<Path>(param),*(Herbs::Path*)ptr_data);
				break;
			
			case Parameter::TypeData::DATETIME:
				builder.create(downcast<DateTime>(param),*(Herbs::Timestamp*)ptr_data);
				break;

			default:
			//	Unknown type
				throw Herbs::ExceptionMissing(___FILE__,__LINE__);
			}
		}
	
	void createDispatch(void* ptr_data
		,Config::InterfaceBuilder& builder
		,const Config::ParameterInfo& obj
		,size_t depth)
		{
		using namespace Config;
		
		switch(obj.type)
			{
			case ParameterInfo::Type::GROUP:
				builder.create(downcast<Group>(obj),depth);
				break;
					
			case ParameterInfo::Type::PARAM_INPUT:
			case ParameterInfo::Type::STATUS_INDICATOR:
				createDispatch(ptr_data,builder,downcast<Parameter>(obj));
				break;
			//	Unknown type
				throw Herbs::ExceptionMissing(___FILE__,__LINE__);
			}
		}
	}

void Config::interfaceCreate(const ParamCollector& params_in,InterfaceBuilder& builder)
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
		
	std::set<uint32_t> visited;
	Herbs::Stack<const ParameterInfo*> param_stack(16);
	params=params_in.paramInfoGet();
	while(*params!=nullptr)
		{
		auto param=*params;
		if(visited.find(param->id)==visited.end())
			{	
			if(param->group==param->id)
				{
			//	Self-refering group
				throw Herbs::ExceptionMissing(___FILE__,__LINE__);
				}
			param_stack.push(param);
		
		//	While parent not is not created, and we have not found the root node
			while(visited.find(param->group)==visited.end()
				&& param->group!=ParameterInfo::ID_INVALID)
				{
				auto ipm=pmap.find(param->group);
				if(ipm==pmap.end())
					{
				//	Unknown group id
					throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				param_stack.push(ipm->second);
				param=ipm->second;
				}
			
			while(param_stack.depth())
				{
				auto param_create=param_stack.pop();
				createDispatch(params_in.paramAddressGet(param_create->id)
					,builder,*param_create
					,0);
				visited.insert(param_create->id);
				}
				
			}
		++params;
		}
	}

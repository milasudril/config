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
#include <herbs/intformat/intformat.h>
#include <herbs/stringformat/stringformat.h>
#include <herbs/messageprinter/messageprinter.h>
#include <set>
#include <map>

namespace
	{
	class InconsistentType:public Herbs::Exception
		{
		public:
			InconsistentType(uint32_t s_exp,uint32_t s_got):
				expected(s_exp),got(s_got)
				{}

			void print(Herbs::MessagePrinter& printer) const
				{
				printer.print(Herbs::format(STR("Fel storlek på typ. "
					"Fick %0 (förväntat %1)"),
					{
					 Herbs::IntFormat<uint32_t>(got)
					,Herbs::IntFormat<uint32_t>(expected)
					}));
				}
				
		private:
			uint32_t expected;
			uint32_t got;
		};
		
	template<class T>
	const T& downcast(const Config::ParameterInfo& obj)
		{
		if(obj.size>=sizeof(T))
			{return (const T&)obj;}
		throw InconsistentType(sizeof(T),obj.size);
		}
	
	void createDispatch(char* ptr_data
		,Config::InterfaceBuilder& builder
		,const Config::Parameter& param
		,uint32_t group_current)
		{
		using namespace Config;
		ptr_data+=param.data_offset;
		
		switch(param.data_type)
			{
			case Parameter::TypeData::INT:
				switch(param.data_size)
					{
					case 4:
						builder.create(downcast<Value<int32_t> >(param)
							,group_current,*(int32_t*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Value<int64_t> >(param)
							,group_current,*(int64_t*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
			case Parameter::TypeData::INT_RANGE:
				switch(param.data_size)
					{
					case 4:
						builder.create(downcast<Range<int32_t> >(param) 
							,group_current,*(int32_t*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Range<int64_t> >(param)
							,group_current,*(int64_t*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
				
			case Parameter::TypeData::INT_UNSIGNED:
				switch(param.data_size)
					{
					case 4:
						builder.create(downcast<Value<uint32_t> >(param)
							,group_current,*(uint32_t*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Value<uint64_t> >(param)
							,group_current,*(uint64_t*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
			
			case Parameter::TypeData::INT_UNSIGNED_RANGE:
				switch(param.data_size)
					{
					case 4:
						builder.create(downcast<Range<uint32_t> >(param)
							,group_current,*(uint32_t*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Range<uint64_t> >(param)
							,group_current,*(uint64_t*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
			
			case Parameter::TypeData::FLOAT:
				switch(param.data_size)
					{
					case 4:
						builder.create(downcast<Value<float> >(param)
							,group_current,*(float*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Value<double> >(param)
							,group_current,*(double*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
			
			case Parameter::TypeData::FLOAT_RANGE:
				switch(param.data_size)
					{
					case 4:
						builder.create(downcast<Range<float> >(param)
							,group_current,*(float*)ptr_data);
						break;
					case 8:
						builder.create(downcast<Range<double> >(param)
							,group_current,*(double*)ptr_data);
						break;
					default:
					//	Bad data size for type
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
					}
				break;
				
			case Parameter::TypeData::NAME_LISTED:
				builder.create(downcast<NameListed>(param),group_current,*(uint32_t*)ptr_data);
				break;
			
			case Parameter::TypeData::FLAGGROUP:
				builder.create(downcast<FlagGroup>(param),group_current,*(uint32_t*)ptr_data);
				break;
			
			case Parameter::TypeData::STRING:
				builder.create(downcast<String>(param),group_current,*(Herbs::String*)ptr_data);
				break;
			
			case Parameter::TypeData::PATH:
				builder.create(downcast<Path>(param),group_current,*(Herbs::Path*)ptr_data);
				break;
			
			case Parameter::TypeData::DATETIME:
				builder.create(downcast<DateTime>(param),group_current,*(Herbs::Timestamp*)ptr_data);
				break;

			default:
			//	Unknown type
				throw Herbs::ExceptionMissing(___FILE__,__LINE__);
			}
		}
	

	
	}

void Config::interfaceCreate(const ParamCollector& params_in,InterfaceBuilder& builder)
	{
	auto si=params_in.setupinfoGet();
	size_t group_level=0;
	Herbs::Stack<std::pair<uint32_t,uint32_t> > group_ids(16);
	uint32_t group_current=ParameterInfo::ID_INVALID;
	auto param=si.param_info;
	auto ptr_data=si.blob_address;
	while(*param!=nullptr)
		{
		auto obj=*param;
		switch(obj->type)
			{
			case ParameterInfo::Type::GROUP:
				{
				const Group& group=downcast<Group>(*obj);
				if(group.level==group_level)
					{
					group_ids.push({group_current,group_level});
					builder.create(group,group_current);
					group_current=group.id;
					}
				else
					{
					if(group.level > group_level)
						{
						group_ids.push({group_current,group_level});
						builder.create(group,group_current);
						group_current=group.id;
						group_level=group.level;
						}
		
					if(group.level < group_level)
						{
						std::pair<uint32_t,uint32_t> node;
						while(group_ids.depth())
							{
							node=group_ids.pop();
							if(node.second<group.level)
								{break;}
							}
						group_current=node.first;
						group_ids.push(node);
						builder.create(group,group_current);
						group_current=group.id;
						group_level=group.level;
						}
					}
				}
				break;
					
			case ParameterInfo::Type::PARAM_INPUT:
			case ParameterInfo::Type::STATUS_INDICATOR:
				createDispatch((char*)ptr_data,builder,downcast<Parameter>(*obj),group_current);
				break;
			default:
			//	Unknown type
				throw Herbs::ExceptionMissing(___FILE__,__LINE__);
			}
		++param;
		}
	
	}

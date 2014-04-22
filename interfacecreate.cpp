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
		,const Config::Parameter& param)
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
				switch(param.data_size)
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
				switch(param.data_size)
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
				switch(param.data_size)
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
				switch(param.data_size)
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
				switch(param.data_size)
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
	
	void createDispatch(char* ptr_data
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
			default:
			//	Unknown type
				throw Herbs::ExceptionMissing(___FILE__,__LINE__);
			}
		}
	
	std::map<uint32_t,const Config::ParameterInfo*> mapIdCreate(const Config::ParameterInfo* const* params)
		{
		std::map<uint32_t, const Config::ParameterInfo*> idmap;
		while(*params!=nullptr)
			{
			auto ip=idmap.insert({(*params)->id,*params});
			if(!ip.second)
				{
			//	Duplicated ID
				throw Herbs::ExceptionMissing(___FILE__,__LINE__);
				}
			++params;
			}
		return idmap;
		}
	
	class ParamTraverseCallback
		{
		public:
			virtual void operator()(const Config::ParameterInfo& param,size_t level)=0;
		};
	
	void traverse(const Config::ParameterInfo* const* params
		,const std::map<uint32_t,const Config::ParameterInfo*>& idmap
		,ParamTraverseCallback& callback
		,size_t depth_max_hint)
		{
		std::set<uint32_t> visited;
	
		Herbs::Stack<std::pair<const Config::ParameterInfo*, size_t> > param_stack
			(depth_max_hint);
		size_t level_count=0;
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

				if(param->type==Config::ParameterInfo::Type::GROUP)
					{++level_count;}
				param_stack.push({param,level_count});
				
			//	While parent group is not created, and we have not found the root node,
			//	keep pushing the parent node on the stack.
				while(visited.find(param->group)==visited.end()
					&& param->group!=Config::ParameterInfo::ID_INVALID)
					{
					auto ipm=idmap.find(param->group);
					if(ipm==idmap.end())
						{
					//	Unknown group id
						throw Herbs::ExceptionMissing(___FILE__,__LINE__);
						}
	
					++level_count;
					param_stack.push({ipm->second,level_count});
					param=ipm->second;
					}
				
				while(param_stack.depth())
					{
					auto node=param_stack.pop();
					auto param_create=node.first;
					
					level_count=node.second;
					callback(*param_create,level_count);
					visited.insert(param_create->id);
					}					
				}
			++params;
			}
		}
		
	class DepthCount:public ParamTraverseCallback
		{
		public:
			DepthCount():level_max(0){}
			void operator()(const Config::ParameterInfo& param,size_t level)
				{
				if(level>level_max)
					{level_max=level;}
				}
			
			operator size_t() const	
				{return level_max;}
			
		private:
			size_t level_max;
		};
	
	class InterfaceBuild:public ParamTraverseCallback
		{
		public:
			InterfaceBuild(Config::InterfaceBuilder& builder,void* blob):
				m_builder(builder),m_blob_address((char*)blob)
				{}
				
			void operator()(const Config::ParameterInfo& param,size_t level)
				{
				createDispatch(m_blob_address,m_builder,param,level);
				}
	
		private:
			Config::InterfaceBuilder& m_builder;
			char* m_blob_address;
		};		
	
	}

void Config::interfaceCreate(const ParamCollector& params_in,InterfaceBuilder& builder)
	{
	auto si=params_in.setupinfoGet();
	
//	Create look-up for parameter ID:s
	auto idmap=mapIdCreate(si.param_info);	
	
	DepthCount depth_max;
	traverse(si.param_info,idmap,depth_max,16);
	
	InterfaceBuild thebuilder(builder,si.blob_address);
	traverse(si.param_info,idmap,thebuilder,depth_max);
	
	}

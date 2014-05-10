#ifdef __WAND__
target[name[paramset_impl.o] type[object]]
#endif

#include "paramset_impl.h"
#include "paraminfo.h"
#include "paramobj.h"

#include "param_group.h"
#include "param_valuemapped.h"
#include "param_intnamed.h"
#include "param_flagset.h"

#include <herbs/stack/stack.h>

namespace
	{
	using namespace Config;
	
	class ParamobjFactoryTable
		{
		public:
			ParamobjFactoryTable()
				{
				factories[(uint32_t)Paraminfo::Type::GROUP]=ParamGroup::create;
				factories[(uint32_t)Paraminfo::Type::INT32]=ParamValuemapped<int32_t>::create;
				factories[(uint32_t)Paraminfo::Type::INT64]=ParamValuemapped<int64_t>::create;
				factories[(uint32_t)Paraminfo::Type::UINT32]=ParamValuemapped<uint32_t>::create;
				factories[(uint32_t)Paraminfo::Type::UINT64]=ParamValuemapped<uint64_t>::create;
				factories[(uint32_t)Paraminfo::Type::INTNAMED32]=ParamIntnamed<uint32_t>::create;
				factories[(uint32_t)Paraminfo::Type::INTNAMED64]=ParamIntnamed<uint64_t>::create;
				factories[(uint32_t)Paraminfo::Type::FLOAT]=ParamValuemapped<float>::create;
				factories[(uint32_t)Paraminfo::Type::DOUBLE]=ParamValuemapped<double>::create;
				factories[(uint32_t)Paraminfo::Type::TIMESTAMP]=ParamValuemapped<Herbs::Timestamp>::create;
				factories[(uint32_t)Paraminfo::Type::FLAGSET32]=ParamFlagset<uint32_t>::create;
				factories[(uint32_t)Paraminfo::Type::FLAGSET64]=ParamFlagset<uint32_t>::create;
				factories[(uint32_t)Paraminfo::Type::STRING]=ParamValuemapped<Herbs::String>::create;
				factories[(uint32_t)Paraminfo::Type::PATH]=ParamValuemapped<Herbs::Path>::create;
				}
				
			Paramobj* create(const Paraminfo& info,Paramobj* group) const
				{return factories[(uint32_t)info.m_type](info,group);}
		
		private:
			Paramobj::Factory factories[(uint32_t)Paraminfo::Type::ID_MAX];
		};
		
	
	const ParamobjFactoryTable factory_table;
	}

Config::ParamsetImpl::ParamsetImpl(const Paraminfo* const* params)
	{
	Herbs::Stack<ParamGroup*> nodes;
	ParamGroupInfo root={STR("Parametrar"),0,0};

	ParamGroup* group_current=new ParamGroup(root,nullptr);
	nodes.push(group_current);
	m_params.append(group_current);
	
	while(*params!=nullptr)
		{
		auto objinfo=*params;
		switch(objinfo->m_type)
			{
			case Paraminfo::Type::GROUP:
				{
				const ParamGroupInfo& g=(const ParamGroupInfo&)(*objinfo);
				const auto level_current=group_current->levelGet();
				if(g.m_level>level_current)
					{
					nodes.push(group_current);
					group_current=new ParamGroup(*objinfo,group_current);
					m_params.append(group_current);
					}			
				else
					{
					while(nodes.depth())
						{
						group_current=nodes.pop();
						if(group_current->levelGet() < g.m_level)
							{break;}
						}
					group_current=new ParamGroup(*objinfo,group_current);
					m_params.append(group_current);
					}
				}
				break;
				
			default:
				m_params.append(factory_table.create(*objinfo,group_current));
			}
		++params;
		}
	}

void Config::ParamsetImpl::uiCreate(UIProvider& ui) const
	{
	auto param=m_params.begin();
	while(param!=m_params.end())
		{
		(*param)->controlCreate(ui);
		++param;
		}
	}

Config::ParamsetImpl::~ParamsetImpl()
	{
	auto param=m_params.begin();
	while(param!=m_params.end())
		{
		delete *param;
		++param;
		}
	}
	

#ifdef __WAND__
target[name[paramset_impl.o] type[object]]
#endif

#include "paramset_impl.h"
#include "paraminfo.h"
#include "paramobj.h"

#include "param_group.h"
#include "param_numeric.h"

namespace
	{
	using namespace Config;
	
	class ParamobjFactoryTable
		{
		public:
			ParamobjFactoryTable()
				{
				factories[(uint32_t)Paraminfo::Type::GROUP]=ParamGroup::create;
				factories[(uint32_t)Paraminfo::Type::INT32]=ParamNumeric<int32_t>::create;
				factories[(uint32_t)Paraminfo::Type::INT64]=ParamNumeric<int64_t>::create;
				factories[(uint32_t)Paraminfo::Type::UINT32]=ParamNumeric<uint32_t>::create;
				factories[(uint32_t)Paraminfo::Type::UINT32]=ParamNumeric<uint64_t>::create;
				factories[(uint32_t)Paraminfo::Type::FLOAT]=ParamNumeric<float>::create;
				factories[(uint32_t)Paraminfo::Type::FLOAT]=ParamNumeric<double>::create;
				}
		
			Paramobj::Factory operator[](Paraminfo::Type type) const
				{return factories[(uint32_t)type];}
		
		private:
			Paramobj::Factory factories[(uint32_t)Paraminfo::Type::ID_MAX];
		};
		
	
	const ParamobjFactoryTable factory_table;
	}

Config::ParamsetImpl::ParamsetImpl(const Paraminfo* const* params)
	{
	while(*params!=nullptr)
		{
		
		++params;
		}
	}


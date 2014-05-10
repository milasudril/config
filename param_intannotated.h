#ifdef __WAND__
target[name[param_intannotated.h] type[include]]
#endif

#ifndef CONFIG_PARAM_INTANNOTATED_H
#define CONFIG_PARAM_INTANNOTATED_H

#include "param_value.h"
#include "param_intannotated_info.h"
#include "uiprovider.h"

#include <herbs/string/string.h>

namespace Config
	{
	template<class T>
	class ParamIntannotated:public ParamValue<T>
		{
		public:
			ParamIntannotated(const Paraminfo& info,ParamGroup* group):
				ParamValue<T>(info,group)
				{
				auto labels=((const ParamIntannotatedInfo<T>&)info).m_labels;
				while(*labels!=nullptr)
					{
					m_labels.append(Herbs::String(*labels));
					++labels;
					}
				}
			
			const Herbs::Array<Herbs::String>& labelsGet() const
				{return m_labels;}

		private:
			Herbs::Array<Herbs::String> m_labels;
		};
	}
	
#endif

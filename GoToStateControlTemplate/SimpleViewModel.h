#pragma once

#include "SimpleViewModel.g.h"

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Data;

namespace winrt::GoToStateControlTemplate::implementation
{
	struct SimpleViewModel : SimpleViewModelT<SimpleViewModel>
	{
		SimpleViewModel() = default;

		winrt::hstring State();
		void State(winrt::hstring const& value);
		winrt::hstring FeedbackState();
		void FeedbackState(winrt::hstring const& value);
		winrt::event_token PropertyChanged(PropertyChangedEventHandler const& value);
		void PropertyChanged(winrt::event_token const& token);

	private:
		winrt::hstring m_feedbackState = winrt::hstring(L"Normal");
		winrt::hstring m_state = winrt::hstring(L"SingleItem");
		winrt::event<PropertyChangedEventHandler> m_propertyChanged;
	};
}

namespace winrt::GoToStateControlTemplate::factory_implementation
{
	struct SimpleViewModel : SimpleViewModelT<SimpleViewModel, implementation::SimpleViewModel>
	{
	};
}

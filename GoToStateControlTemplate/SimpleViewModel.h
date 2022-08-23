#pragma once

#include "SimpleViewModel.g.h"

namespace winrt::GoToStateControlTemplate::implementation
{
    struct SimpleViewModel : SimpleViewModelT<SimpleViewModel>
    {
        SimpleViewModel() = default;

        winrt::hstring State();
        void State(winrt::hstring const& value);
        winrt::hstring FeedbackState();
        void FeedbackState(winrt::hstring const& value);
        winrt::event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value);
        void PropertyChanged(winrt::event_token const& token);

    private:
        winrt::hstring m_feedbackState;
        winrt::hstring m_state; 
        winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

namespace winrt::GoToStateControlTemplate::factory_implementation
{
    struct SimpleViewModel : SimpleViewModelT<SimpleViewModel, implementation::SimpleViewModel>
    {
    };
}

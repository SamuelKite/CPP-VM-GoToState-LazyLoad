#include "pch.h"
#include "SimpleViewModel.h"
#if __has_include("SimpleViewModel.g.cpp")
#include "SimpleViewModel.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Data;

namespace winrt::GoToStateControlTemplate::implementation
{
    winrt::hstring SimpleViewModel::FeedbackState()
    {
        return m_feedbackState;
    }

    void SimpleViewModel::FeedbackState(winrt::hstring const& value)
    {
        if (m_state != value)
        {
            m_feedbackState = value;
            m_propertyChanged(*this, PropertyChangedEventArgs{ L"FeedbackState" });
        }
    }

    winrt::hstring SimpleViewModel::State()
    {
        return m_state;
    }

    void SimpleViewModel::State(winrt::hstring const& value)
    {
        if (m_state != value)
        {
            m_state = value;
            m_propertyChanged(*this, PropertyChangedEventArgs{ L"State" });
        }
    }

    winrt::event_token SimpleViewModel::PropertyChanged(PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }

    void SimpleViewModel::PropertyChanged(winrt::event_token const& token)
    {
        m_propertyChanged.remove(token);
    }
}

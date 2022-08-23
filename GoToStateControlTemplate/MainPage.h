#pragma once

#include "MainPage.g.h"
#include "SimpleViewModel.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::GoToStateControlTemplate::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        GoToStateControlTemplate::SimpleViewModel VM();

    private:
        GoToStateControlTemplate::SimpleViewModel m_simpleVM{ nullptr };
        winrt::event_token m_simpleVMPropChangedEventToken;
        void HandlePropertyChanged(winrt::Windows::Foundation::IInspectable const& sender, ::winrt::Windows::UI::Xaml::Data::PropertyChangedEventArgs const& args);
        void GoToStateWithTagVM(winrt::Windows::Foundation::IInspectable const& sender, winrt::hstring const& state);
   
    public:
        void GoToFourItemButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void GoToSpecialItemButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void GoToSingleItemButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        
        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::GoToStateControlTemplate::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}

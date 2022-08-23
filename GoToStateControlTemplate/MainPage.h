#pragma once

#include "MainPage.g.h"
#include "SimpleViewModel.h"

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::Foundation;

namespace winrt::GoToStateControlTemplate::implementation
{
	struct MainPage : MainPageT<MainPage>
	{
		MainPage();

		GoToStateControlTemplate::SimpleViewModel VM();
		void GoToFourItemButton_Click(IInspectable const& sender, RoutedEventArgs const& e);
		void GoToSpecialItemButton_Click(IInspectable const& sender, RoutedEventArgs const& e);
		void GoToSingleItemButton_Click(IInspectable const& sender, RoutedEventArgs const& e);

		void Page_Loaded(IInspectable const& sender, RoutedEventArgs const& e);
		void FeedbackResponse_Click(IInspectable const& sender, RoutedEventArgs const& e);
		void FeedbackButton_Click(IInspectable const& sender, RoutedEventArgs const& e);

	private:
		GoToStateControlTemplate::SimpleViewModel m_simpleVM{ nullptr };
		winrt::event_token m_simpleVMPropChangedEventToken;
		void HandlePropertyChanged(IInspectable const& sender, PropertyChangedEventArgs const& args);
		void GoToStateForRecognizedStates(std::wstring const& propName);
		void GoToStateWithTagVM(winrt::hstring const& state);
		void GoToFeedbackStateWithTagVM(winrt::hstring const& state);
	};
}

namespace winrt::GoToStateControlTemplate::factory_implementation
{
	struct MainPage : MainPageT<MainPage, implementation::MainPage>
	{
	};
}

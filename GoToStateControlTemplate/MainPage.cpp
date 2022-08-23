#include "pch.h"
#include <unordered_set>
#include "MainPage.h"
#include "MainPage.g.cpp"
#include "MainPage.xaml.g.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::GoToStateControlTemplate::implementation
{
	MainPage::MainPage()
	{
		// Xaml objects should not call InitializeComponent during construction.
		// See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
		m_simpleVM = winrt::make<implementation::SimpleViewModel>();
		m_simpleVMPropChangedEventToken = m_simpleVM.PropertyChanged({ this, &MainPage::HandlePropertyChanged });
	}

	void MainPage::Page_Loaded(IInspectable const& sender, RoutedEventArgs const& e)
	{

	}

	GoToStateControlTemplate::SimpleViewModel MainPage::VM() {
		return m_simpleVM;
	}

	std::unordered_set<std::wstring> m_states{ L"SingleItem", L"FourItem", L"SpecialItem" };
	std::unordered_set<std::wstring> m_feedbackStates{ L"Normal", L"GatherFeedback" };

	void MainPage::HandlePropertyChanged(IInspectable const& /* sender */, PropertyChangedEventArgs const& args) {

		if (
			(args.PropertyName() == L"State" && m_states.find(std::wstring(VM().State())) != m_states.end())
			||
			(args.PropertyName() == L"FeedbackState" && m_feedbackStates.find(std::wstring(VM().State())) != m_states.end())
			)
		{
			VisualStateManager::GoToState(this->try_as<Controls::Control>(), VM().State(), true);
		}
	}


	void MainPage::GoToFourItemButton_Click(IInspectable const& sender, RoutedEventArgs const& /*e*/)
	{
		GoToStateWithTagVM(sender, L"FourItem");
	}

	void MainPage::GoToSpecialItemButton_Click(IInspectable const& sender, RoutedEventArgs const& /*e*/)
	{
		GoToStateWithTagVM(sender, L"SpecialItem");
	}

	void MainPage::GoToSingleItemButton_Click(IInspectable const& sender, RoutedEventArgs const& /*e*/)
	{
		GoToStateWithTagVM(sender, L"SingleItem");
	}

	void MainPage::GoToStateWithTagVM(IInspectable const& sender, winrt::hstring const& state)
	{
		if (auto muhControl = sender.try_as<Controls::Control>())
		{
			if (auto muhVM = muhControl.Tag().try_as<GoToStateControlTemplate::SimpleViewModel>())
			{
				muhVM.State(state);
			}
		}
	}
}





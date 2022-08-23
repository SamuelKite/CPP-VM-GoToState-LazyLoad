#include "pch.h"
#include <unordered_set>
#include "MainPage.h"
#include "MainPage.g.cpp"
#include "MainPage.xaml.g.h"

using namespace winrt;
using namespace Windows::Foundation;
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

	void MainPage::Page_Loaded(IInspectable const& /*sender*/, RoutedEventArgs const& /*e*/)
	{
		if (m_simpleVM != nullptr)
		{
			GoToStateForRecognizedStates(std::wstring(m_simpleVM.FeedbackState()));
			GoToStateForRecognizedStates(std::wstring(m_simpleVM.State()));
		}
	}

	GoToStateControlTemplate::SimpleViewModel MainPage::VM() {
		return m_simpleVM;
	}

	std::unordered_set<std::wstring> m_states{ L"SingleItem", L"FourItem", L"SpecialItem" };
	std::unordered_set<std::wstring> m_feedbackStates{ L"Normal", L"GatherFeedback" };

	void MainPage::HandlePropertyChanged(IInspectable const& /* sender */, PropertyChangedEventArgs const& args) {

		auto wstringPropName = std::wstring(args.PropertyName());
		GoToStateForRecognizedStates(wstringPropName);
	}

	void MainPage::GoToStateForRecognizedStates(std::wstring const& propName) {
		if (propName == L"State" && m_states.find(std::wstring(VM().State())) != m_states.end())
		{
			VisualStateManager::GoToState(this->try_as<Controls::Control>(), VM().State(), true);
		}
		else if (propName == L"FeedbackState" && m_feedbackStates.find(std::wstring(VM().FeedbackState())) != m_feedbackStates.end())
		{
			VisualStateManager::GoToState(this->try_as<Controls::Control>(), VM().FeedbackState(), true);
		}
	}

	void MainPage::GoToFourItemButton_Click(IInspectable const& /*sender*/, RoutedEventArgs const& /*e*/)
	{
		GoToStateWithTagVM(L"FourItem");
	}

	void MainPage::GoToSpecialItemButton_Click(IInspectable const& /*sender*/, RoutedEventArgs const& /*e*/)
	{
		GoToStateWithTagVM(L"SpecialItem");
	}

	void MainPage::GoToSingleItemButton_Click(IInspectable const& /*sender*/, RoutedEventArgs const& /*e*/)
	{
		GoToStateWithTagVM(L"SingleItem");
	}

	void MainPage::GoToStateWithTagVM(winrt::hstring const& state)
	{
		if (m_simpleVM != nullptr && m_states.find(std::wstring(state)) != m_states.end())
		{
			m_simpleVM.State(state);
		}
	}

	void MainPage::FeedbackResponse_Click(IInspectable const& /*sender*/, RoutedEventArgs const& /*e*/)
	{
		GoToFeedbackStateWithTagVM(L"Normal");
	}

	void MainPage::FeedbackButton_Click(IInspectable const& /*sender*/, RoutedEventArgs const& /*e*/)
	{
		GoToFeedbackStateWithTagVM(L"GatherFeedback");
	}

	void MainPage::GoToFeedbackStateWithTagVM(winrt::hstring const& state)
	{
		if (m_simpleVM != nullptr && m_feedbackStates.find(std::wstring(state)) != m_feedbackStates.end())
		{
			m_simpleVM.FeedbackState(state);
		}
	}
}


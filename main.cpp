#include "GeneratedAuto.h"
#include "UserWindow.h"
#include <QtWidgets/QApplication>
#include "IssueRepository.h"
#include "Controller.h"
#include <assert.h>

int main(int argc, char *argv[])
{
	IssueRepository issueRepository;
	Controller controller{ issueRepository };

	QApplication a(argc, argv);

	std::vector<UserWindow*> windows;

	for (auto user : controller.getUsers()) {
		UserWindow* userWindow = new UserWindow{ controller,user.getName(),user.getType() };
		windows.push_back(userWindow);
		controller.registerObserver(userWindow);
	}

	for (auto window : windows) {
		window->show();
	}

	return a.exec();
}
